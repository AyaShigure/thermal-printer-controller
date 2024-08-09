#include "cmdtestunit.h"
#include "cmdtestfunction.h"

CmdTestUnit listCmdTestUnit[] = {

    { "Test_Label_SampleTicket_55x30_1", Test_Label_SampleTicket_55x30_1 },

	{ "Test_Port_Write", Test_Port_Write },
    { "Test_Port_Read", Test_Port_Read },
    { "Test_Port_ReadUntilByte", Test_Port_ReadUntilByte },
    { "Test_Port_Available", Test_Port_Available },
    { "Test_Port_SkipAvailable", Test_Port_SkipAvailable },
	{ "Test_Port_IsConnectionValid", Test_Port_IsConnectionValid },

    { "Test_Printer_ClearPrinterBuffer", Test_Printer_ClearPrinterBuffer },

    { "Test_Pos_QueryRTStatus", Test_Pos_QueryRTStatus },
    { "Test_Pos_QueryPrintResult", Test_Pos_QueryPrintResult },

    { "Test_Pos_KickOutDrawer", Test_Pos_KickOutDrawer },
    { "Test_Pos_Beep", Test_Pos_Beep },

    { "Test_Pos_PrintSelfTestPage", Test_Pos_PrintSelfTestPage },

    { "Test_Pos_ResetPrinter", Test_Pos_ResetPrinter },
    { "Test_Pos_SetPrintSpeed_20", Test_Pos_SetPrintSpeed_20 },
    { "Test_Pos_SetPrintSpeed_50", Test_Pos_SetPrintSpeed_50 },
    { "Test_Pos_SetPrintSpeed_100", Test_Pos_SetPrintSpeed_100 },
    { "Test_Pos_SetPrintDensity_0", Test_Pos_SetPrintDensity_0 },
    { "Test_Pos_SetPrintDensity_7", Test_Pos_SetPrintDensity_7 },
    { "Test_Pos_SetPrintDensity_15", Test_Pos_SetPrintDensity_15 },

    { "Test_Label_EnableLabelMode", Test_Label_EnableLabelMode },
    { "Test_Label_DisableLabelMode", Test_Label_DisableLabelMode },
    { "Test_Label_CalibrateLabel", Test_Label_CalibrateLabel },
    { "Test_Label_FeedLabel", Test_Label_FeedLabel },
    { "Test_Label_PageBegin", Test_Label_PageBegin_PagePrint },
    { "Test_Label_PagePrint", Test_Label_PageBegin_PagePrint },
    { "Test_Label_DrawText", Test_Label_DrawText },
    { "Test_Label_DrawTextInUTF8", Test_Label_DrawTextInUTF8 },
    { "Test_Label_DrawTextInGBK", Test_Label_DrawTextInGBK },
    { "Test_Label_DrawBarcode_UPCA", Test_Label_DrawBarcode_UPCA },
    { "Test_Label_DrawBarcode_UPCE", Test_Label_DrawBarcode_UPCE },
    { "Test_Label_DrawBarcode_EAN13", Test_Label_DrawBarcode_EAN13 },
    { "Test_Label_DrawBarcode_EAN8", Test_Label_DrawBarcode_EAN8 },
    { "Test_Label_DrawBarcode_CODE39", Test_Label_DrawBarcode_CODE39 },
    { "Test_Label_DrawBarcode_ITF", Test_Label_DrawBarcode_ITF },
    { "Test_Label_DrawBarcode_CODEBAR", Test_Label_DrawBarcode_CODEBAR },
    { "Test_Label_DrawBarcode_CODE93", Test_Label_DrawBarcode_CODE93 },
    { "Test_Label_DrawBarcode_CODE128", Test_Label_DrawBarcode_CODE128 },
    { "Test_Label_DrawQRCode", Test_Label_DrawQRCode },
    { "Test_Label_DrawPDF417Code", Test_Label_DrawPDF417Code },
    { "Test_Label_DrawLine", Test_Label_DrawLine },
    { "Test_Label_DrawRect", Test_Label_DrawRect },
    { "Test_Label_DrawBox", Test_Label_DrawBox },
    { "Test_Label_DrawImageFromFile", Test_Label_DrawImageFromFile },

};
size_t listCmdTestUnitSize = sizeof(listCmdTestUnit) / sizeof(CmdTestUnit);
