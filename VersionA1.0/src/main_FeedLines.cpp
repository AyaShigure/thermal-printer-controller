#include "printerutilities.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

// Feed and cut
int main(int argc, char *argv[])
{
    /*
        argv[0] : This function
        argv[1] : Serial port name
        argv[2] : Feed lines number
    */

    ShowMessage("\nPrinting function arguements.\n");
    for(int i = 0; i < argc; i++){
        std::cout << "** Argv[" << i << "]: " << argv[i] << std::endl; 
    }

    if(argc != 3){
        std::cout << std::endl;
        ShowMessage("***************************************************");
        ShowMessage("Invilad arguments. Exiting...(Double check the arguments passed in.)");
        std::cout << std::endl;
        return 0;
    }

    const char *port_name = argv[1];
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

    int nFeedLines = convertToInt(argv[2]);
    // Send cut paper command
    if (h) {
        CP_Pos_FeedLine(h, nFeedLines);
        CP_Port_Close(h);
    }

    return 0;
}
