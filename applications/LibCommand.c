#include <string.h>
#include "LibCommand.h"

LIB_COMMAND_REGISTER(10, NULL, NULL);
LIB_COMMAND_REGISTER(20, NULL, NULL);
LIB_COMMAND_REGISTER(30, NULL, NULL);
LIB_COMMAND_REGISTER(40, NULL, NULL);
LIB_COMMAND_REGISTER(50, NULL, NULL);
LIB_COMMAND_REGISTER(60, NULL, NULL);
LIB_COMMAND_REGISTER(70, NULL, NULL);
LIB_COMMAND_REGISTER(80, NULL, NULL);
LIB_COMMAND_REGISTER(90, NULL, NULL);

int LibCommand_Execute(uint8_t group, const char *name, int sender, void *parameter)
{
    int cnt = 0;
    const LibCommand_Type *b;
    const LibCommand_Type *e;
    if (group == 1)
    {
        b = &mLibCommand_10_NULL;
        e = &mLibCommand_20_NULL;
    }
    else if (group == 2)
    {
        b = &mLibCommand_20_NULL;
        e = &mLibCommand_30_NULL;
    }
    else if (group == 3)
    {
        b = &mLibCommand_30_NULL;
        e = &mLibCommand_40_NULL;
    }
    else if (group == 4)
    {
        b = &mLibCommand_40_NULL;
        e = &mLibCommand_50_NULL;
    }
    else if (group == 5)
    {
        b = &mLibCommand_50_NULL;
        e = &mLibCommand_60_NULL;
    }
    else if (group == 6)
    {
        b = &mLibCommand_60_NULL;
        e = &mLibCommand_70_NULL;
    }
    else if (group == 7)
    {
        b = &mLibCommand_70_NULL;
        e = &mLibCommand_80_NULL;
    }
    else if (group == 8)
    {
        b = &mLibCommand_80_NULL;
        e = &mLibCommand_90_NULL;
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