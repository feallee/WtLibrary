#include <string.h>
#include "WtEntry.h"
__attribute__((used, __section__(".WtEntry.10"))) const static WtEntry_Type mWtEntry1;
__attribute__((used, __section__(".WtEntry.20"))) const static WtEntry_Type mWtEntry2;
__attribute__((used, __section__(".WtEntry.30"))) const static WtEntry_Type mWtEntry3;
__attribute__((used, __section__(".WtEntry.40"))) const static WtEntry_Type mWtEntry4;
__attribute__((used, __section__(".WtEntry.50"))) const static WtEntry_Type mWtEntry5;
__attribute__((used, __section__(".WtEntry.60"))) const static WtEntry_Type mWtEntry6;
__attribute__((used, __section__(".WtEntry.70"))) const static WtEntry_Type mWtEntry7;
__attribute__((used, __section__(".WtEntry.80"))) const static WtEntry_Type mWtEntry8;
__attribute__((used, __section__(".WtEntry.90"))) const static WtEntry_Type mWtEntry9;

int WtEntry_Execute(WtEntry_GroupType group, const char *name, uint32_t executer, void *parameter)
{
    int cnt = 0;
    const WtEntry_Type *b;
    const WtEntry_Type *e;
    switch (group)
    {
    case WT_ENTRY_GROUP_1:
    {
        b = &mWtEntry1 + 1;
        e = &mWtEntry2;
    }
    break;
    case WT_ENTRY_GROUP_2:
    {
        b = &mWtEntry2 + 1;
        e = &mWtEntry3;
    }
    break;
    case WT_ENTRY_GROUP_3:
    {
        b = &mWtEntry3 + 1;
        e = &mWtEntry4;
    }
    break;
    case WT_ENTRY_GROUP_4:
    {
        b = &mWtEntry4 + 1;
        e = &mWtEntry5;
    }
    break;
    case WT_ENTRY_GROUP_5:
    {
        b = &mWtEntry5 + 1;
        e = &mWtEntry6;
    }
    break;
    case WT_ENTRY_GROUP_6:
    {
        b = &mWtEntry6 + 1;
        e = &mWtEntry7;
    }
    break;
    case WT_ENTRY_GROUP_7:
    {
        b = &mWtEntry7 + 1;
        e = &mWtEntry8;
    }
    break;
    case WT_ENTRY_GROUP_8:
    {
        b = &mWtEntry8 + 1;
        e = &mWtEntry9;
    }
    break;
    default:
    {
        b = e = NULL;
    }
    break;
    }
    while (b < e)
    {
        if (name)
        {
            if (b->Name)
            {
                if (strcmp(name, b->Name) == 0)
                {
                    if (b->Action)
                    {
                        b->Action(executer, parameter);
                    }
                    cnt++;
                }
            }
        }
        else
        {
            if (b->Action)
            {
                b->Action(executer, parameter);
            }
            cnt++;
        }
        b++;
    }
    return cnt;
}