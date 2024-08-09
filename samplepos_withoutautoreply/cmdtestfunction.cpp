#include "cmdtestfunction.h"
#include "cmdtestutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void Test_Pos_SampleTicket_58MM_1(void * h)
{
    int paperWidth = 384;

    CP_Pos_ResetPrinter(h);
    CP_Pos_PrintText(h, "123xxstreet,xxxcity,xxxxstate\r\n");
    CP_Pos_SetAlignment(h, CP_Pos_Alignment_Right);
    CP_Pos_PrintText(h, "TEL 9999-99-9999  C#2\r\n");
    CP_Pos_SetAlignment(h, CP_Pos_Alignment_HCenter);
    CP_Pos_PrintText(h, "2018-06-19 14:09:00");
    CP_Pos_FeedLine(h, 1);

    CP_Pos_FeedLine(h, 1);
    CP_Pos_PrintText(h, "apples");
    CP_Pos_SetHorizontalAbsolutePrintPosition(h, paperWidth - 12*6);
    CP_Pos_PrintText(h, "$10.00");
    CP_Pos_FeedLine(h, 1);
    CP_Pos_PrintText(h, "grapes");
    CP_Pos_SetHorizontalAbsolutePrintPosition(h, paperWidth - 12*6);
    CP_Pos_PrintText(h, "$20.00");
    CP_Pos_FeedLine(h, 1);
    CP_Pos_PrintText(h, "bananas");
    CP_Pos_SetHorizontalAbsolutePrintPosition(h, paperWidth - 12*6);
    CP_Pos_PrintText(h, "$30.00");
    CP_Pos_FeedLine(h, 1);
    CP_Pos_PrintText(h, "lemons");
    CP_Pos_SetHorizontalAbsolutePrintPosition(h, paperWidth - 12*6);
    CP_Pos_PrintText(h, "$40.00");
    CP_Pos_FeedLine(h, 1);
    CP_Pos_PrintText(h, "oranges");
    CP_Pos_SetHorizontalAbsolutePrintPosition(h, paperWidth - 12*7);
    CP_Pos_PrintText(h, "$100.00");
    CP_Pos_FeedLine(h, 1);
    CP_Pos_FeedLine(h, 1);
    CP_Pos_PrintText(h, "Before adding tax");
    CP_Pos_SetHorizontalAbsolutePrintPosition(h, paperWidth - 12*7);
    CP_Pos_PrintText(h, "$200.00");
    CP_Pos_FeedLine(h, 1);
    CP_Pos_PrintText(h, "tax 5.0%");
    CP_Pos_SetHorizontalAbsolutePrintPosition(h, paperWidth - 12*6);
    CP_Pos_PrintText(h, "$10.00");
    CP_Pos_FeedLine(h, 1);
    char line[100] = { 0, };
    memset(line, ' ', paperWidth / 12);
    CP_Pos_SetTextUnderline(h, 2);
    CP_Pos_PrintText(h, line);
    CP_Pos_SetTextUnderline(h, 0);
    CP_Pos_FeedLine(h, 1);
    CP_Pos_SetTextScale(h, 1, 0);
    CP_Pos_PrintText(h, "total");
    CP_Pos_SetHorizontalAbsolutePrintPosition(h, paperWidth - 12*2*7);
    CP_Pos_PrintText(h, "$190.00");
    CP_Pos_SetTextScale(h, 0, 0);
    CP_Pos_FeedLine(h, 1);
    CP_Pos_PrintText(h, "Customer's payment");
    CP_Pos_SetHorizontalAbsolutePrintPosition(h, paperWidth - 12*7);
    CP_Pos_PrintText(h, "$200.00");
    CP_Pos_FeedLine(h, 1);
    CP_Pos_PrintText(h, "Change");
    CP_Pos_SetHorizontalAbsolutePrintPosition(h, paperWidth - 12*6);
    CP_Pos_PrintText(h, "$10.00");
    CP_Pos_FeedLine(h, 1);

    CP_Pos_SetBarcodeHeight(h, 60);
    CP_Pos_SetBarcodeUnitWidth(h, 3);
    CP_Pos_SetBarcodeReadableTextPosition(h, CP_Pos_BarcodeTextPrintPosition_BelowBarcode);
    CP_Pos_PrintBarcode(h, CP_Pos_BarcodeType_UPCA, "12345678901");

    CP_Pos_Beep(h, 1, 500);

    Test_Pos_QueryPrintResult(h);
}

void Test_Pos_SampleTicket_58MM_2(void * h)
{
    {
        CP_Printer_ClearPrinterBuffer(h);
        CP_Pos_ResetPrinter(h);
        CP_Pos_SetMultiByteMode(h);
        CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_UTF8);
    }

    {
        CP_Pos_PrintHorizontalLine(h, 0, 383);
        CP_Pos_PrintHorizontalLine(h, 0, 383);
        CP_Pos_PrintHorizontalLine(h, 0, 383);
        CP_Pos_PrintHorizontalLine(h, 0, 383);
        CP_Pos_FeedLine(h, 1);
        CP_Pos_SetAlignment(h, CP_Pos_Alignment_Left);
        CP_Pos_SetTextBold(h, 1);

        CP_Pos_PrintTextInUTF8(h, L"公司名称：东莞市XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX公司\r\n");
        CP_Pos_PrintTextInUTF8(h, L"公司地址：东莞市XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX888街道888号\r\n");
        CP_Pos_FeedLine(h, 1);
        CP_Pos_PrintTextInUTF8(h, L"机器编号:D000010000000000000000\r\n");
        CP_Pos_PrintTextInUTF8(h, L"订 单 号:0000100000000000000000\r\n");
        CP_Pos_PrintTextInUTF8(h, L"销售日期:2019年12月03日 17时13分00秒\r\n");
        CP_Pos_PrintTextInUTF8(h, L"商品名称:康师傅桶面\r\n");
        CP_Pos_PrintTextInUTF8(h, L"销售数量:1\r\n");
        CP_Pos_PrintTextInUTF8(h, L"销售价格:元\r\n");
    }

    {
        CP_Pos_SetAlignment(h, CP_Pos_Alignment_Left);
        CP_Pos_PrintTextInUTF8(h, L"客服电话:123456789\r\n");
        CP_Pos_FeedLine(h, 1);
        //CP_Pos_SetAlignment(h, AutoReplyPrint.CP_Pos_Alignment_HCenter);
        CP_Pos_SetPrintAreaLeftMargin(h, 0);
        CP_Pos_PrintTextInUTF8(h, L"因药品属于特殊商品，除药品质量原因外，药品一经售出，不得退换\r\n");
        CP_Pos_SetPrintAreaLeftMargin(h, 0);
        CP_Pos_FeedLine(h, 1);
        CP_Pos_PrintTextInUTF8(h, L"谢谢,欢迎再次光临\r\n");

        {
            CP_Pos_SetAlignment(h, CP_Pos_Alignment_HCenter);
            CP_Pos_SetBarcodeUnitWidth(h, 7);
            CP_Pos_PrintQRCode(h, 0, CP_QRCodeECC_L, "www.caysn.com");
            CP_Pos_FeedLine(h, 1);
        }

        CP_Pos_FeedAndHalfCutPaper(h);
        CP_Pos_FeedLine(h, 1);
        CP_Pos_FeedLine(h, 1);

    }

    {
        Test_Pos_QueryPrintResult(h);
    }
}

void Test_Pos_SampleTicket_80MM_1(void * h)
{
    int nLineStartPos[3] = { 0, 201, 401};
    int nLineEndPos[3] = { 200, 400, 575};

    {
        CP_Pos_ResetPrinter(h);
        CP_Pos_FeedLine(h, 2);
    }

    {
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
    }

    {
        CP_Pos_SetMultiByteMode(h);
        CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_UTF8);
        CP_Pos_FeedLine(h, 2);
        CP_Pos_SetAlignment(h, CP_Pos_Alignment_Right);
        CP_Pos_PrintTextInUTF8(h, L"服务台\r\n");
    }

    {
        CP_Pos_FeedLine(h, 2);

        int nStartPos = 0;
        int nEndPos = 120;
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, 1, &nStartPos, &nEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, 1, &nStartPos, &nEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, 1, &nStartPos, &nEndPos);
        CP_Pos_FeedDot(h, 10);
        CP_Pos_SetAlignment(h, CP_Pos_Alignment_Left);
        CP_Pos_SetTextBold(h, true);
        CP_Pos_SetTextScale(h, 1, 1);
        CP_Pos_SetHorizontalAbsolutePrintPosition(h, 12);
        CP_Pos_PrintTextInUTF8(h, L"圆桌");
        CP_Pos_FeedDot(h, 0);
        CP_Pos_SetTextScale(h, 0, 0);
        CP_Pos_FeedDot(h, 10);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, 1, &nStartPos, &nEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, 1, &nStartPos, &nEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, 1, &nStartPos, &nEndPos);
        CP_Pos_FeedLine(h, 1);
        CP_Pos_SetTextBold(h, false);
        CP_Pos_PrintTextInUTF8(h, L"麻辣香锅（上梅林店）\r\n2018年2月7日15:51:00\r\n\r\n");
    }

    {
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
    }

    {
        CP_Pos_SetAlignment(h, CP_Pos_Alignment_HCenter);
        CP_Pos_SetTextScale(h, 1, 1);
        CP_Pos_PrintTextInUTF8(h, L"\r\n15-D-一楼-大厅-散座\r\n");
        CP_Pos_SetAlignment(h, CP_Pos_Alignment_Left);
        CP_Pos_SetTextScale(h, 0, 0);
        CP_Pos_PrintTextInUTF8(h, L"\r\n扫码点餐订单\r\n店内用餐\r\n7人\r\n");
    }

    {
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
    }

    {
        CP_Pos_SetHorizontalAbsolutePrintPosition(h, 0);
        CP_Pos_PrintTextInUTF8(h, L"\r\n热菜类\r\n");
        CP_Pos_SetHorizontalAbsolutePrintPosition(h, 80);
        CP_Pos_PrintTextInUTF8(h, L"鱼香肉丝");
        CP_Pos_SetHorizontalAbsolutePrintPosition(h, 200);
        CP_Pos_PrintTextInUTF8(h, L"1");
        CP_Pos_SetHorizontalAbsolutePrintPosition(h, 480);
        CP_Pos_PrintTextInUTF8(h, L"¥23.50\r\n");
        CP_Pos_SetHorizontalAbsolutePrintPosition(h, 80);
        CP_Pos_PrintTextInUTF8(h, L"麻辣鸡丝");
        CP_Pos_SetHorizontalAbsolutePrintPosition(h, 200);
        CP_Pos_PrintTextInUTF8(h, L"1");
        CP_Pos_SetHorizontalAbsolutePrintPosition(h, 480);
        CP_Pos_PrintTextInUTF8(h, L"¥23.50\r\n");
        CP_Pos_SetHorizontalAbsolutePrintPosition(h, 0);

        CP_Pos_PrintTextInUTF8(h, L"凉菜类\r\n");
        CP_Pos_SetHorizontalAbsolutePrintPosition(h, 80);
        CP_Pos_PrintTextInUTF8(h, L"凉拌腐竹");
        CP_Pos_SetHorizontalAbsolutePrintPosition(h, 200);
        CP_Pos_PrintTextInUTF8(h, L"1");
        CP_Pos_SetHorizontalAbsolutePrintPosition(h, 480);
        CP_Pos_PrintTextInUTF8(h, L"¥23.50\r\n");
        CP_Pos_SetHorizontalAbsolutePrintPosition(h, 80);
        CP_Pos_PrintTextInUTF8(h, L"糖醋花生");
        CP_Pos_SetHorizontalAbsolutePrintPosition(h, 200);
        CP_Pos_PrintTextInUTF8(h, L"1");
        CP_Pos_SetHorizontalAbsolutePrintPosition(h, 480);
        CP_Pos_PrintTextInUTF8(h, L"¥23.50\r\n");
    }

    {
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
    }

    {
        CP_Pos_FeedDot(h, 30);
        CP_Pos_SetHorizontalAbsolutePrintPosition(h, 80);
        CP_Pos_PrintTextInUTF8(h, L"消毒餐具");
        CP_Pos_SetHorizontalAbsolutePrintPosition(h, 200);
        CP_Pos_PrintTextInUTF8(h, L"7");
        CP_Pos_SetHorizontalAbsolutePrintPosition(h, 480);
        CP_Pos_PrintTextInUTF8(h, L"¥14.00\r\n");
    }

    {
        CP_Pos_FeedLine(h, 2);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
        CP_Pos_FeedLine(h, 1);
    }

    {
        CP_Pos_SetHorizontalAbsolutePrintPosition(h, 0);
        CP_Pos_PrintTextInUTF8(h, L"在线支付");
        CP_Pos_SetHorizontalAbsolutePrintPosition(h, 480);
        CP_Pos_PrintTextInUTF8(h, L"¥114.00\r\n");
    }

    {
        CP_Pos_PrintTextInUTF8(h, L"备注\r\n");
        CP_Pos_SetPrintAreaLeftMargin(h, 80);
        CP_Pos_PrintTextInUTF8(h, L"所有菜都不要放葱，口味要微辣。百事可乐不要加冰。上菜快点，太慢了！！\r\n\r\n");
        CP_Pos_SetPrintAreaLeftMargin(h, 0);
    }

    {
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
        CP_Pos_FeedLine(h, 1);
    }

    {
        CP_Pos_SetAlignment(h, CP_Pos_Alignment_HCenter);
        CP_Pos_PrintQRCode(h, 0, CP_QRCodeECC_L, "麻辣香锅");
        CP_Pos_PrintTextInUTF8(h, L"\r\n用心服务每一天\r\n40008083030\r\n\r\n");
    }

    {
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
        CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, sizeof(nLineStartPos) / sizeof(int), nLineStartPos, nLineEndPos);
    }

    {
        CP_Pos_FeedAndHalfCutPaper(h);
        CP_Pos_Beep(h, 1, 500);
    }

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

void Test_Printer_ClearPrinterBuffer(void * h)
{
    CP_Printer_ClearPrinterBuffer(h);
}

void Test_Pos_QueryRTStatus(void * h)
{
    int status = CP_Pos_QueryRTStatus(h, 3000);
    if (status) {
        char msg[1000] = { 0, };
        sprintf(&msg[strlen(msg)], "RTStatus: %02X %02X %02X %02X\r\n", status & 0xff, (status >> 8) & 0xff, (status >> 16) & 0xff, (status >> 24) & 0xff);
        if (CP_RTSTATUS_COVERUP(status))
            sprintf(&msg[strlen(msg)], "[Cover Up]");
        if (CP_RTSTATUS_NOPAPER(status))
            sprintf(&msg[strlen(msg)], "[No Paper]");
        ShowMessage(msg);
    } else {
        ShowMessage("Query failed");
    }
}

void Test_Pos_QueryPrintResult(void * h)
{
    static unsigned int nPageID = 1;
    bool result = CP_Pos_QueryPrintResult(h, nPageID++, 30000);
    if (!result) {
        ShowMessage("Print failed");
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

void Test_Pos_FeedAndHalfCutPaper(void * h)
{
    bool result = CP_Pos_FeedAndHalfCutPaper(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_FullCutPaper(void * h)
{
    bool result = CP_Pos_FullCutPaper(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_HalfCutPaper(void * h)
{
    bool result = CP_Pos_HalfCutPaper(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_Feed(void * h)
{
    CP_Pos_PrintText(h, "12345678901234567890");
    CP_Pos_FeedLine(h, 4);
    CP_Pos_PrintText(h, "12345678901234567890");
    CP_Pos_FeedDot(h, 100);
    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_PrintSelfTestPage(void * h)
{
    bool result = CP_Pos_PrintSelfTestPage(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_PrintText(void * h)
{
    CP_Pos_PrintTextInBytes(h, "12345678901234567890\r\n", 3);
    bool result = CP_Pos_PrintText(h, "12345678901234567890\r\n");
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_PrintTextInUTF8(void * h)
{
    const wchar_t *str =
                    L"1234567890\r\n"
                    L"abcdefghijklmnopqrstuvwxyz\r\n"
                    L"ΑΒΓΔΕΖΗΘΙΚ∧ΜΝΞΟ∏Ρ∑ΤΥΦΧΨΩ\r\n"
                    L"αβγδεζηθικλμνξοπρστυφχψω\r\n"
                    L"你好，欢迎使用！\r\n"
                    L"你號，歡迎使用！\r\n"
                    L"梦を见る事が出来なければ\r\n未来を変える事は出来ません\r\n"
                    L"왕관을 쓰려는자\r\n그 무게를 견뎌라\r\n";
    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_UTF8);
    bool result = CP_Pos_PrintTextInUTF8(h, str);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Pos_PrintTextInGBK(void * h)
{
    const wchar_t *str = L"1234567890\r\nabcdefghijklmnopqrstuvwxyz\r\n你好，欢迎使用！\r\n你號，歡迎使用！\r\n";
    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_GBK);
    bool result = CP_Pos_PrintTextInGBK(h, str);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Pos_PrintTextInBIG5(void * h)
{
    const wchar_t *str = L"1234567890\r\nabcdefghijklmnopqrstuvwxyz\r\n你號，歡迎使用！\r\n";
    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_BIG5);
    bool result = CP_Pos_PrintTextInBIG5(h, str);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Pos_PrintTextInShiftJIS(void * h)
{
    const wchar_t *str =
                    L"1234567890\r\n"
                    L"abcdefghijklmnopqrstuvwxyz\r\n"
                    L"こんにちは\r\n";
    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_ShiftJIS);
    bool result = CP_Pos_PrintTextInShiftJIS(h, str);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Pos_PrintTextInEUCKR(void * h)
{
    const wchar_t *str =
                    L"1234567890\r\n"
                    L"abcdefghijklmnopqrstuvwxyz\r\n"
                    L"왕관을 쓰려는자\r\n"
                    L"그 무게를 견뎌라\r\n";
    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_EUCKR);
    bool result = CP_Pos_PrintTextInEUCKR(h, str);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_PrintBarcode_UPCA(void * h)
{
    const char *str = "01234567890";
    CP_Pos_SetBarcodeUnitWidth(h, 2);
    CP_Pos_SetBarcodeHeight(h, 60);
    CP_Pos_SetBarcodeReadableTextFontType(h, 0);
    CP_Pos_SetBarcodeReadableTextPosition(h, CP_Pos_BarcodeTextPrintPosition_BelowBarcode);
    CP_Pos_PrintBarcode(h, CP_Pos_BarcodeType_UPCA, str);

    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Pos_PrintBarcode_UPCE(void * h)
{
    const char *str = "123456";
    CP_Pos_SetBarcodeUnitWidth(h, 2);
    CP_Pos_SetBarcodeHeight(h, 60);
    CP_Pos_SetBarcodeReadableTextFontType(h, 0);
    CP_Pos_SetBarcodeReadableTextPosition(h, CP_Pos_BarcodeTextPrintPosition_BelowBarcode);
    CP_Pos_PrintBarcode(h, CP_Pos_BarcodeType_UPCE, str);

    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Pos_PrintBarcode_EAN13(void * h)
{
    const char *str = "123456789012";
    CP_Pos_SetBarcodeUnitWidth(h, 2);
    CP_Pos_SetBarcodeHeight(h, 60);
    CP_Pos_SetBarcodeReadableTextFontType(h, 0);
    CP_Pos_SetBarcodeReadableTextPosition(h, CP_Pos_BarcodeTextPrintPosition_BelowBarcode);
    CP_Pos_PrintBarcode(h, CP_Pos_BarcodeType_EAN13, str);

    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Pos_PrintBarcode_EAN8(void * h)
{
    const char *str = "1234567";
    CP_Pos_SetBarcodeUnitWidth(h, 2);
    CP_Pos_SetBarcodeHeight(h, 60);
    CP_Pos_SetBarcodeReadableTextFontType(h, 0);
    CP_Pos_SetBarcodeReadableTextPosition(h, CP_Pos_BarcodeTextPrintPosition_BelowBarcode);
    CP_Pos_PrintBarcode(h, CP_Pos_BarcodeType_EAN8, str);

    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Pos_PrintBarcode_CODE39(void * h)
{
    const char *str = "123456";
    CP_Pos_SetBarcodeUnitWidth(h, 2);
    CP_Pos_SetBarcodeHeight(h, 60);
    CP_Pos_SetBarcodeReadableTextFontType(h, 0);
    CP_Pos_SetBarcodeReadableTextPosition(h, CP_Pos_BarcodeTextPrintPosition_BelowBarcode);
    CP_Pos_PrintBarcode(h, CP_Pos_BarcodeType_CODE39, str);

    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Pos_PrintBarcode_ITF(void * h)
{
    const char *str = "123456";
    CP_Pos_SetBarcodeUnitWidth(h, 2);
    CP_Pos_SetBarcodeHeight(h, 60);
    CP_Pos_SetBarcodeReadableTextFontType(h, 0);
    CP_Pos_SetBarcodeReadableTextPosition(h, CP_Pos_BarcodeTextPrintPosition_BelowBarcode);
    CP_Pos_PrintBarcode(h, CP_Pos_BarcodeType_ITF, str);

    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Pos_PrintBarcode_CODEBAR(void * h)
{
    const char *str = "A123456A";
    CP_Pos_SetBarcodeUnitWidth(h, 2);
    CP_Pos_SetBarcodeHeight(h, 60);
    CP_Pos_SetBarcodeReadableTextFontType(h, 0);
    CP_Pos_SetBarcodeReadableTextPosition(h, CP_Pos_BarcodeTextPrintPosition_BelowBarcode);
    CP_Pos_PrintBarcode(h, CP_Pos_BarcodeType_CODEBAR, str);

    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Pos_PrintBarcode_CODE93(void * h)
{
    const char *str = "123456";
    CP_Pos_SetBarcodeUnitWidth(h, 2);
    CP_Pos_SetBarcodeHeight(h, 60);
    CP_Pos_SetBarcodeReadableTextFontType(h, 0);
    CP_Pos_SetBarcodeReadableTextPosition(h, CP_Pos_BarcodeTextPrintPosition_BelowBarcode);
    CP_Pos_PrintBarcode(h, CP_Pos_BarcodeType_CODE93, str);

    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Pos_PrintBarcode_CODE128(void * h)
{
    const char *str = "No.123456";
    CP_Pos_SetBarcodeUnitWidth(h, 2);
    CP_Pos_SetBarcodeHeight(h, 60);
    CP_Pos_SetBarcodeReadableTextFontType(h, 0);
    CP_Pos_SetBarcodeReadableTextPosition(h, CP_Pos_BarcodeTextPrintPosition_BelowBarcode);
    CP_Pos_PrintBarcode(h, CP_Pos_BarcodeType_CODE128, str);

    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_PrintQRCode(void * h)
{
    CP_Pos_SetBarcodeUnitWidth(h, 8);
    CP_Pos_PrintQRCode(h, 0, CP_QRCodeECC_L, "Hello 欢迎使用");

    int result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");

}
void Test_Pos_PrintQRCodeUseEpsonCmd(void * h)
{
    CP_Pos_PrintQRCodeUseEpsonCmd(h, 8, CP_QRCodeECC_L, "Hello 欢迎使用");

    int result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");

}

void Test_Pos_PrintRasterImageFromFile(void * h)
{
    const char *str = "blackwhite_1.bmp";

    CP_Pos_PrintRasterImageFromFile(h, 0, 0, str, CP_ImageBinarizationMethod_Dithering, CP_ImageCompressionMethod_None);
    CP_Pos_PrintRasterImageFromFile(h, 0, 0, str, CP_ImageBinarizationMethod_Thresholding, CP_ImageCompressionMethod_None);

    int result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_PrintHorizontalLine(void * h)
{
    for (int i = 0; i < 50; i += 1)
        CP_Pos_PrintHorizontalLine(h, i, i + 100);
    for (int i = 50; i > 0; i -= 1)
        CP_Pos_PrintHorizontalLine(h, i, i + 100);

    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Pos_PrintHorizontalLineSpecifyThickness(void * h)
{
    CP_Pos_PrintHorizontalLineSpecifyThickness(h, 0, 200, 10);

    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}
void Test_Pos_PrintMultipleHorizontalLinesAtOneRow(void * h)
{
    int r = 150;
    for (int y = -r; y <= r; ++y) {
        int x = sqrt(double(r*r-y*y));
        int x1 = -x+r;
        int x2 = x+r;
        int pLineStartPosition[2] = { x1, x2 };
        int pLineEndPosition[2] = { x1, x2 };
        if (CP_Pos_PrintMultipleHorizontalLinesAtOneRow(h, 2, pLineStartPosition, pLineEndPosition))
            continue;
        else
            break;
    }

    bool result = CP_Pos_FeedLine(h, 3);
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

void Test_Pos_SetSingleByteMode(void * h)
{
    const char *str = "Welcome 你好\r\n";

    CP_Pos_SetSingleByteMode(h);
    CP_Pos_SetCharacterSet(h, CP_CharacterSet_CHINA);
    CP_Pos_SetCharacterCodepage(h, CP_CharacterCodepage_CP437);

    bool result = CP_Pos_PrintText(h, str);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_SetMultiByteMode(void * h)
{
    const char *str = "Welcome 你好\r\n";

    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_UTF8);

    bool result = CP_Pos_PrintText(h, str);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_SetMovementUnit(void * h)
{
    CP_Pos_SetMovementUnit(h, 100, 100);
    CP_Pos_SetAsciiTextCharRightSpacing(h, 10);
    CP_Pos_PrintText(h, "1234567890\r\n");
    CP_Pos_SetMovementUnit(h, 200, 200);
    CP_Pos_SetAsciiTextCharRightSpacing(h, 10);
    CP_Pos_PrintText(h, "1234567890\r\n");
    bool result = CP_Pos_SetAsciiTextCharRightSpacing(h, 0);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_SetPrintAreaLeftMargin(void * h)
{
    CP_Pos_SetPrintAreaLeftMargin(h, 96);
    CP_Pos_SetPrintAreaWidth(h, 384);
    CP_Pos_PrintText(h, "1234567890123456789012345678901234567890\r\n");
    bool result = CP_Pos_ResetPrinter(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_SetPrintAreaWidth(void * h)
{
    CP_Pos_SetPrintAreaWidth(h, 384);
    CP_Pos_PrintText(h, "1234567890123456789012345678901234567890\r\n");
    bool result = CP_Pos_ResetPrinter(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_SetPrintPosition(void * h)
{
    CP_Pos_SetHorizontalAbsolutePrintPosition(h, 0);
    CP_Pos_PrintText(h, "12345678901234567890\r\n");
    CP_Pos_SetHorizontalAbsolutePrintPosition(h, 24);
    CP_Pos_PrintText(h, "1234567890");
    CP_Pos_SetHorizontalRelativePrintPosition(h, 24);
    CP_Pos_PrintText(h, "1234567890");
    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_SetAlignment(void * h)
{
    CP_Pos_SetAlignment(h, CP_Pos_Alignment_Right);
    CP_Pos_PrintText(h, "12345678901234567890\r\n");
    CP_Pos_SetAlignment(h, CP_Pos_Alignment_HCenter);
    CP_Pos_PrintText(h, "12345678901234567890\r\n");
    CP_Pos_SetAlignment(h, CP_Pos_Alignment_Left);
    CP_Pos_PrintText(h, "12345678901234567890\r\n");
    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_SetTextScale(void * h)
{
    int nPosition = 0;
    CP_Pos_SetHorizontalAbsolutePrintPosition(h, nPosition);
    CP_Pos_SetTextScale(h, 0, 0);
    CP_Pos_PrintText(h, "a");
    nPosition += 12;
    CP_Pos_SetHorizontalAbsolutePrintPosition(h, nPosition);
    CP_Pos_SetTextScale(h, 1, 1);
    CP_Pos_PrintText(h, "a");
    nPosition += 12*2;
    CP_Pos_SetHorizontalAbsolutePrintPosition(h, nPosition);
    CP_Pos_SetTextScale(h, 2, 2);
    CP_Pos_PrintText(h, "a");
    nPosition += 12*3;
    CP_Pos_SetHorizontalAbsolutePrintPosition(h, nPosition);
    CP_Pos_SetTextScale(h, 3, 3);
    CP_Pos_PrintText(h, "a");
    nPosition += 12*4;
    CP_Pos_SetHorizontalAbsolutePrintPosition(h, nPosition);
    CP_Pos_SetTextScale(h, 4, 4);
    CP_Pos_PrintText(h, "a");
    nPosition += 12*5;
    CP_Pos_SetHorizontalAbsolutePrintPosition(h, nPosition);
    CP_Pos_SetTextScale(h, 5, 5);
    CP_Pos_PrintText(h, "a");
    nPosition += 12*6;
    CP_Pos_SetHorizontalAbsolutePrintPosition(h, nPosition);
    CP_Pos_SetTextScale(h, 6, 6);
    CP_Pos_PrintText(h, "a");
    nPosition += 12*7;
    CP_Pos_SetHorizontalAbsolutePrintPosition(h, nPosition);
    CP_Pos_SetTextScale(h, 7, 7);
    CP_Pos_PrintText(h, "a");
    CP_Pos_SetTextScale(h, 0, 0);
    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_SetAsciiTextFontType(void * h)
{
    CP_Pos_SetAsciiTextFontType(h, 0);
    CP_Pos_PrintText(h, "FontA\r\n");
    CP_Pos_SetAsciiTextFontType(h, 1);
    CP_Pos_PrintText(h, "FontB\r\n");
    CP_Pos_SetAsciiTextFontType(h, 2);
    CP_Pos_PrintText(h, "FontC\r\n");
    CP_Pos_SetAsciiTextFontType(h, 3);
    CP_Pos_PrintText(h, "FontD\r\n");
    CP_Pos_SetAsciiTextFontType(h, 4);
    CP_Pos_PrintText(h, "FontE\r\n");
    CP_Pos_SetAsciiTextFontType(h, 0);
    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_SetTextBold(void * h)
{
    CP_Pos_SetTextBold(h, 1);
    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_UTF8);
    CP_Pos_PrintTextInUTF8(h, L"粗体 Bold\r\n");
    CP_Pos_SetTextBold(h, 0);
    CP_Pos_PrintText(h, "Normal\r\n");
    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_SetTextUnderline(void * h)
{
    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_UTF8);
    CP_Pos_SetTextUnderline(h, 2);
    CP_Pos_PrintTextInUTF8(h, L"下划线2点 Underline2\r\n");
    CP_Pos_SetTextUnderline(h, 1);
    CP_Pos_PrintTextInUTF8(h, L"下划线1点 Underline2\r\n");
    CP_Pos_SetTextUnderline(h, 0);
    CP_Pos_PrintTextInUTF8(h, L"无下划线 No Underline\r\n");
    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_SetTextUpsideDown(void * h)
{
    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_UTF8);
    CP_Pos_SetTextUpsideDown(h, 1);
    CP_Pos_PrintTextInUTF8(h, L"上下倒置 UpsideDown\r\n");
    CP_Pos_SetTextUpsideDown(h, 0);
    CP_Pos_PrintText(h, "Normal\r\n");
    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_SetTextWhiteOnBlack(void * h)
{
    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_UTF8);
    CP_Pos_SetTextWhiteOnBlack(h, 1);
    CP_Pos_PrintTextInUTF8(h, L"黑白反显 WhiteOnBlack\r\n");
    CP_Pos_SetTextWhiteOnBlack(h, 0);
    CP_Pos_PrintText(h, "Normal\r\n");
    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_SetTextRotate(void * h)
{
    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_UTF8);
    CP_Pos_SetTextRotate(h, 1);
    CP_Pos_PrintTextInUTF8(h, L"文字旋转打印 TextRotate\r\n");
    CP_Pos_SetTextRotate(h, 0);
    CP_Pos_PrintText(h, "Normal\r\n");
    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_SetTextLineHeight(void * h)
{
    CP_Pos_SetTextLineHeight(h, 100);
    CP_Pos_PrintText(h, "LineHeight 100\r\nLineHeight 100\r\nLineHeight 100\r\n");
    CP_Pos_SetTextLineHeight(h, 32);
    CP_Pos_PrintText(h, "LineHeight 32\r\nLineHeight 32\r\nLineHeight 32\r\n");
    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_SetAsciiTextCharRightSpacing(void * h)
{
    const wchar_t *str = L"Hello你好\r\n";
    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_UTF8);
    CP_Pos_SetAsciiTextCharRightSpacing(h, 2);
    CP_Pos_PrintTextInUTF8(h, str);
    CP_Pos_SetAsciiTextCharRightSpacing(h, 0);
    CP_Pos_PrintTextInUTF8(h, str);
    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Pos_SetKanjiTextCharSpacing(void * h)
{
    const wchar_t *str = L"Hello你好\r\n";
    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_UTF8);
    CP_Pos_SetKanjiTextCharSpacing(h, 2, 2);
    CP_Pos_PrintTextInUTF8(h, str);
    CP_Pos_SetKanjiTextCharSpacing(h, 0, 0);
    CP_Pos_PrintTextInUTF8(h, str);
    bool result = CP_Pos_FeedLine(h, 3);
    if (!result)
        ShowMessage("Write failed");
}
