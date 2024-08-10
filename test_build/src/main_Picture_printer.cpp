#include "cmdtestfunction.h"
#include "cmdtestutils.h"
#include "cmdtestunit.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>


// char to wchar_t conversition utility function
#include <cwchar>   // For mbstowcs
#include <clocale>  // For setlocale
#include <cstring>  // For strlen
wchar_t* convertToWideChar(const char* charStr) {
    // Determine the required length for the wide string
    std::size_t length = std::mbstowcs(nullptr, charStr, 0);
    if (length == static_cast<std::size_t>(-1)) {
        std::cerr << "Error: Invalid multibyte sequence encountered." << std::endl;
        return nullptr;
    }

    // Allocate memory for the wide character string
    wchar_t* wideStr = new wchar_t[length + 1];

    // Perform the conversion
    std::mbstowcs(wideStr, charStr, length + 1);

    return wideStr;
}





int main(int argc, char *argv[])
{
    /*
        argv[0] : This function
        argv[1] : Serial port name
        argv[2] : String to print
    */

    // Set the locale for the conversion to support the full character set
    std::setlocale(LC_ALL, "");
    const char* charStr = argv[2];
    wchar_t* wideStr = convertToWideChar(charStr);

    // check parameters
    // if (argc != 3) {
    //     std::cout << std::endl;
    //     ShowMessage("Usage: program port_name function_index");
    //     ShowMessage("Example: ./test /dev/usb/lp0 0");
    //     std::cout << std::endl;
    // }
    ShowMessage("\nPrinting function arguements.\n");
    for(int i = 0; i < argc; i++){
        std::cout << "** Argv[" << i << "]: " << argv[i] << std::endl; 
    }
    if(argc != 3){
        std::cout << std::endl;
        ShowMessage("***************************************************");
        ShowMessage("Invilad arguments. Exiting...");
        std::cout << std::endl;
        return 0;
    }


    // get parameters
    const char *port_name = argv[1];
    // if (argc >= 2) {
    //     port_name = argv[1];
    // }
    // int function_index = 0;
    // if (argc >= 3) {
    //     function_index = atoi(argv[2]);
    // }

    // show function list
    if (1) {
        ShowMessage("\r\nfunction list:\r\n");

        int i;
        for (i = 0; i < (int)listCmdTestUnitSize; ++i) {
            char message[100];
            sprintf(message, "%d %s", i, listCmdTestUnit[i].cmdTestDescription);
            ShowMessage(message);
        }

        ShowMessage("\r\n");
    }

    // open port
    void *h = 0;
    if (strstr(port_name, "/dev/usb/lp")) {
        h = CP_Port_OpenUsb(port_name, 1);
    } else if (strstr(port_name, "/dev/tty")) {
        h = CP_Port_OpenCom(port_name, 115200, CP_ComDataBits_8, CP_ComParity_NoParity, CP_ComStopBits_One, CP_ComFlowControl_None, 1);
    } else if (strstr(port_name, ".")) {
        h = CP_Port_OpenTcp(0, port_name, 9100, 5000, 1);
    }
    if (h == 0) {
        ShowMessage("Can not open port. you can use sudo to retry.");
        return 0;
    }


    // wchar_t strToPrint = *argv[2];
    // test function
    if (h) {

        Test_Page_DrawTextInGBK_AYA(h, wideStr);

        CP_Port_Close(h);
    }

    delete[] wideStr; // Clean up the allocated memory
    return 0;
}
