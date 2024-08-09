#include "cmdtestfunction.h"
#include "cmdtestutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void Test_Page_SampleTicket_58mm_1(void * h)
{
    int paperWidth = 384;
    int paperHeight = 800;

    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, paperWidth, paperHeight);
    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_UTF8);

    CP_Pos_SetTextScale(h, 1, 1);
    CP_Page_DrawTextInUTF8(h, CP_Page_DrawAlignment_HCenter, 10, L"中国福利彩票");
    CP_Pos_SetTextScale(h, 0, 0);
    CP_Page_DrawTextInUTF8(h, 0, 60, L"销售期2015033");
    CP_Page_DrawTextInUTF8(h, CP_Page_DrawAlignment_Right, 60, L"兑奖期2015033");
    CP_Page_DrawTextInUTF8(h, 0, 90, L"站号230902001");
    CP_Page_DrawTextInUTF8(h, CP_Page_DrawAlignment_Right, 90, L"7639-A");
    CP_Page_DrawTextInUTF8(h, 0, 120, L"注数5");
    CP_Page_DrawTextInUTF8(h, CP_Page_DrawAlignment_Right, 120, L"金额10.00");

    CP_Pos_SetTextLineHeight(h, 60);
    CP_Pos_SetTextScale(h, 0, 1);
    CP_Pos_SetTextUnderline(h, 2);
    CP_Page_DrawTextInUTF8(h, 0, 160, L" A: 02  07  10  17  20  21  25\r\n A: 02  07  10  17  20  21  25\r\n A: 02  07  10  17  20  21  25\r\n A: 02  07  10  17  20  21  25\r\n A: 02  07  10  17  20  21  25\r\n");
    CP_Pos_SetTextScale(h, 0, 0);
    CP_Pos_SetTextUnderline(h, 0);
    CP_Pos_SetTextLineHeight(h, 30);

    CP_Pos_SetBarcodeHeight(h, 60);
    CP_Pos_SetBarcodeUnitWidth(h, 3);
    CP_Pos_SetBarcodeReadableTextPosition(h, CP_Pos_BarcodeTextPrintPosition_BelowBarcode);
    CP_Page_DrawBarcode(h, 0, 460, CP_Pos_BarcodeType_CODE128, "1234567890");
    CP_Pos_SetBarcodeUnitWidth(h, 4);
    CP_Page_DrawQRCode(h, 284, 460, 0, CP_QRCodeECC_L, "1234567890");

    CP_Page_PrintPage(h);
    CP_Page_ExitPageMode(h);

    CP_Pos_FeedAndHalfCutPaper(h);
    CP_Pos_KickOutDrawer(h, 0, 100, 100);
    CP_Pos_KickOutDrawer(h, 1, 100, 100);
    CP_Pos_Beep(h, 1, 500);

    Test_Pos_QueryPrintResult(h);
}

void Test_Page_SampleTicket_80mm_1(void * h)
{
    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 576, 200);
    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_GBK);

    CP_Pos_SetTextScale(h, 1, 1);
    CP_Page_DrawText(h, CP_Page_DrawAlignment_HCenter, 0, "Print Store");
    CP_Pos_SetTextScale(h, 7, 1);
    CP_Page_DrawText(h, CP_Page_DrawAlignment_HCenter, 48,"______");
    CP_Page_DrawBarcode(h, CP_Page_DrawAlignment_HCenter, 100, CP_Pos_BarcodeType_CODE128, "No.201804190001");

    CP_Page_SetPageArea(h, 0, 200, 576, 1400);
    CP_Page_DrawBox(h, 0, 0, 576, 1400, 1, 1);
    CP_Page_SetPageDrawDirection(h, CP_Page_DrawDirection_TopToBottom);

    int y = 0;
    CP_Pos_SetTextScale(h, 1, 1);
    CP_Page_DrawTextInGBK(h, CP_Page_DrawAlignment_HCenter, y, L"Print物流（测试）托运单");

    y += 64;
    CP_Pos_SetTextScale(h, 0, 0);
    CP_Page_DrawTextInGBK(h, 0,   y, L"发站：厦门总部");
    CP_Page_DrawTextInGBK(h, 300, y, L"到站：广州 0539-7825336");
    CP_Page_DrawTextInGBK(h, 600, y, L"托运日期：2016-05-24");
    CP_Page_DrawTextInGBK(h, 900,y, L"运单号：601052400032");

    y += 32;
    CP_Page_DrawRect(h, 0, y - 5, 1400, 2, 1);
    CP_Page_DrawTextInGBK(h, 0,   y, L"收货人");
    CP_Page_DrawTextInGBK(h, 300, y, L"电话：15000353189");
    CP_Page_DrawTextInGBK(h, 600, y, L"运费：提付10");

    y += 32;
    CP_Page_DrawRect(h, 0, y - 5, 1400, 2, 1);
    CP_Page_DrawTextInGBK(h, 0,   y, L"发货人");
    CP_Page_DrawTextInGBK(h, 300, y, L"电话：15000353189");
    CP_Page_DrawTextInGBK(h, 600, y, L"会员号");
    CP_Page_DrawTextInGBK(h, 900, y, L"代收款：1000");

    y += 32;
    CP_Page_DrawRect(h, 0, y - 5, 1400, 2, 1);
    CP_Page_DrawTextInGBK(h, 0,   y, L"货物名称");
    CP_Page_DrawTextInGBK(h, 150, y, L"件数");
    CP_Page_DrawTextInGBK(h, 300, y, L"重量");
    CP_Page_DrawTextInGBK(h, 450, y, L"体积");
    CP_Page_DrawTextInGBK(h, 600, y, L"保价额");
    CP_Page_DrawTextInGBK(h, 750, y, L"保价费");
    CP_Page_DrawTextInGBK(h, 900, y, L"交货方式");
    CP_Page_DrawTextInGBK(h, 1050, y, L"自提");

    y += 32;
    CP_Page_DrawRect(h, 0, y - 5, 1400, 2, 1);
    CP_Page_DrawTextInGBK(h, 0,   y, L"配件");
    CP_Page_DrawTextInGBK(h, 900, y, L"送货费");

    y += 32;
    CP_Page_DrawRect(h, 0, y - 5, 1400, 2, 1);
    CP_Page_DrawTextInGBK(h, 0,   y, L"托运地址");
    CP_Page_DrawTextInGBK(h, 150, y, L"运河路高架桥南张营中心街东首");
    CP_Page_DrawTextInGBK(h, 900, y, L"预付运费");

    y += 32;
    CP_Page_DrawRect(h, 0, y - 5, 1400, 2, 1);
    CP_Page_DrawTextInGBK(h, 0,   y, L"到站地址");
    CP_Page_DrawTextInGBK(h, 150, y, L"金兰物流E7区11号");
    CP_Page_DrawTextInGBK(h, 900, y, L"提付合计");

    y += 32;
    CP_Page_DrawRect(h, 0, y - 5, 1400, 2, 1);
    CP_Page_DrawTextInGBK(h, 0,   y, L"备注");
    CP_Page_DrawTextInGBK(h, 900, y, L"返款");

    y += 32;
    CP_Page_DrawRect(h, 0, y - 5, 1400, 2, 1);
    CP_Page_DrawTextInGBK(h, 0,   y, L"声明：1、不得虚假报货名 2、不得虚假报货名 3、不得虚假报货名 4、不得虚假报货名 5、不得虚假报货名 6、不得虚假报货名 7、不得虚假报货名 8、不得虚假报货名 1、不得虚假报货名 2、不得虚假报货名 3、不得虚假报货名 4、不得虚假报货名 5、不得虚假报货名 6、不得虚假报货名 7、不得虚假报货名 8、不得虚假报货名 1、不得虚假报货名 2、不得虚假报货名 3、不得虚假报货名 4、不得虚假报货名 5、不得虚假报货名 6、不得虚假报货名 7、不得虚假报货名 8、不得虚假报货名 1、不得虚假报货名 2、不得虚假报货名 3、不得虚假报货名 4、不得虚假报货名 5、不得虚假报货名 6、不得虚假报货名 7、不得虚假报货名 8、不得虚假报货名");

    y = 530;
    CP_Page_DrawRect(h, 0, y - 5, 1400, 2, 1);
    CP_Page_DrawTextInGBK(h, 0,   y, L"服务查询：2379911");
    CP_Page_DrawTextInGBK(h, 300, y, L"发货人签名");
    CP_Page_DrawTextInGBK(h, 600, y, L"第一联");
    CP_Page_DrawTextInGBK(h, 900, y, L"制单");

    CP_Page_PrintPage(h);
    CP_Page_ExitPageMode(h);

    CP_Pos_FeedAndHalfCutPaper(h);
    CP_Pos_KickOutDrawer(h, 0, 100, 100);
    CP_Pos_KickOutDrawer(h, 1, 100, 100);
    CP_Pos_Beep(h, 1, 500);

    Test_Pos_QueryPrintResult(h);
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

void Test_Page_SetPageDrawDirection(void * h)
{
    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Page_SetPageDrawDirection(h, CP_Page_DrawDirection_LeftToRight);
    CP_Page_DrawText(h, 0, 0, "LeftToRight");
    CP_Page_SetPageDrawDirection(h, CP_Page_DrawDirection_RightToLeft);
    CP_Page_DrawText(h, 0, 0, "RightToLeft");
    CP_Page_SetPageDrawDirection(h, CP_Page_DrawDirection_TopToBottom);
    CP_Page_DrawText(h, 0, 0, "TopToBottom");
    CP_Page_SetPageDrawDirection(h, CP_Page_DrawDirection_BottomToTop);
    CP_Page_DrawText(h, 0, 0, "BottomToTop");
    CP_Page_PrintPage(h);
    bool result = CP_Page_ExitPageMode(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Page_DrawRect(void * h)
{
    // 10,10
    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Page_DrawRect(h, 10, 10, 100, 100, 1);
    CP_Page_DrawRect(h, 20, 20, 80, 80, 0);
    CP_Page_PrintPage(h);
    CP_Page_ExitPageMode(h);

    // left,top
    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Page_DrawRect(h, -1, -1, 100, 20, 1);
    CP_Page_PrintPage(h);
    CP_Page_ExitPageMode(h);

    // left,vcenter
    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Page_DrawRect(h, -1, -2, 100, 20, 1);
    CP_Page_PrintPage(h);
    CP_Page_ExitPageMode(h);

    // left,bottom
    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Page_DrawRect(h, -1, -3, 100, 20, 1);
    CP_Page_PrintPage(h);
    CP_Page_ExitPageMode(h);

    // hcenter,top
    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Page_DrawRect(h, -2, -1, 100, 20, 1);
    CP_Page_PrintPage(h);
    CP_Page_ExitPageMode(h);

    // hcenter,vcenter
    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Page_DrawRect(h, -2, -2, 100, 20, 1);
    CP_Page_PrintPage(h);
    CP_Page_ExitPageMode(h);

    // hcenter,bottom
    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Page_DrawRect(h, -2, -3, 100, 20, 1);
    CP_Page_PrintPage(h);
    CP_Page_ExitPageMode(h);

    // right,top
    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Page_DrawRect(h, -3, -1, 100, 20, 1);
    CP_Page_PrintPage(h);
    CP_Page_ExitPageMode(h);

    // right,vcenter
    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Page_DrawRect(h, -3, -2, 100, 20, 1);
    CP_Page_PrintPage(h);
    CP_Page_ExitPageMode(h);

    // right,bottom
    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Page_DrawRect(h, -3, -3, 100, 20, 1);
    CP_Page_PrintPage(h);
    CP_Page_ExitPageMode(h);
}

void Test_Page_DrawText(void * h)
{
    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Page_DrawText(h, 0, 0, "12345678901234567890");
    CP_Page_PrintPage(h);
    bool result = CP_Page_ExitPageMode(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Page_DrawTextInUTF8(void * h)
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

    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Page_DrawTextInUTF8(h, 0, 0, str);
    CP_Page_PrintPage(h);
    bool result = CP_Page_ExitPageMode(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Page_DrawTextInGBK(void * h)
{
    const wchar_t *str = L"1234567890\r\nabcdefghijklmnopqrstuvwxyz\r\n你好，欢迎使用！\r\n你號，歡迎使用！\r\n";

    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_GBK);

    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Page_DrawTextInGBK(h, 0, 0, str);
    CP_Page_PrintPage(h);
    bool result = CP_Page_ExitPageMode(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Page_DrawTextInBIG5(void * h)
{
    const wchar_t *str = L"1234567890\r\nabcdefghijklmnopqrstuvwxyz\r\n你號，歡迎使用！\r\n";

    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_BIG5);

    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Page_DrawTextInBIG5(h, 0, 0, str);
    CP_Page_PrintPage(h);
    bool result = CP_Page_ExitPageMode(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Page_DrawTextInShiftJIS(void * h)
{
    const wchar_t *str =
                    L"1234567890\r\n"
                    L"abcdefghijklmnopqrstuvwxyz\r\n"
                    L"こんにちは\r\n";

    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_ShiftJIS);

    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Page_DrawTextInShiftJIS(h, 0, 0, str);
    CP_Page_PrintPage(h);
    bool result = CP_Page_ExitPageMode(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Page_DrawTextInEUCKR(void * h)
{
    const wchar_t *str =
                    L"1234567890\r\n"
                    L"abcdefghijklmnopqrstuvwxyz\r\n"
                    L"왕관을 쓰려는자\r\n"
                    L"그 무게를 견뎌라\r\n";

    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_EUCKR);

    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Page_DrawTextInEUCKR(h, 0, 0, str);
    CP_Page_PrintPage(h);
    bool result = CP_Page_ExitPageMode(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Page_DrawBarcode(void * h)
{
    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 1000);
    CP_Pos_SetBarcodeUnitWidth(h, 2);
    CP_Pos_SetBarcodeHeight(h, 60);
    CP_Pos_SetBarcodeReadableTextFontType(h, 0);
    CP_Pos_SetBarcodeReadableTextPosition(h, CP_Pos_BarcodeTextPrintPosition_BelowBarcode);
    CP_Page_DrawBarcode(h, 0, 0, CP_Pos_BarcodeType_UPCA, "01234567890");
    CP_Page_DrawBarcode(h, 0, 100, CP_Pos_BarcodeType_UPCE, "123456");
    CP_Page_DrawBarcode(h, 0, 200, CP_Pos_BarcodeType_EAN13, "123456789012");
    CP_Page_DrawBarcode(h, 0, 300, CP_Pos_BarcodeType_EAN8, "1234567");
    CP_Page_DrawBarcode(h, 0, 400, CP_Pos_BarcodeType_CODE39, "123456");
    CP_Page_DrawBarcode(h, 0, 500, CP_Pos_BarcodeType_ITF, "123456");
    CP_Page_DrawBarcode(h, 0, 600, CP_Pos_BarcodeType_CODEBAR, "A123456A");
    CP_Page_DrawBarcode(h, 0, 700, CP_Pos_BarcodeType_CODE93, "123456");
    CP_Page_DrawBarcode(h, 0, 800, CP_Pos_BarcodeType_CODE128, "No.123456");
    CP_Page_PrintPage(h);
    CP_Page_ExitPageMode(h);
}

void Test_Page_DrawBarcode_CODE128(void * h)
{
    const char *str = "No.123456";

    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Pos_SetBarcodeUnitWidth(h, 2);
    CP_Pos_SetBarcodeHeight(h, 60);
    CP_Pos_SetBarcodeReadableTextFontType(h, 0);
    CP_Pos_SetBarcodeReadableTextPosition(h, CP_Pos_BarcodeTextPrintPosition_BelowBarcode);
    CP_Page_DrawBarcode(h, 10, 100, CP_Pos_BarcodeType_CODE128, str);
    CP_Page_DrawBarcode(h, 10, 200, CP_Pos_BarcodeType_CODE128, str);
    CP_Page_DrawBarcode(h, 10, 300, CP_Pos_BarcodeType_CODE128, str);
    CP_Page_PrintPage(h);
    CP_Page_ExitPageMode(h);

    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Pos_SetBarcodeUnitWidth(h, 2);
    CP_Pos_SetBarcodeHeight(h, 60);
    CP_Pos_SetBarcodeReadableTextFontType(h, 0);
    CP_Pos_SetBarcodeReadableTextPosition(h, CP_Pos_BarcodeTextPrintPosition_None);
    CP_Page_DrawBarcode(h, -1, -1, CP_Pos_BarcodeType_CODE128, str);
    CP_Page_DrawBarcode(h, -2, -2, CP_Pos_BarcodeType_CODE128, str);
    CP_Page_DrawBarcode(h, -3, -3, CP_Pos_BarcodeType_CODE128, str);
    CP_Page_PrintPage(h);
    CP_Page_ExitPageMode(h);

    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Pos_SetBarcodeUnitWidth(h, 2);
    CP_Pos_SetBarcodeHeight(h, 60);
    CP_Pos_SetBarcodeReadableTextFontType(h, 0);
    CP_Pos_SetBarcodeReadableTextPosition(h, CP_Pos_BarcodeTextPrintPosition_AboveAndBelowBarcode);
    CP_Page_DrawBarcode(h, -1, -1, CP_Pos_BarcodeType_CODE128, str);
    CP_Page_DrawBarcode(h, -2, -2, CP_Pos_BarcodeType_CODE128, str);
    CP_Page_DrawBarcode(h, -3, -3, CP_Pos_BarcodeType_CODE128, str);
    CP_Page_PrintPage(h);
    CP_Page_ExitPageMode(h);

    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Pos_SetBarcodeUnitWidth(h, 2);
    CP_Pos_SetBarcodeHeight(h, 60);
    CP_Pos_SetBarcodeReadableTextFontType(h, 0);
    CP_Pos_SetBarcodeReadableTextPosition(h, CP_Pos_BarcodeTextPrintPosition_AboveBarcode);
    CP_Page_DrawBarcode(h, -1, -1, CP_Pos_BarcodeType_CODE128, str);
    CP_Page_DrawBarcode(h, -2, -2, CP_Pos_BarcodeType_CODE128, str);
    CP_Page_DrawBarcode(h, -3, -3, CP_Pos_BarcodeType_CODE128, str);
    CP_Page_PrintPage(h);
    CP_Page_ExitPageMode(h);

    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Pos_SetBarcodeUnitWidth(h, 2);
    CP_Pos_SetBarcodeHeight(h, 60);
    CP_Pos_SetBarcodeReadableTextFontType(h, 0);
    CP_Pos_SetBarcodeReadableTextPosition(h, CP_Pos_BarcodeTextPrintPosition_BelowBarcode);
    CP_Page_DrawBarcode(h, -1, -1, CP_Pos_BarcodeType_CODE128, str);
    CP_Page_DrawBarcode(h, -2, -2, CP_Pos_BarcodeType_CODE128, str);
    CP_Page_DrawBarcode(h, -3, -3, CP_Pos_BarcodeType_CODE128, str);
    CP_Page_PrintPage(h);
    bool result = CP_Page_ExitPageMode(h);
    if (!result)
        ShowMessage("Write failed");
}

void Test_Page_DrawQRCode(void * h)
{
    const char *str = "Hello";

    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Pos_SetBarcodeUnitWidth(h, 4);
    CP_Page_DrawQRCode(h, -1, -1, 0, CP_QRCodeECC_L, str);
    CP_Page_DrawQRCode(h, -2, -2, 0, CP_QRCodeECC_L, str);
    CP_Page_DrawQRCode(h, -3, -3, 0, CP_QRCodeECC_L, str);
    CP_Page_PrintPage(h);
    CP_Page_ExitPageMode(h);

    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 1000);
    CP_Page_DrawBox(h, 0, 0, 384, 1000, 2, 1);
    CP_Pos_SetBarcodeUnitWidth(h, 4);
    CP_Page_DrawQRCode(h, 10, 10, 10, CP_QRCodeECC_L, str);
    CP_Page_DrawQRCode(h, 10, 300, 10, CP_QRCodeECC_L, str);
    CP_Page_DrawQRCode(h, 10, 600, 10, CP_QRCodeECC_L, str);
    CP_Page_PrintPage(h);
    CP_Page_ExitPageMode(h);
}

void Test_Page_DrawRasterImageFromFile(void * h)
{
    const char *str = "blackwhite_1.bmp";

    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Page_DrawRasterImageFromFile(h, 0, 0, 0, 0, str, CP_ImageBinarizationMethod_Dithering);
    CP_Page_PrintPage(h);
    CP_Page_ExitPageMode(h);

    Test_Pos_QueryPrintResult(h);
}
