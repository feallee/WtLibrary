#include <stdlib.h>
#include <stddef.h>
#include "WtButton.h"

static struct Node
{
	unsigned char HoldTicks;
	unsigned char RepeatTicks;
	WtButton_GetValue GetValue;
	WtButton_Callback Callback;

	unsigned char Time;
	unsigned char HoldCount;
	unsigned char RepeatCount;

	unsigned char State;

	struct Node* Next;
}*Head = NULL;

static void ReadyState(struct Node* node)
{
	if (node->GetValue())
	{
		node->State = 1;
	}
}

static void DownAcceptState(struct Node* node)
{
	if (node->GetValue())
	{
		node->HoldCount = 0;
		node->Time = 0;
		node->Callback(WtButton_Down, 1);
		node->State = 2;
	}
	else
	{
		node->RepeatCount = 0;
		node->State = 0;
	}
}

static void HoldState(struct Node* node)
{
	node->Time++;
	if (node->GetValue())
	{
		if (node->Time % node->HoldTicks == 0)
		{
			node->Callback(WtButton_Hold, node->HoldCount++);
		}
	}
	else
	{
		node->State = 3;
	}
}
static void UpAcceptState(struct Node* node)
{
	if (node->GetValue())
	{
		if (node->Time++ % node->HoldTicks == 0)
		{
			node->Callback(WtButton_Hold, node->HoldCount++);
		}
		node->State = 2;
	}
	else
	{
		node->Time = 0;
		node->Callback(WtButton_Up, 1);
		node->State = 4;
	}
}

static void WaitState(struct Node* node)
{
	if (node->Time++ < node->RepeatTicks)
	{
		if (node->GetValue())
		{
			if (node->RepeatCount)
			{
				node->Callback(WtButton_Repeat, node->RepeatCount);
			}
			node->RepeatCount++;
		}
	}
	else
	{
		node->RepeatCount = 0;
		node->State = 0;
	}
}

unsigned char WtButton_Regist(unsigned char holdTicks, unsigned char repeatTicks, WtButton_GetValue getValue, WtButton_Callback callback)
{
	unsigned char r = 0;
	struct Node* node;
	if (node = malloc(sizeof(struct Node)))
	{
		if (holdTicks == 0) { holdTicks = 10; }
		if (repeatTicks == 0) { holdTicks = 50; }
		node->HoldTicks = holdTicks;
		node->RepeatTicks = repeatTicks;
		node->GetValue = getValue;
		node->Callback = callback;

		node->Time = 0;
		node->HoldCount = 0;
		node->RepeatCount = 0;

		node->State = 0;

		node->Next = Head;
		Head = node;
	}
	return r;
}

void WtButton_Scan(void)
{
	struct Node* node;
	node = Head;
	while (node)
	{
		if (node->GetValue && node->Callback)
		{
			if (node->State == 0)
			{
				ReadyState(node);
			}
			else if (node->State == 1)
			{
				DownAcceptState(node);
			}
			else if (node->State == 2)
			{
				HoldState(node);
			}
			else if (node->State == 3)
			{
				UpAcceptState(node);
			}
			else if (node->State == 4)
			{
				WaitState(node);
			}
		}
		node = node->Next;
	}
}

void WtButton_Dispose(void)
{
	struct Node* node;
	while (Head)
	{
		node = Head->Next;
		free(Head);
		Head = node;
	}
}