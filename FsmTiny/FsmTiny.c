#include <stdlib.h>
#include "FsmTiny.h"

struct Machine
{
	FsmTiny_Transition* Transitions;
	unsigned char Length;
	FsmTiny_State Current;
	FsmTiny_State Final;
};

FsmTiny_Type FsmTiny_Start(FsmTiny_Transition* transitions, unsigned char length, FsmTiny_State initialState, FsmTiny_State finalState)
{
	struct Machine* m = NULL;
	if (transitions)
	{
		if (m = malloc(sizeof(struct Machine)))
		{
			m->Transitions = transitions;
			m->Length = length;
			m->Current = initialState;
			m->Final = finalState;
		}
	}
	return m;
}

unsigned char FsmTiny_Transit(FsmTiny_Type machine, FsmTiny_Event event, void* args)
{
	unsigned char r;
	unsigned char i;
	struct Machine* m;
	if (m = machine)
	{
		if (m->Current == m->Final)
		{
			r = FSMTNY_TRANSIT_FINAL;
		}
		else
		{
			r = FSMTNY_TRANSIT_UNDEFINED;
			for (i = 0; i < m->Length; i++)
			{
				if (m->Transitions[i].State == m->Current && m->Transitions[i].Event == event)
				{
					r = FSMTNY_TRANSIT_SUCCESS;
					if (m->Transitions[i].Action)
					{
						m->Transitions[i].Action(args);
					}
					m->Current = m->Transitions[i].Next;
					break;
				}
			}
		}
	}
	else
	{
		r = FSMTNY_TRANSIT_UNKNOW;
	}
	return r;
}

FsmTiny_State FsmTiny_GetCurrent(FsmTiny_Type machine)
{
	FsmTiny_State r = FSMTINY_STATE_UNKNOW;
	struct Machine* m;
	if (m = machine)
	{
		r = m->Current;
	}
	return r;
}

void FsmTiny_Stop(FsmTiny_Type machine)
{
	free(machine);
}


