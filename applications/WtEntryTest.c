#include <stdio.h>
#include "WtEntry.h"
#include "WtEntryTest.h"

static void Entry1(void)
{
    printf("entry1\n");
}
WT_ENTRY_REGISTER1("entry", Entry1);

static void Entry2(void)
{
    printf("entry2\n");
}
WT_ENTRY_REGISTER2("entry", Entry2);

static void Entry3(void)
{
    printf("entry3\n");
}
WT_ENTRY_REGISTER3("entry", Entry3);

static void Entry4(void)
{
    printf("entry4\n");
}
WT_ENTRY_REGISTER4("entry", Entry4);

static void Entry5(void)
{
    printf("entry5\n");
}
WT_ENTRY_REGISTER5("entry", Entry5);

static void Entry6(void)
{
    printf("entry6\n");
}
WT_ENTRY_REGISTER6("entry", Entry6);

static void Entry7(void)
{
    printf("entry7\n");
}
WT_ENTRY_REGISTER7("entry", Entry7);

static void Entry8(void)
{
    printf("entry8\n");
}
WT_ENTRY_REGISTER8("entry", Entry8);

static void Entry0(void)    
{
    printf("entry0\n");
}
WT_ENTRY_REGISTER8("entry0", Entry0);
void WtEntryTest_Run(void)
{
    WtEntry_Execute("entry0");
    WtEntry_Execute("entry");
}