#include <string.h>
#include "WtCommand.h"

WT_COMMAND_REGISTER(10, NULL, NULL);
WT_COMMAND_REGISTER(20, NULL, NULL);
WT_COMMAND_REGISTER(30, NULL, NULL);
WT_COMMAND_REGISTER(40, NULL, NULL);
WT_COMMAND_REGISTER(50, NULL, NULL);
WT_COMMAND_REGISTER(60, NULL, NULL);
WT_COMMAND_REGISTER(70, NULL, NULL);
WT_COMMAND_REGISTER(80, NULL, NULL);
WT_COMMAND_REGISTER(90, NULL, NULL);

int WtCommand_Execute(uint8_t group, const char *name, int32_t sender, void *parameter)
{
    int cnt = 0;
    const WtCommand_Type *b;
    const WtCommand_Type *e;
    if (group == 1)
    {
        b = &mWtCommand_10_NULL;
        e = &mWtCommand_20_NULL;
    }
    else if (group == 2)
    {
        b = &mWtCommand_20_NULL;
        e = &mWtCommand_30_NULL;
    }
    else if (group == 3)
    {
        b = &mWtCommand_30_NULL;
        e = &mWtCommand_40_NULL;
    }
    else if (group == 4)
    {
        b = &mWtCommand_40_NULL;
        e = &mWtCommand_50_NULL;
    }
    else if (group == 5)
    {
        b = &mWtCommand_50_NULL;
        e = &mWtCommand_60_NULL;
    }
    else if (group == 6)
    {
        b = &mWtCommand_60_NULL;
        e = &mWtCommand_70_NULL;
    }
    else if (group == 7)
    {
        b = &mWtCommand_70_NULL;
        e = &mWtCommand_80_NULL;
    }
    else if (group == 8)
    {
        b = &mWtCommand_80_NULL;
        e = &mWtCommand_90_NULL;
    }
    else
    {
        b = e = NULL;
    }

    while (++b < e)
    {
        if (name)
        {
            if (b->Name)
            {
                if (strcmp(name, b->Name) == 0)
                {
                    if (b->Action)
                    {
                        b->Action(sender, parameter);
                    }
                    cnt++;
                }
            }
        }
        else
        {

            if (b->Name == NULL)
            {
                if (b->Action)
                {
                    b->Action(sender, parameter);
                }
                cnt++;
            }
        }
    }
    return cnt;
}