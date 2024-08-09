#include "cmdtestfunction.h"
#include "cmdtestutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void Test_Label_SampleTicket_55x30_1(void * h)
{
    if (!Test_Pos_CheckPrinterStatus(h))
        return;

    int nPageWidth = 48 * 8;
    int nPageHeight = 25 * 8;

    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_GBK);

    CP_Label_PageBegin(h, 0, 0, nPageWidth, nPageHeight, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, nPageWidth, nPageHeight, 1, CP_Label_Color_Black);
    CP_Label_DrawTextInGBK(h, 10, 10, 24, 0, L"型号：P58A+");
    CP_Label_DrawTextInGBK(h, 10, 40, 24, 0, L"MFG ：0000");
    CP_Label_DrawBarcode(h, 10, 70, CP_Label_BarcodeType_CODE128, CP_Label_BarcodeTextPrintPosition_BelowBarcode, 60, 2, CP_Label_Rotation_0, "No.123456");
    CP_Label_DrawQRCode(h, 240, 10, 4, CP_QRCodeECC_L, 4, CP_Label_Rotation_0, "No.123456");
    CP_Label_PagePrint(h, 1);

    Test_Pos_QueryPrintResult(h);
}

void Test_Port_Write(void * h)
{
    // send this cmd to print a selftest page
    unsigned char cmd[] = { 0x12, 0x54 };
    if (CP_Port_Write(h, cmd, sizeof(cmd), 1000) != (int)sizeof(cmd))
        ShowMessage("Write failed");
}

void Test_Port_Read(void * h)
{
    // send this cmd to query printer status
    unsigned char cmd[] = { 0x10, 0x04, 0x01 };
    CP_Port_SkipAvailable(h);
    if (CP_Port_Write(h, cmd, sizeof(cmd), 1000) == (int)sizeof(cmd)) {
        unsigned char status;
        if (CP_Port_Read(h, &status, 1, 2000) == 1) {
            char msg[100];
            sprintf(msg, "Status: %02X", status);
            ShowMessage(msg);
        } else {
            ShowMessage("Read failed");
        }
    } else {
        ShowMessage("Write failed");
    }
}

void Test_Port_ReadUntilByte(void * h)
{
    // send this cmd to query printer label voltage status
    unsigned char cmd[] = { 0x1F, 0x28, 0x4C, 0x02, 0x00, 0x72, 0x41 };
    CP_Port_SkipAvailable(h);
    if (CP_Port_Write(h, cmd, sizeof(cmd), 1000) == (int)sizeof(cmd)) {
        char buffer[0x100];
        if (CP_Port_ReadUntilByte(h, (unsigned char *)buffer, (unsigned int)sizeof(buffer), 2000, 0x00) > 0) {
            ShowMessage(buffer);
        } else {
            ShowMessage("Read failed");
        }
    } else {
        ShowMessage("Write failed");
    }
}

void Test_Port_Available(void * h)
{
    int available = CP_Port_Available(h);
    char msg[100];
    sprintf(msg, "available: %d", available);
    ShowMessage(msg);
}

void Test_Port_SkipAvailable(void * h)
{
    CP_Port_SkipAvailable(h);
}

void Test_Port_IsConnectionValid(void * h)
{
    bool valid = CP_Port_IsConnectionValid(h);
    char msg[100];
    sprintf(msg, "valid: %d", valid);
    ShowMessage(msg);
}

void Test_Printer_GetPrinterInfo(void * h)
{
    long long printer_error_status;
    long long printer_info_status;
    unsigned int printer_received_byte_count;
    unsigned int printer_printed_page_id;
    long long timestamp_ms_printer_status;
    long long timestamp_ms_printer_received;
    long long timestamp_ms_printer_printed;
    if (CP_Printer_GetPrinterStatusInfo(h, &printer_error_status, &printer_info_status, &timestamp_ms_printer_status) &&
            CP_Printer_GetPrinterReceivedInfo(h, &printer_received_byte_count, &timestamp_ms_printer_received) &&
            CP_Printer_GetPrinterPrintedInfo(h, &printer_printed_page_id, &timestamp_ms_printer_printed)) {
        char msg[1000] = { 0, };

        // printer_error_status
        {
            sprintf(&msg[strlen(msg)], " Printer Error Status: 0x%llX", printer_error_status);

            if (printer_error_status) {
                if (CP_PRINTERSTATUS_ERROR_CUTTER(printer_error_status))
                    sprintf(&msg[strlen(msg)], "%s", "[Cutter Error]");
                if (CP_PRINTERSTATUS_ERROR_FLASH(printer_error_status))
                    sprintf(&msg[strlen(msg)], "%s", "[Flash Error]");
                if (CP_PRINTERSTATUS_ERROR_NOPAPER(printer_error_status))
                    sprintf(&msg[strlen(msg)], "%s", "[No Paper]");
                if (CP_PRINTERSTATUS_ERROR_VOLTAGE(printer_error_status))
                    sprintf(&msg[strlen(msg)], "%s", "[Voltage Error]");
                if (CP_PRINTERSTATUS_ERROR_MARKER(printer_error_status))
                    sprintf(&msg[strlen(msg)], "%s", "[Marker Error]");
                if (CP_PRINTERSTATUS_ERROR_ENGINE(printer_error_status))
                    sprintf(&msg[strlen(msg)], "%s", "[Engine Error]");
                if (CP_PRINTERSTATUS_ERROR_OVERHEAT(printer_error_status))
                    sprintf(&msg[strlen(msg)], "%s", "[Overheat]");
                if (CP_PRINTERSTATUS_ERROR_COVERUP(printer_error_status))
                    sprintf(&msg[strlen(msg)], "%s", "[Coverup]");
                if (CP_PRINTERSTATUS_ERROR_MOTOR(printer_error_status))
                    sprintf(&msg[strlen(msg)], "%s", "[Motor Error]");
            }

            sprintf(&msg[strlen(msg)], "%s", "\r\n");
        }

        // printer_info_status
        {
            sprintf(&msg[strlen(msg)], " Printer Info Status: 0x%llX", printer_info_status);

            if (CP_PRINTERSTATUS_INFO_LABELMODE(printer_info_status))
                sprintf(&msg[strlen(msg)], "%s", "[Label Mode]");
            if (CP_PRINTERSTATUS_INFO_LABELPAPER(printer_info_status))
                sprintf(&msg[strlen(msg)], "%s", "[Label Paper]");
            if (CP_PRINTERSTATUS_INFO_PAPERNOFETCH(printer_info_status))
                sprintf(&msg[strlen(msg)], "%s", "[Paper Not Fetch]");

            sprintf(&msg[strlen(msg)], "%s", "\r\n");
        }

        sprintf(&msg[strlen(msg)], " Printer Received Byte Count: %u\r\n", printer_received_byte_count);
        sprintf(&msg[strlen(msg)], " Printer Printed Page ID: %u\r\n", printer_printed_page_id);
        ShowMessage(msg);
    }
}

void Test_Printer_ClearPrinterBuffer(void * h)
{
    CP_Printer_ClearPrinterBuffer(h);
}

bool Test_Pos_CheckPrinterStatus(void * h)
{
    if (!CP_Port_IsConnectionValid(h)) {
        ShowMessage("Connection Invalid");
        return false;
    }

    long long printer_error_status;
    long long printer_info_status;
    long long timestamp_ms_printer_status;
    if (!CP_Printer_GetPrinterStatusInfo(h, &printer_error_status, &printer_info_status, &timestamp_ms_printer_status)) {
        ShowMessage("Unable Get Printer Status Info");
        return false;
    }

    if (printer_error_status) {
        ShowMessage("Printer Status Error");
        Test_Printer_GetPrinterInfo(h);
        return false;
    }

    if (printer_info_status) {
        char msg[1000] = { 0, };
        if (CP_PRINTERSTATUS_INFO_PAPERNOFETCH(printer_info_status))
            sprintf(&msg[strlen(msg)], "%s", "[Paper Not Fetch]");
        if (strlen(msg)) {
            // warning
            ShowMessage(msg);
        }
    }

    return true;
}

void Test_Pos_QueryPrintResult(void * h)
{
    static unsigned int nPageID = 1;
    bool result = CP_Pos_QueryPrintResult(h, nPageID++, 30000);
    if (!result) {
        ShowMessage("Print failed");
        Test_Printer_GetPrinterInfo(h);
    } else {
        ShowMessage("Print Success");
    }
}

void Test_Pos_KickOutDrawer(void * h)
{
    CP_Pos_KickOutDrawer(h, 0, 100, 100);
    bool result = CP_Pos_KickOutDrawer(h, 1, 100, 100);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_Beep(void * h)
{
    bool result = CP_Pos_Beep(h, 3, 300);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_PrintSelfTestPage(void * h)
{
    bool result = CP_Pos_PrintSelfTestPage(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_ResetPrinter(void * h)
{
    bool result = CP_Pos_ResetPrinter(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_SetPrintSpeed_20(void * h)
{
    CP_Pos_SetPrintSpeed(h, 20);
    bool result = CP_Pos_PrintSelfTestPage(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_SetPrintSpeed_50(void * h)
{
    CP_Pos_SetPrintSpeed(h, 50);
    bool result = CP_Pos_PrintSelfTestPage(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_SetPrintSpeed_100(void * h)
{
    CP_Pos_SetPrintSpeed(h, 100);
    bool result = CP_Pos_PrintSelfTestPage(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_SetPrintDensity_0(void * h)
{
    CP_Pos_SetPrintDensity(h, 0);
    bool result = CP_Pos_PrintSelfTestPage(h);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Pos_SetPrintDensity_7(void * h)
{
    CP_Pos_SetPrintDensity(h, 7);
    bool result = CP_Pos_PrintSelfTestPage(h);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Pos_SetPrintDensity_15(void * h)
{
    CP_Pos_SetPrintDensity(h, 15);
    bool result = CP_Pos_PrintSelfTestPage(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Label_EnableLabelMode(void * h)
{
    bool result = CP_Label_EnableLabelMode(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Label_DisableLabelMode(void * h)
{
    bool result = CP_Label_DisableLabelMode(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Label_CalibrateLabel(void * h)
{
    bool result = CP_Label_CalibrateLabel(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Label_FeedLabel(void * h)
{
    bool result = CP_Label_FeedLabel(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Label_PageBegin_PagePrint(void * h)
{
    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);
    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Label_DrawText(void * h)
{
    // 0x24 is $
    char str[20];
    memset(str, 0x24, sizeof(str));
    str[sizeof(str)-1] = 0;

    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);
    CP_Label_DrawText(h, 10, 10, 24, 0, str);
    CP_Label_DrawText(h, 10, 40, 24,
                         CP_LABEL_TEXT_STYLE_UNDERLINE | CP_LABEL_TEXT_STYLE_BOLD,
                         str);
    CP_Label_DrawText(h, 10, 70, 24,
                         CP_LABEL_TEXT_STYLE_WIDTH_ENLARGEMENT(2) | CP_LABEL_TEXT_STYLE_HEIGHT_ENLARGEMENT(2),
                         str);
    CP_Label_DrawText(h, 30, 130, 24, CP_LABEL_TEXT_STYLE_ROTATION_90,
                         str);
    CP_Label_DrawText(h, 40, 200, 26, 0, str);
    CP_Label_DrawText(h, 40, 240, 28, 0, str);
    CP_Label_DrawText(h, 40, 280, 16, 0, str);
    CP_Label_DrawText(h, 40, 320, 21, 0, str);
    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Label_DrawTextInUTF8(void * h)
{
    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_UTF8);
    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);
    CP_Label_DrawTextInUTF8(h, 10, 10, 24, 0, L"1234567890");
    CP_Label_DrawTextInUTF8(h, 10, 40, 24, 0, L"abcdefghijklmnopqrstuvwxyz");
    CP_Label_DrawTextInUTF8(h, 10, 70, 24, 0, L"ΑΒΓΔΕΖΗΘΙΚ∧ΜΝΞΟ∏Ρ∑ΤΥΦΧΨΩ");
    CP_Label_DrawTextInUTF8(h, 10, 110, 24, 0, L"αβγδεζηθικλμνξοπρστυφχψω");
    CP_Label_DrawTextInUTF8(h, 10, 140, 24, 0, L"你好，欢迎使用！");
    CP_Label_DrawTextInUTF8(h, 10, 170, 24, 0, L"你號，歡迎使用！");
    CP_Label_DrawTextInUTF8(h, 10, 210, 24, 0, L"梦を见る事が出来なければ");
    CP_Label_DrawTextInUTF8(h, 10, 240, 24, 0, L"왕관을 쓰려는자");
    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Label_DrawTextInGBK(void * h)
{
    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_GBK);
    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);
    CP_Label_DrawTextInGBK(h, 10, 10, 24, 0, L"1234567890");
    CP_Label_DrawTextInGBK(h, 10, 40, 24, 0, L"abcdefghijklmnopqrstuvwxyz");
    CP_Label_DrawTextInGBK(h, 10, 70, 24, 0, L"ΑΒΓΔΕΖΗΘΙΚ∧ΜΝΞΟ∏Ρ∑ΤΥΦΧΨΩ");
    CP_Label_DrawTextInGBK(h, 10, 110, 24, 0, L"αβγδεζηθικλμνξοπρστυφχψω");
    CP_Label_DrawTextInGBK(h, 10, 140, 24, 0, L"你好，欢迎使用！");
    CP_Label_DrawTextInGBK(h, 10, 170, 24, 0, L"你號，歡迎使用！");
    CP_Label_DrawTextInGBK(h, 10, 210, 24, 0, L"梦を见る事が出来なければ");
    CP_Label_DrawTextInGBK(h, 10, 240, 24, 0, L"왕관을 쓰려는자");
    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Label_DrawTextInBIG5(void * h)
{
    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_BIG5);
    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);
    CP_Label_DrawTextInBIG5(h, 10, 10, 24, 0, L"你號，歡迎使用！");
    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Label_DrawTextInShiftJIS(void * h)
{
    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_ShiftJIS);
    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);
    CP_Label_DrawTextInShiftJIS(h, 10, 10, 24, 0, L"梦を见る事が出来なければ");
    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Label_DrawTextInEUCKR(void * h)
{
    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_EUCKR);
    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);
    CP_Label_DrawTextInEUCKR(h, 10, 10, 24, 0, L"왕관을 쓰려는자");
    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Label_DrawTextInBytes(void * h)
{
    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_GBK);
    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);
    CP_Label_DrawTextInBytes(h, 10, 10, 24, 0, "1234567890", 3);
    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Label_DrawBarcode_UPCA(void * h)
{
    const char *str = "01234567890";

    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);

    CP_Label_DrawBarcode(h, 10, 10, CP_Label_BarcodeType_UPCA, CP_Label_BarcodeTextPrintPosition_BelowBarcode, 60, 2, CP_Label_Rotation_0, str);

    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Label_DrawBarcode_UPCE(void * h)
{
    const char *str = "123456";

    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);

    CP_Label_DrawBarcode(h, 10, 10, CP_Label_BarcodeType_UPCE, CP_Label_BarcodeTextPrintPosition_BelowBarcode, 60, 2, CP_Label_Rotation_0, str);

    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Label_DrawBarcode_EAN13(void * h)
{
    const char *str = "123456789012";

    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);

    CP_Label_DrawBarcode(h, 10, 10, CP_Label_BarcodeType_EAN13, CP_Label_BarcodeTextPrintPosition_BelowBarcode, 60, 2, CP_Label_Rotation_0, str);

    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Label_DrawBarcode_EAN8(void * h)
{
    const char *str = "1234567";

    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);

    CP_Label_DrawBarcode(h, 10, 10, CP_Label_BarcodeType_EAN8, CP_Label_BarcodeTextPrintPosition_BelowBarcode, 60, 2, CP_Label_Rotation_0, str);

    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Label_DrawBarcode_CODE39(void * h)
{
    const char *str = "123456";

    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);

    CP_Label_DrawBarcode(h, 10, 10, CP_Label_BarcodeType_CODE39, CP_Label_BarcodeTextPrintPosition_BelowBarcode, 60, 2, CP_Label_Rotation_0, str);

    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Label_DrawBarcode_ITF(void * h)
{
    const char *str = "123456";

    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);

    CP_Label_DrawBarcode(h, 10, 10, CP_Label_BarcodeType_ITF, CP_Label_BarcodeTextPrintPosition_BelowBarcode, 60, 2, CP_Label_Rotation_0, str);

    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Label_DrawBarcode_CODEBAR(void * h)
{
    const char *str = "A123456A";

    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);

    CP_Label_DrawBarcode(h, 10, 10, CP_Label_BarcodeType_CODEBAR, CP_Label_BarcodeTextPrintPosition_BelowBarcode, 60, 2, CP_Label_Rotation_0, str);

    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Label_DrawBarcode_CODE93(void * h)
{
    const char *str = "123456";

    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);

    CP_Label_DrawBarcode(h, 10, 10, CP_Label_BarcodeType_CODE93, CP_Label_BarcodeTextPrintPosition_BelowBarcode, 60, 2, CP_Label_Rotation_0, str);

    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Label_DrawBarcode_CODE128(void * h)
{
    const char *str = "No.123456";

    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);

    CP_Label_DrawBarcode(h, 10, 10, CP_Label_BarcodeType_CODE128, CP_Label_BarcodeTextPrintPosition_BelowBarcode, 60, 2, CP_Label_Rotation_0, str);

    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Label_DrawQRCode(void * h)
{
    const char *code = "Hello 你好";

    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);
    CP_Label_DrawQRCode(h, 10, 10, 0, CP_QRCodeECC_L, 8, CP_Label_Rotation_0, code);
    CP_Label_PagePrint(h, 1);

    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);
    CP_Label_DrawQRCode(h, 10, 10, 0, CP_QRCodeECC_L, 8, CP_Label_Rotation_0, code);
    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Label_DrawQRCodeInUTF8(void * h)
{
    const wchar_t *code = L"Hello 你好";
    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);
    CP_Label_DrawQRCodeInUTF8(h, 10, 10, 0, CP_QRCodeECC_L, 8, CP_Label_Rotation_0, code);
    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Label_DrawQRCodeInBytes(void * h)
{
    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);
    CP_Label_DrawQRCodeInBytes(h, 10, 10, 0, CP_QRCodeECC_L, 8, CP_Label_Rotation_0, "123456", 3);
    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Label_DrawPDF417Code(void * h)
{
    const char *code = "Hello 你好";

    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);

    CP_Label_DrawPDF417Code(h, 10, 10, 3, 3, 0, 3, CP_Label_Rotation_0, code);

    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Label_DrawLine(void * h)
{
    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);
    CP_Label_DrawLine(h, 20, 20, 100, 300, 1, CP_Label_Color_Black);
    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Label_DrawRect(void * h)
{
    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);
    CP_Label_DrawRect(h, 20, 20, 200, 10, CP_Label_Color_Black);
    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Label_DrawBox(void * h)
{
    CP_Label_PageBegin(h, 0, 0, 384, 400, CP_Label_Rotation_0);
    CP_Label_DrawBox(h, 0, 0, 384, 400, 1, CP_Label_Color_Black);
    CP_Label_DrawBox(h, 30, 30, 300, 200, 1, CP_Label_Color_Black);
    bool result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Label_DrawImageFromFile(void * h)
{
    const char *str = "blackwhite_1.bmp";

    CP_Label_PageBegin(h, 0, 0, 384, 600, CP_Label_Rotation_0);
    CP_Label_DrawImageFromFile(h, 0, 0, 0, 0, str, CP_ImageBinarizationMethod_Thresholding);
    int result = CP_Label_PagePrint(h, 1);
    if (!result)
        ShowMessage("Write failed");
}
