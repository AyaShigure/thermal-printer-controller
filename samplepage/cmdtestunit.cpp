#include "cmdtestunit.h"
#include "cmdtestfunction.h"

CmdTestUnit listCmdTestUnit[] = {

    { "Test_Page_SampleTicket_58mm_1", Test_Page_SampleTicket_58mm_1 },
    { "Test_Page_SampleTicket_80mm_1", Test_Page_SampleTicket_80mm_1 },

    { "Test_Pos_QueryPrintResult", Test_Pos_QueryPrintResult },

    { "Test_Page_SetPageDrawDirection", Test_Page_SetPageDrawDirection },
    { "Test_Page_DrawRect", Test_Page_DrawRect },
    { "Test_Page_DrawText", Test_Page_DrawText },
    { "Test_Page_DrawTextInUTF8", Test_Page_DrawTextInUTF8 },
    { "Test_Page_DrawTextInGBK", Test_Page_DrawTextInGBK },
    { "Test_Page_DrawTextInBIG5", Test_Page_DrawTextInBIG5 },
    { "Test_Page_DrawTextInShiftJIS", Test_Page_DrawTextInShiftJIS },
    { "Test_Page_DrawTextInEUCKR", Test_Page_DrawTextInEUCKR },
    { "Test_Page_DrawBarcode", Test_Page_DrawBarcode },
    { "Test_Page_DrawBarcode_CODE128", Test_Page_DrawBarcode_CODE128 },
    { "Test_Page_DrawQRCode", Test_Page_DrawQRCode },
    { "Test_Page_DrawRasterImageFromFile", Test_Page_DrawRasterImageFromFile },

};
size_t listCmdTestUnitSize = sizeof(listCmdTestUnit) / sizeof(CmdTestUnit);
