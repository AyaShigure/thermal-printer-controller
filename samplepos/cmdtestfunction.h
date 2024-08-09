#ifndef CMDTESTFUNCTION_H
#define CMDTESTFUNCTION_H

void Test_Pos_SampleTicket_58MM_1(void * h);
void Test_Pos_SampleTicket_58MM_2(void * h);
void Test_Pos_SampleTicket_80MM_1(void * h);

void Test_Port_Write(void * h);
void Test_Port_Read(void * h);
void Test_Port_Available(void * h);
void Test_Port_SkipAvailable(void * h);
void Test_Port_IsConnectionValid(void * h);

void Test_Printer_GetPrinterInfo(void * h);
void Test_Printer_ClearPrinterBuffer(void * h);

bool Test_Pos_CheckPrinterStatus(void * h);
void Test_Pos_QueryPrintResult(void * h);

void Test_Pos_KickOutDrawer(void * h);
void Test_Pos_Beep(void * h);
void Test_Pos_FeedAndHalfCutPaper(void * h);
void Test_Pos_FullCutPaper(void * h);
void Test_Pos_HalfCutPaper(void * h);
void Test_Pos_Feed(void * h);

void Test_Pos_PrintSelfTestPage(void * h);
void Test_Pos_PrintText(void * h);
void Test_Pos_PrintTextInUTF8(void * h);
void Test_Pos_PrintTextInGBK(void * h);
void Test_Pos_PrintTextInBIG5(void * h);
void Test_Pos_PrintTextInShiftJIS(void * h);
void Test_Pos_PrintTextInEUCKR(void * h);

void Test_Pos_PrintBarcode_UPCA(void * h);
void Test_Pos_PrintBarcode_UPCE(void * h);
void Test_Pos_PrintBarcode_EAN13(void * h);
void Test_Pos_PrintBarcode_EAN8(void * h);
void Test_Pos_PrintBarcode_CODE39(void * h);
void Test_Pos_PrintBarcode_ITF(void * h);
void Test_Pos_PrintBarcode_CODEBAR(void * h);
void Test_Pos_PrintBarcode_CODE93(void * h);
void Test_Pos_PrintBarcode_CODE128(void * h);

void Test_Pos_PrintQRCode(void * h);
void Test_Pos_PrintQRCodeUseEpsonCmd(void * h);

void Test_Pos_PrintRasterImageFromFile(void * h);

void Test_Pos_PrintHorizontalLine(void * h);
void Test_Pos_PrintHorizontalLineSpecifyThickness(void * h);
void Test_Pos_PrintMultipleHorizontalLinesAtOneRow(void * h);

void Test_Pos_ResetPrinter(void * h);
void Test_Pos_SetPrintSpeed_20(void * h);
void Test_Pos_SetPrintSpeed_50(void * h);
void Test_Pos_SetPrintSpeed_100(void * h);
void Test_Pos_SetPrintDensity_0(void * h);
void Test_Pos_SetPrintDensity_7(void * h);
void Test_Pos_SetPrintDensity_15(void * h);
void Test_Pos_SetSingleByteMode(void * h);
void Test_Pos_SetMultiByteMode(void * h);

void Test_Pos_SetMovementUnit(void * h);
void Test_Pos_SetPrintAreaLeftMargin(void * h);
void Test_Pos_SetPrintAreaWidth(void * h);
void Test_Pos_SetPrintPosition(void * h);
void Test_Pos_SetAlignment(void * h);
void Test_Pos_SetTextScale(void * h);
void Test_Pos_SetAsciiTextFontType(void * h);
void Test_Pos_SetTextBold(void * h);
void Test_Pos_SetTextUnderline(void * h);
void Test_Pos_SetTextUpsideDown(void * h);
void Test_Pos_SetTextWhiteOnBlack(void * h);
void Test_Pos_SetTextRotate(void * h);
void Test_Pos_SetTextLineHeight(void * h);
void Test_Pos_SetAsciiTextCharRightSpacing(void * h);
void Test_Pos_SetKanjiTextCharSpacing(void * h);

#endif // CMDTESTFUNCTION_H
