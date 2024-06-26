#include <string.h>
#include "WtEntry.h"

WT_ENTRY_REGISTER(0, NULL, NULL);
WT_ENTRY_REGISTER(9, NULL, NULL);

int WtEntry_Execute(const char *category)
{
    int cnt = 0;
    for (const WtEntry_Type *b = &mWtEntry_0_NULL + 1; b < &mWtEntry_9_NULL; b++)
    {
        if (category)
        {
            if (b->Category)
            {
                if (strcmp(category, b->Category) == 0)
                {
                    if (b->Action)
                    {
                        b->Action();
                    }
                    cnt++;
                }
            }
        }
        else
        {
            if (b->Category == NULL)
            {
                if (b->Action)
                {
                    b->Action();
                }
                cnt++;
            }
        }
    }
    return cnt;
}