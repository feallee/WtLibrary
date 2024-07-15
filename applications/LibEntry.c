#include <string.h>
#include "LibEntry.h"

LIB_ENTRY_REGISTER(0, NULL, NULL);
LIB_ENTRY_REGISTER(9, NULL, NULL);

int LibEntry_Execute(const char *category, void *parameter)
{
    int cnt = 0;
    if (category)
    {
        for (const LibEntry_Type *b = &mLibEntry_0_NULL + 1; b < &mLibEntry_9_NULL; b++)
        {
            if (b->Category)
            {
                if (strcmp(category, b->Category) == 0)
                {
                    if (b->Action)
                    {
                        b->Action(parameter);
                    }
                    cnt++;
                }
            }
        }
    }
    else
    {
        for (const LibEntry_Type *b = &mLibEntry_0_NULL + 1; b < &mLibEntry_9_NULL; b++)
        {
            if (b->Category == NULL)
            {
                if (b->Action)
                {
                    b->Action(parameter);
                }
                cnt++;
            }
        }
    }    
    return cnt;
}