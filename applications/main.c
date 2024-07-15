#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "AppVersion.h"
#include "LibEntryTest.h"
#include "LibCommandTest.h"
#include "LibMealyTest.h"
#include "LibCheckTest.h"
int main(void)
{
    printf("%s\n", APP_VERSION_FULL);
    LibEntryTest_Run();
    LibCommandTest_Run();
    LibMealyTest_Run();
    LibCheckTest_Run();
    return 0;
}
