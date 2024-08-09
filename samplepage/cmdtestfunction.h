#ifndef CMDTESTFUNCTION_H
#define CMDTESTFUNCTION_H

void Test_Pos_SampleTicket_58MM_1(void * h);
void Test_Pos_SampleTicket_58MM_2(void * h);
void Test_Pos_SampleTicket_80MM_1(void * h);
void Test_Page_SampleTicket_58mm_1(void * h);
void Test_Page_SampleTicket_80mm_1(void * h);
void Test_Label_SampleTicket_55x30_1(void * h);

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

void Test_Page_SetPageDrawDirection(void * h);
void Test_Page_DrawRect(void * h);
void Test_Page_DrawText(void * h);
void Test_Page_DrawTextInUTF8(void * h);
void Test_Page_DrawTextInGBK(void * h);
void Test_Page_DrawTextInBIG5(void * h);
void Test_Page_DrawTextInShiftJIS(void * h);
void Test_Page_DrawTextInEUCKR(void * h);
void Test_Page_DrawBarcode(void * h);
void Test_Page_DrawBarcode_CODE128(void * h);
void Test_Page_DrawQRCode(void * h);
void Test_Page_DrawRasterImageFromFile(void * h);

void Test_BlackMark_EnableBlackMarkMode(void * h);
void Test_BlackMark_DisableBlackMarkMode(void * h);
void Test_BlackMark_SetBlackMarkMaxFindLength(void * h);
void Test_BlackMark_FindNextBlackMark(void * h);
void Test_BlackMark_SetBlackMarkPaperPrintPosition(void * h);
void Test_BlackMark_SetBlackMarkPaperCutPosition(void * h);
void Test_BlackMark_PrintTextOnBlackMarkPaper(void * h);
void Test_BlackMark_FullCutBlackMarkPaper(void * h);
void Test_BlackMark_HalfCutBlackMarkPaper(void * h);

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

#endif // CMDTESTFUNCTION_H
