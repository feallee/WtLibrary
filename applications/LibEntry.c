#include <string.h>
#include "LibEntry.h"

LIB_ENTRY_REGISTER(0, NULL, NULL);
LIB_ENTRY_REGISTER(9, NULL, NULL);

int LibEntry_Execute(const char *category)
{
    int cnt = 0;
    for (const LibEntry_Type *b = &mLibEntry_0_NULL + 1; b < &mLibEntry_9_NULL; b++)
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