#include <stdio.h>
#include "LibEntry.h"
#include "LibEntryTest.h"

static void Entry1(void *parameter)
{
    printf("entry1\n");
}
LIB_ENTRY_REGISTER1("entry", Entry1);

static void Entry2(void *parameter)
{
    printf("entry2\n");
}
LIB_ENTRY_REGISTER2("entry", Entry2);

static void Entry3(void *parameter)
{
    printf("entry3\n");
}
LIB_ENTRY_REGISTER3("entry", Entry3);

static void Entry4(void *parameter)
{
    printf("entry4\n");
}
LIB_ENTRY_REGISTER4("entry", Entry4);

static void Entry5(void *parameter)
{
    printf("entry5\n");
}
LIB_ENTRY_REGISTER5("entry", Entry5);

static void Entry6(void *parameter)
{
    printf("entry6\n");
}
LIB_ENTRY_REGISTER6("entry", Entry6);

static void Entry7(void *parameter)
{
    printf("entry7\n");
}
LIB_ENTRY_REGISTER7("entry", Entry7);

static void Entry8(void *parameter)
{
    printf("entry8\n");
}
LIB_ENTRY_REGISTER8("entry", Entry8);

static void Entry0(void *parameter)    
{
    printf("entry0\n");
}
LIB_ENTRY_REGISTER8("entry0", Entry0);
void LibEntryTest_Run(void)
{
    LibEntry_Execute("entry0",NULL);
    LibEntry_Execute("entry",NULL);
}