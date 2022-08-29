#ifndef __WT_QUEUE_H_
#define __WT_QUEUE_H_
#include <stddef.h>

typedef struct
{
	char Value;//此数据类型可以自定义。
}Wt_Queue_Type;

void* Wt_Queue_Create(size_t count);
unsigned char Wt_Queue_Push(void* queue, Wt_Queue_Type value);
Wt_Queue_Type Wt_Queue_Pop(void* queue);
void Wt_Queue_Dispose(void* queue)
#endif
