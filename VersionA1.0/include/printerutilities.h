#ifndef PRINTERUTILITIES_H
#define PRINTERUTILITIES_H

#include "autoreplyprint.h"

void ShowMessage(const char *message);
wchar_t *convertToWideChar(const char *charStr);
int convertToInt(const char* str);

#endif // PRINTERUTILITIES_H
