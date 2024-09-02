#include <stdio.h>
#include "Application.h"

static void OnCommand11(Application_CommandSenderType sender, void *parameter)
{
    printf("AppTest is Command11\n");
}
APPLICATION_REGISTER_COMMAND_1(OnCommand11, "cmd11");

static void OnCommand12(Application_CommandSenderType sender, void *parameter)
{
    printf("AppTest is Command12\n");
}
APPLICATION_REGISTER_COMMAND_1(OnCommand12, "cmd12");

static void OnCommand2(Application_CommandSenderType sender, void *parameter)
{
    printf("AppTest is Command2\n");
}
APPLICATION_REGISTER_COMMAND_2(OnCommand2, "cmd2");

static void OnCommand3(Application_CommandSenderType sender, void *parameter)
{
    printf("AppTest is Command3\n");
}
APPLICATION_REGISTER_COMMAND_3(OnCommand3, "cmd3");

static void OnCommand4(Application_CommandSenderType sender, void *parameter)
{
    printf("AppTest is Command4\n");
}
APPLICATION_REGISTER_COMMAND_4(OnCommand4, "cmd4");

static void OnLoad1(void *parameter)
{    
    printf("Initialize the console here.\n");
    printf("Load application settings here.\n");
    printf("%u,%s,%s\n", APPLICATION_VERSION_NUMBER, APPLICATION_VERSION_TINY, APPLICATION_VERSION_FULL);
    Application_Execute(1, "cmd11", APPLICATION_COMMAND_SENDER_CONSOLE, NULL);
    Application_Execute(1, "cmd12", APPLICATION_COMMAND_SENDER_CONSOLE, NULL);
    Application_Execute(2, "cmd2", APPLICATION_COMMAND_SENDER_CONSOLE, NULL);
    Application_Execute(3, "cmd3", APPLICATION_COMMAND_SENDER_CONSOLE, NULL);
    Application_Execute(4, "cmd4", APPLICATION_COMMAND_SENDER_CONSOLE, NULL);
    printf("AppTest is loaded1\n");
}
APPLICATION_REGISTER_ENTRY_1(OnLoad1, APPLICATION_ENTRY_PROCEDURE_LOAD);

static void OnLoad2(void *parameter)
{
    printf("AppTest is loaded2\n");
}
APPLICATION_REGISTER_ENTRY_2(OnLoad2, APPLICATION_ENTRY_PROCEDURE_LOAD);

static void OnLoad3(void *parameter)
{
    printf("AppTest is loaded3\n");
}
APPLICATION_REGISTER_ENTRY_3(OnLoad3, APPLICATION_ENTRY_PROCEDURE_LOAD);

static void OnLoad4(void *parameter)
{
    printf("AppTest is loaded4\n");
}
APPLICATION_REGISTER_ENTRY_4(OnLoad4, APPLICATION_ENTRY_PROCEDURE_LOAD);

static void OnLoad5(void *parameter)
{
    printf("AppTest is loaded5\n");
}
APPLICATION_REGISTER_ENTRY_5(OnLoad5, APPLICATION_ENTRY_PROCEDURE_LOAD);

static void OnLoad6(void *parameter)
{
    printf("AppTest is loaded6\n");
}
APPLICATION_REGISTER_ENTRY_6(OnLoad6, APPLICATION_ENTRY_PROCEDURE_LOAD);

static void OnLoad7(void *parameter)
{
    printf("AppTest is loaded7\n");
}
APPLICATION_REGISTER_ENTRY_7(OnLoad7, APPLICATION_ENTRY_PROCEDURE_LOAD);

static void OnLoad8(void *parameter)
{
    printf("AppTest is loaded8\n");
}
APPLICATION_REGISTER_ENTRY_8(OnLoad8, APPLICATION_ENTRY_PROCEDURE_LOAD);

static void OnWORK1(void *parameter)
{
    printf("AppTest is WORKed1\n");
}
APPLICATION_REGISTER_ENTRY_1(OnWORK1, APPLICATION_ENTRY_PROCEDURE_WORK);

static void OnWORK2(void *parameter)
{
    printf("AppTest is WORKed2\n");
}
APPLICATION_REGISTER_ENTRY_2(OnWORK2, APPLICATION_ENTRY_PROCEDURE_WORK);

static void OnWORK3(void *parameter)
{
    printf("AppTest is WORKed3\n");
}
APPLICATION_REGISTER_ENTRY_3(OnWORK3, APPLICATION_ENTRY_PROCEDURE_WORK);

static void OnWORK4(void *parameter)
{
    printf("AppTest is WORKed4\n");
}
APPLICATION_REGISTER_ENTRY_4(OnWORK4, APPLICATION_ENTRY_PROCEDURE_WORK);

static void OnWORK5(void *parameter)
{
    printf("AppTest is WORKed5\n");
}
APPLICATION_REGISTER_ENTRY_5(OnWORK5, APPLICATION_ENTRY_PROCEDURE_WORK);

static void OnWORK6(void *parameter)
{
    printf("AppTest is WORKed6\n");
}
APPLICATION_REGISTER_ENTRY_6(OnWORK6, APPLICATION_ENTRY_PROCEDURE_WORK);

static void OnWORK7(void *parameter)
{
    printf("AppTest is WORKed7\n");
}
APPLICATION_REGISTER_ENTRY_7(OnWORK7, APPLICATION_ENTRY_PROCEDURE_WORK);

static void OnWORK8(void *parameter)
{
    printf("AppTest is WORKed8\n");
}
APPLICATION_REGISTER_ENTRY_8(OnWORK8, APPLICATION_ENTRY_PROCEDURE_WORK);

static void OnCHECK1(void *parameter)
{
    printf("AppTest is CHECKed1\n");
}
APPLICATION_REGISTER_ENTRY_1(OnCHECK1, APPLICATION_ENTRY_PROCEDURE_CHECK);

static void OnCHECK2(void *parameter)
{
    printf("AppTest is CHECKed2\n");
}
APPLICATION_REGISTER_ENTRY_2(OnCHECK2, APPLICATION_ENTRY_PROCEDURE_CHECK);

static void OnCHECK3(void *parameter)
{
    printf("AppTest is CHECKed3\n");
}
APPLICATION_REGISTER_ENTRY_3(OnCHECK3, APPLICATION_ENTRY_PROCEDURE_CHECK);

static void OnCHECK4(void *parameter)
{
    printf("AppTest is CHECKed4\n");
}
APPLICATION_REGISTER_ENTRY_4(OnCHECK4, APPLICATION_ENTRY_PROCEDURE_CHECK);

static void OnCHECK5(void *parameter)
{
    printf("AppTest is CHECKed5\n");
}
APPLICATION_REGISTER_ENTRY_5(OnCHECK5, APPLICATION_ENTRY_PROCEDURE_CHECK);

static void OnCHECK6(void *parameter)
{
    printf("AppTest is CHECKed6\n");
}
APPLICATION_REGISTER_ENTRY_6(OnCHECK6, APPLICATION_ENTRY_PROCEDURE_CHECK);

static void OnCHECK7(void *parameter)
{
    printf("AppTest is CHECKed7\n");
}
APPLICATION_REGISTER_ENTRY_7(OnCHECK7, APPLICATION_ENTRY_PROCEDURE_CHECK);

static void OnCHECK8(void *parameter)
{
    printf("AppTest is CHECKed8\n");
}
APPLICATION_REGISTER_ENTRY_8(OnCHECK8, APPLICATION_ENTRY_PROCEDURE_CHECK);

static void OnCWAKEUP1(void *parameter)
{
    printf("AppTest is CWAKEUPed1\n");
}
APPLICATION_REGISTER_ENTRY_1(OnCWAKEUP1, APPLICATION_ENTRY_PROCEDURE_WAKEUP);

static void OnCWAKEUP2(void *parameter)
{
    printf("AppTest is CWAKEUPed2\n");
}
APPLICATION_REGISTER_ENTRY_2(OnCWAKEUP2, APPLICATION_ENTRY_PROCEDURE_WAKEUP);

static void OnCWAKEUP3(void *parameter)
{
    printf("AppTest is CWAKEUPed3\n");
}
APPLICATION_REGISTER_ENTRY_3(OnCWAKEUP3, APPLICATION_ENTRY_PROCEDURE_WAKEUP);

static void OnCWAKEUP4(void *parameter)
{
    printf("AppTest is CWAKEUPed4\n");
}
APPLICATION_REGISTER_ENTRY_4(OnCWAKEUP4, APPLICATION_ENTRY_PROCEDURE_WAKEUP);

static void OnCWAKEUP5(void *parameter)
{
    printf("AppTest is CWAKEUPed5\n");
}
APPLICATION_REGISTER_ENTRY_5(OnCWAKEUP5, APPLICATION_ENTRY_PROCEDURE_WAKEUP);

static void OnCWAKEUP6(void *parameter)
{
    printf("AppTest is CWAKEUPed6\n");
}
APPLICATION_REGISTER_ENTRY_6(OnCWAKEUP6, APPLICATION_ENTRY_PROCEDURE_WAKEUP);

static void OnCWAKEUP7(void *parameter)
{
    printf("AppTest is CWAKEUPed7\n");
}
APPLICATION_REGISTER_ENTRY_7(OnCWAKEUP7, APPLICATION_ENTRY_PROCEDURE_WAKEUP);

static void OnCWAKEUP8(void *parameter)
{
    printf("AppTest is CWAKEUPed8\n");
}
APPLICATION_REGISTER_ENTRY_8(OnCWAKEUP8, APPLICATION_ENTRY_PROCEDURE_WAKEUP);

static void OnSLEEP1(void *parameter)
{
    printf("AppTest is SLEEPed1\n");
}
APPLICATION_REGISTER_ENTRY_1(OnSLEEP1, APPLICATION_ENTRY_PROCEDURE_SLEEP);

static void OnSLEEP2(void *parameter)
{
    printf("AppTest is SLEEPed2\n");
}
APPLICATION_REGISTER_ENTRY_2(OnSLEEP2, APPLICATION_ENTRY_PROCEDURE_SLEEP);

static void OnSLEEP3(void *parameter)
{
    printf("AppTest is SLEEPed3\n");
}
APPLICATION_REGISTER_ENTRY_3(OnSLEEP3, APPLICATION_ENTRY_PROCEDURE_SLEEP);

static void OnSLEEP4(void *parameter)
{
    printf("AppTest is SLEEPed4\n");
}
APPLICATION_REGISTER_ENTRY_4(OnSLEEP4, APPLICATION_ENTRY_PROCEDURE_SLEEP);

static void OnSLEEP5(void *parameter)
{
    printf("AppTest is SLEEPed5\n");
}
APPLICATION_REGISTER_ENTRY_5(OnSLEEP5, APPLICATION_ENTRY_PROCEDURE_SLEEP);

static void OnSLEEP6(void *parameter)
{
    printf("AppTest is SLEEPed6\n");
}
APPLICATION_REGISTER_ENTRY_6(OnSLEEP6, APPLICATION_ENTRY_PROCEDURE_SLEEP);

static void OnSLEEP7(void *parameter)
{
    printf("AppTest is SLEEPed7\n");
}
APPLICATION_REGISTER_ENTRY_7(OnSLEEP7, APPLICATION_ENTRY_PROCEDURE_SLEEP);

static void OnSLEEP8(void *parameter)
{
    printf("AppTest is SLEEPed8\n");
}
APPLICATION_REGISTER_ENTRY_8(OnSLEEP8, APPLICATION_ENTRY_PROCEDURE_SLEEP);
