#include <stdio.h>
#include "WtEntry.h"
#include "WtEntryTest.h"

static void Entry11(int sender, void *parameter)
{
    printf("entry11(%d,%p)\n", sender, parameter);
}
WT_ENTRY_REGISTER1("entry1", Entry11);

static void Entry12(int sender, void *parameter)
{
    printf("entry12(%d,%p)\n", sender, parameter);
}
WT_ENTRY_REGISTER1("entry1", Entry12);

static void Entry2(int sender, void *parameter)
{
    printf("entry2(%d,%p)\n", sender, parameter);
}
WT_ENTRY_REGISTER2("entry2", Entry2);

static void Entry3(int sender, void *parameter)
{
    printf("entry3(%d,%p)\n", sender, parameter);
}
WT_ENTRY_REGISTER3("entry3", Entry3);

static void Entry4(int sender, void *parameter)
{
    printf("entry4(%d,%p)\n", sender, parameter);
}
WT_ENTRY_REGISTER4("entry4", Entry4);

static void Entry5(int sender, void *parameter)
{
    printf("entry5(%d,%p)\n", sender, parameter);
}
WT_ENTRY_REGISTER5("entry5", Entry5);

static void Entry6(int sender, void *parameter)
{
    printf("entry6(%d,%p)\n", sender, parameter);
}
WT_ENTRY_REGISTER6("entry6", Entry6);

static void Entry7(int sender, void *parameter)
{
    printf("entry7(%d,%p)\n", sender, parameter);
}
WT_ENTRY_REGISTER7("entry7", Entry7);

static void Entry81(int sender, void *parameter)
{
    printf("entry81(%d,%p)\n", sender, parameter);
}
WT_ENTRY_REGISTER8("entry81", Entry81);

static void Entry82(int sender, void *parameter)
{
    printf("entry82(%d,%p)\n", sender, parameter);
}
WT_ENTRY_REGISTER8("entry82", Entry82); 

static void Entry83(int sender, void *parameter)
{
    printf("entry83(%d,%p)\n", sender, parameter);
}
WT_ENTRY_REGISTER8("entry83", Entry83); 


void WtEntryTest_Run(void)
{
    WtEntry_Execute(WT_ENTRY_GROUP_1, "entry1", WT_ENTRY_SENDER_CONSOLE, NULL);
    WtEntry_Execute(WT_ENTRY_GROUP_2, "entry2", WT_ENTRY_SENDER_CONSOLE, NULL);
    WtEntry_Execute(WT_ENTRY_GROUP_3, "entry3", WT_ENTRY_SENDER_CONSOLE, NULL);
    WtEntry_Execute(WT_ENTRY_GROUP_4, "entry4", WT_ENTRY_SENDER_CONSOLE, NULL);
    WtEntry_Execute(WT_ENTRY_GROUP_5, "entry5", WT_ENTRY_SENDER_CONSOLE, NULL);
    WtEntry_Execute(WT_ENTRY_GROUP_6, "entry6", WT_ENTRY_SENDER_CONSOLE, NULL);
    WtEntry_Execute(WT_ENTRY_GROUP_7, "entry7", WT_ENTRY_SENDER_CONSOLE, NULL);
    WtEntry_Execute(WT_ENTRY_GROUP_8, NULL, WT_ENTRY_SENDER_CONSOLE, NULL);
}