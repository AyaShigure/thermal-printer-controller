#include "printerutilities.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

// Print .bmp image
void PrintRasterImage(void *h, wchar_t *imagePath)
{
    CP_Page_SelectPageModeEx(h, 200, 200, 0, 0, 384, 600);
    CP_Page_DrawBox(h, 0, 0, 384, 600, 2, 1);
    CP_Page_DrawRasterImageFromFile(h, 0, 0, 0, 0, imagePath, CP_ImageBinarizationMethod_Dithering);
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
        argv[2] : Absolute path to the target image
    */
    const char *port_name = argv[1];
    const char *imagePath = argv[2];

    ShowMessage("\nPrinting function arguements.\n");
    for(int i = 0; i < argc; i++){
        std::cout << "** Argv[" << i << "]: " << argv[i] << std::endl; 
    }
    if(argc != 3){
        std::cout << std::endl;
        ShowMessage("***************************************************");
        ShowMessage("Invilad number of arguments. Exiting...");
        std::cout << std::endl;
        return 0;
    }

    // Open port
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

    // Execute the print
    if (h) {
        PrintRasterImage(h, imagePath);
        CP_Port_Close(h);
    }
    return 0;
}
