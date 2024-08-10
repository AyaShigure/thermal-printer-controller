#include "printerutilities.h"
#include "stdio.h"
#include <iostream>

void ShowMessage(const char *message)
{
    printf("%s\r\n", message);
}


// char to wchar_t conversition utility function
#include <cwchar>   // For mbstowcs
#include <clocale>  // For setlocale
#include <cstring>  // For strlen
wchar_t *convertToWideChar(const char *charStr) {
    // Determine the required length for the wide string
    std::size_t length = std::mbstowcs(nullptr, charStr, 0);
    if (length == static_cast<std::size_t>(-1)) {
        std::cerr << "Error: Invalid multibyte sequence encountered." << std::endl;
        return nullptr;
    }

    // Allocate memory for the wide character string
    wchar_t *wideStr = new wchar_t[length + 1];

    // Perform the conversion
    std::mbstowcs(wideStr, charStr, length + 1);

    return wideStr;
}


// char to int conversition utility function

#include <cstdlib> // For strtol
#include <cerrno>  // For errno
#include <climits> // For LONG_MAX and LONG_MIN
int convertToInt(const char* str) {
    errno = 0; // Reset errno before calling strtol
    char* endptr;
    long result = strtol(str, &endptr, 10);

    // Check for conversion errors
    if (endptr == str) {
        std::cerr << "Error: No digits were found in input." << std::endl;
        return 0; // Return a default value or handle the error appropriately
    } else if ((result == LONG_MAX || result == LONG_MIN) && errno == ERANGE) {
        std::cerr << "Error: Number out of range." << std::endl;
        return 0; // Return a default value or handle the error appropriately
    }

    // Check if the result fits in an int
    if (result > INT_MAX || result < INT_MIN) {
        std::cerr << "Error: Converted value out of int range." << std::endl;
        return 0; // Return a default value or handle the error appropriately
    }

    return static_cast<int>(result);
}