#include <stdio.h>
#include "WtCommand.h"
#include "WtCommandTest.h"

static void Command11(int32_t sender, void *parameter)
{
    printf("command11\n");
}
WT_COMMAND_REGISTER1("cmd1", Command11);

static void Command12(int32_t sender, void *parameter)
{
    printf("command12\n");
}
WT_COMMAND_REGISTER1("cmd1", Command12);

static void Command2(int32_t sender, void *parameter)
{
    printf("command2\n");
}
WT_COMMAND_REGISTER2("cmd2", Command2);

static void Command3(int32_t sender, void *parameter)
{
    printf("command3\n");
}
WT_COMMAND_REGISTER3("cmd3", Command3);

static void Command4(int32_t sender, void *parameter)
{
    printf("command4\n");
}
WT_COMMAND_REGISTER4("cmd4", Command4);

static void Command5(int32_t sender, void *parameter)
{
    printf("command5\n");
}
WT_COMMAND_REGISTER5("cmd5", Command5);

static void Command6(int32_t sender, void *parameter)
{
    printf("command6\n");
}
WT_COMMAND_REGISTER6("cmd6", Command6);

static void Command7(int32_t sender, void *parameter)
{
    printf("command7\n");
}
WT_COMMAND_REGISTER7("cmd7", Command7);

static void Command8(int32_t sender, void *parameter)
{
    printf("command8\n");
}
WT_COMMAND_REGISTER8("cmd8", Command8);

void WtCommandTest_Run(void)
{
    WtCommand_Execute(1, "cmd1", 0, NULL);
    WtCommand_Execute(2, "cmd2", 0, NULL);

    WtCommand_Execute(3, "cmd3", 0, NULL);
    WtCommand_Execute(4, "cmd4", 0, NULL);
    WtCommand_Execute(5, "cmd5", 0, NULL);
    WtCommand_Execute(6, "cmd6", 0, NULL);
    WtCommand_Execute(7, "cmd7", 0, NULL);
    WtCommand_Execute(8, "cmd8", 0, NULL);
}