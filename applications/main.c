#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "WtVersion.h"
#include "WtEntryTest.h"
#include "WtCommandTest.h"
int main(void)
{
    printf("%s\n",WT_VERSION_FULL);
    WtEntryTest_Run();
    WtCommandTest_Run();
    return 0;
}

