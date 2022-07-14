#include <stdlib.h>
#include <stddef.h>
#include "WtButton.h"

typedef void* (*State)(struct Node* node);

static struct Node
{
	unsigned char HoldTicks;
	unsigned char RepeatTicks;
	WtButton_GetValue GetValue;
	WtButton_Report Report;

	unsigned char Time;
	unsigned char HoldCount;
	unsigned char RepeatCount;

	State Current;

	struct Node* Next;
}*Head = NULL;

static void* ReadyState(struct Node* node);
static void* DownState(struct Node* node);
static void* HoldState(struct Node* node);
static void* UpState(struct Node* node);
static void* WaitState(struct Node* node);
static void* Down1State(struct Node* node);

static void* ReadyState(struct Node* node)
{
	if (node->GetValue())
	{
		node->RepeatCount = 0;
		return DownState;
	}
	else
	{
		return NULL;
	}
}

static void* DownState(struct Node* node)
{
	if (node->GetValue())
	{
		node->HoldCount = 0;
		node->Time = 0;
		node->Report(WtButton_Hold, node->HoldCount++);
		return HoldState;
	}
	else
	{
		return ReadyState;
	}
}

static void* HoldState(struct Node* node)
{
	node->Time++;
	if (node->GetValue())
	{
		if (node->Time % node->HoldTicks == 0)
		{
			node->Report(WtButton_Hold, node->HoldCount++);
		}
		return NULL;
	}
	else
	{
		return UpState;
	}
}
static void* UpState(struct Node* node)
{
	node->Time++;
	if (node->GetValue())
	{
		if (node->Time % node->HoldTicks == 0)
		{
			node->Report(WtButton_Hold, node->HoldCount++);
		}
		return HoldState;
	}
	else
	{
		node->Time = 0;
		node->Report(WtButton_Repeat, node->RepeatCount++);
		return WaitState;
	}
}

static void* WaitState(struct Node* node)
{
	if (node->Time++ < node->RepeatTicks)
	{
		if (node->GetValue())
		{
			return	Down1State;
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		return ReadyState;
	}
}

static void* Down1State(struct Node* node)
{
	node->Time++;
	if (node->GetValue())
	{
		node->HoldCount = 0;
		node->Time = 0;
		node->Report(WtButton_Hold, node->HoldCount++);
		return HoldState;
	}
	else
	{
		return WaitState;
	}
}

unsigned char WtButton_Regist(unsigned char holdTicks, unsigned char repeatTicks, WtButton_GetValue getValue, WtButton_Report report)
{
	unsigned char r = 0;
	struct Node* node;
	if (getValue && report)
	{
		if (node = malloc(sizeof(struct Node)))
		{
			if (holdTicks == 0) { holdTicks = 10; }
			if (repeatTicks == 0) { repeatTicks = 50; }
			node->HoldTicks = holdTicks;
			node->RepeatTicks = repeatTicks;
			node->GetValue = getValue;
			node->Report = report;

			/*node->Time = 0;
			node->HoldCount = 0;
			node->RepeatCount = 0;*/

			node->Current = ReadyState;

			node->Next = Head;
			Head = node;
		}
	}
	return r;
}

void WtButton_Scan(void)
{
	struct Node* node;
	State current;
	node = Head;
	while (node)
	{
		if (current = node->Current(node))//×´Ì¬×ª»»
		{
			node->Current = current;
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