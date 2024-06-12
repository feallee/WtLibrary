#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "WtVersion.h"
#include "WtEntryTest.h"
int main(void)
{
    printf("%s\n",WT_VERSION_FULL);
    WtEntryTest_Run();

    return 0;
}

