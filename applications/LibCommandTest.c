#include <stdio.h>
#include "LibCommand.h"
#include "LibCommandTest.h"

static void Command11(int sender, void *parameter)
{
    printf("command11\n");
}
LIB_COMMAND_REGISTER1("cmd1", Command11);

static void Command12(int sender, void *parameter)
{
    printf("command12\n");
}
LIB_COMMAND_REGISTER1("cmd1", Command12);

static void Command2(int sender, void *parameter)
{
    printf("command2\n");
}
LIB_COMMAND_REGISTER2("cmd2", Command2);

static void Command3(int sender, void *parameter)
{
    printf("command3\n");
}
LIB_COMMAND_REGISTER3("cmd3", Command3);

static void Command4(int sender, void *parameter)
{
    printf("command4\n");
}
LIB_COMMAND_REGISTER4("cmd4", Command4);

static void Command5(int sender, void *parameter)
{
    printf("command5\n");
}
LIB_COMMAND_REGISTER5("cmd5", Command5);

static void Command6(int sender, void *parameter)
{
    printf("command6\n");
}
LIB_COMMAND_REGISTER6("cmd6", Command6);

static void Command7(int sender, void *parameter)
{
    printf("command7\n");
}
LIB_COMMAND_REGISTER7("cmd7", Command7);

static void Command8(int sender, void *parameter)
{
    printf("command8\n");
}
LIB_COMMAND_REGISTER8("cmd8", Command8);

void LibCommandTest_Run(void)
{
    LibCommand_Execute(1, "cmd1", 0, NULL);
    LibCommand_Execute(2, "cmd2", 0, NULL);

    LibCommand_Execute(3, "cmd3", 0, NULL);
    LibCommand_Execute(4, "cmd4", 0, NULL);
    LibCommand_Execute(5, "cmd5", 0, NULL);
    LibCommand_Execute(6, "cmd6", 0, NULL);
    LibCommand_Execute(7, "cmd7", 0, NULL);
    LibCommand_Execute(8, "cmd8", 0, NULL);
}