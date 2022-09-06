#include <stdlib.h>
#include <stddef.h>
#include "../FsmTiny/FsmTiny.h"
#include "WtButton.h"

struct Button
{
	char Id;
	WtButton_Event HoldEvent;
	WtButton_Event RepeatEvent;
	size_t HoldCount;
	size_t RepeatCount;
	size_t RepeatCycles;
	size_t Time;
	FsmTiny_Type Machine;
};

static void OnRepeatEvent(struct Button* button)
{
	if (button->RepeatEvent)
	{
		button->RepeatEvent(button->Id, button->RepeatCount++);
	}
}

static void OnHoldEvent(struct Button* button)
{
	if (button->HoldEvent)
	{
		button->HoldEvent(button->Id, button->HoldCount++);
	}
}

static void RepeatAction(void* args)
{
	struct Button* m;
	if (m = args)
	{
		m->Time = m->RepeatCycles;
		OnRepeatEvent(m);
	}
}

static void HoldAction1(void* args)
{
	struct Button* m;
	if (m = args)
	{
		m->HoldCount = 0;
		OnHoldEvent(m);
	}
}

static void HoldAction2(void* args)
{	
	struct Button* m;
	if (m = args)
	{		
		OnHoldEvent(m);
	}
}

#define STATE_READY		0
#define STATE_ACTIVE	1
#define STATE_HOLD		2
#define STATE_DEACTIVE	3

#define EVENT_DEACTIVE	0
#define EVENT_ACTIVE	1

static FsmTiny_Transition Transitions[] =
{
	//状态           事件            动作          次态
	//------------------------------------------------------------------------------	
	{STATE_READY,    EVENT_ACTIVE,   NULL,         STATE_ACTIVE},
	{STATE_ACTIVE,   EVENT_DEACTIVE, NULL,         STATE_READY},
	{STATE_ACTIVE,   EVENT_ACTIVE,   HoldAction1,  STATE_HOLD},
	{STATE_HOLD,     EVENT_ACTIVE,   HoldAction2,  STATE_HOLD},
	{STATE_HOLD,     EVENT_DEACTIVE, NULL,         STATE_DEACTIVE},
	{STATE_DEACTIVE, EVENT_ACTIVE,   HoldAction2,  STATE_HOLD},
	{STATE_DEACTIVE, EVENT_DEACTIVE, RepeatAction, STATE_READY},
};

WtButton_Type WtButton_Create(char id, size_t repeatCycles, WtButton_Event holdEvent, WtButton_Event repeatEvent)
{
	struct Button* m = NULL;
	if (m = malloc(sizeof(struct Button)))
	{
		if (m->Machine = FsmTiny_Start(Transitions, sizeof(Transitions) / sizeof(Transitions[0]), STATE_READY, FSMTINY_STATE_UNKNOW))
		{
			m->Id = id;
			m->RepeatCycles = repeatCycles;
			m->HoldEvent = holdEvent;
			m->RepeatEvent = repeatEvent;

			m->HoldCount = 0;
			m->RepeatCount = 0;			
			m->Time = 0;
		}
		else
		{
			free(m);
			m = NULL;
		}
	}
	return m;
}

void WtButton_Scan(WtButton_Type button, unsigned char value)
{
	struct Button* m;
	if (m = button)
	{
		//执行
		if (m->Time)
		{
			if (--m->Time == 0)
			{
				m->RepeatCount = 0;
			}
		}
		//状态切换
		FsmTiny_Transit(m->Machine, value ? EVENT_ACTIVE : EVENT_DEACTIVE, m);
	}
}

void WtButton_Dispose(WtButton_Type button)
{
	struct Button* m;
	if (m = button)
	{
		FsmTiny_Stop(m->Machine);
	}
	free(m);
}
