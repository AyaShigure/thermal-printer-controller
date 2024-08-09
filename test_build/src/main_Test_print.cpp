#include "cmdtestfunction.h"
#include "cmdtestutils.h"
#include "cmdtestunit.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    // check parameters
    if (argc != 3) {
        ShowMessage("Usage: program port_name function_index");
        ShowMessage("Example: ./test /dev/usb/lp0 0");
    }

    // get parameters
    const char *port_name = "/dev/usb/lp0";
    if (argc >= 2) {
        port_name = argv[1];
    }
    int function_index = 0;
    if (argc >= 3) {
        function_index = atoi(argv[2]);
    }

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

    // test function
    if (h) {
        if ((function_index >= 0) && (function_index < (int)listCmdTestUnitSize)) {
            ShowMessage(listCmdTestUnit[function_index].cmdTestDescription);
            listCmdTestUnit[function_index].cmdTestFunction(h);
        }
        CP_Port_Close(h);
    }

    return 0;
}
