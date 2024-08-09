#ifndef CMDTESTFUNCTION_H
#define CMDTESTFUNCTION_H

void Test_Label_SampleTicket_55x30_1(void * h);

void Test_Port_Write(void * h);
void Test_Port_Read(void * h);
void Test_Port_ReadUntilByte(void * h);
void Test_Port_Available(void * h);
void Test_Port_SkipAvailable(void * h);
void Test_Port_IsConnectionValid(void * h);

void Test_Printer_GetPrinterInfo(void * h);
void Test_Printer_ClearPrinterBuffer(void * h);

bool Test_Pos_CheckPrinterStatus(void * h);
void Test_Pos_QueryPrintResult(void * h);

void Test_Pos_KickOutDrawer(void * h);
void Test_Pos_Beep(void * h);

void Test_Pos_PrintSelfTestPage(void * h);

void Test_Pos_ResetPrinter(void * h);
void Test_Pos_SetPrintSpeed_20(void * h);
void Test_Pos_SetPrintSpeed_50(void * h);
void Test_Pos_SetPrintSpeed_100(void * h);
void Test_Pos_SetPrintDensity_0(void * h);
void Test_Pos_SetPrintDensity_7(void * h);
void Test_Pos_SetPrintDensity_15(void * h);

void Test_Label_EnableLabelMode(void * h);
void Test_Label_DisableLabelMode(void * h);
void Test_Label_CalibrateLabel(void * h);
void Test_Label_FeedLabel(void * h);
void Test_Label_PageBegin_PagePrint(void * h);
void Test_Label_DrawText(void * h);
void Test_Label_DrawTextInUTF8(void * h);
void Test_Label_DrawTextInGBK(void * h);
void Test_Label_DrawTextInBIG5(void * h);
void Test_Label_DrawTextInShiftJIS(void * h);
void Test_Label_DrawTextInEUCKR(void * h);
void Test_Label_DrawTextInBytes(void * h);
void Test_Label_DrawBarcode_UPCA(void * h);
void Test_Label_DrawBarcode_UPCE(void * h);
void Test_Label_DrawBarcode_EAN13(void * h);
void Test_Label_DrawBarcode_EAN8(void * h);
void Test_Label_DrawBarcode_CODE39(void * h);
void Test_Label_DrawBarcode_ITF(void * h);
void Test_Label_DrawBarcode_CODEBAR(void * h);
void Test_Label_DrawBarcode_CODE93(void * h);
void Test_Label_DrawBarcode_CODE128(void * h);
void Test_Label_DrawQRCode(void * h);
void Test_Label_DrawQRCodeInUTF8(void * h);
void Test_Label_DrawQRCodeInBytes(void * h);
void Test_Label_DrawPDF417Code(void * h);
void Test_Label_DrawLine(void * h);
void Test_Label_DrawRect(void * h);
void Test_Label_DrawBox(void * h);
void Test_Label_DrawImageFromFile(void * h);

#endif // CMDTESTFUNCTION_H
