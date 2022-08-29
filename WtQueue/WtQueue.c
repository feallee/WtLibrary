#include <stdlib.h>
#include "WtQueue.h"

static struct Queue 
{
	Wt_Queue_Type* Buffer;
	size_t
};


void* Wt_Queue_Create(size_t count)
{
	 malloc()
}


unsigned char Wt_Queue_Push(void* queue, Wt_Queue_Type value);
Wt_Queue_Type Wt_Queue_Pop(void* queue);
void Wt_Queue_Dispose(void* queue)