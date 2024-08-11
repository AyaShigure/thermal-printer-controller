#include "printerutilities.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

void PrintTextUTF8(void *h, wchar_t *input_str)
{
    CP_Pos_SetMultiByteMode(h);
    CP_Pos_SetMultiByteEncoding(h, CP_MultiByteEncoding_GBK);

    CP_Page_DrawTextInGBK(h, 0, 0, input_str);
    CP_Page_PrintPage(h);

    bool result = CP_Page_ExitPageMode(h);
    if (!result)
        ShowMessage("Write failed");
}


int main(int argc, char *argv[])
{
    /*
        argv[0] : This function
        argv[1] : Serial port name
        argv[2] : String to print
    */

    const char *port_name = argv[1];
    // Set the locale for the conversion to support the full character set
    std::setlocale(LC_ALL, "");
    const char* charStr = argv[2];
    wchar_t* wideStr = convertToWideChar(charStr);

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
    ShowMessage("***************************************************");
    ShowMessage("Some how command line calling this function does not work, but from python it works." );
    ShowMessage("Call this function only with python.");

    ShowMessage("***************************************************");

    // wchar_t strToPrint = *argv[2];
    // test function
    if (h) {
        int printDensity = 30; // 30 seems to be the best quality
        CP_Pos_SetPrintDensity(h, printDensity);
        PrintTextUTF8(h, wideStr);
        CP_Port_Close(h);
    }

    delete[] wideStr; // Clean up the allocated memory
    return 0;
}
