#include <stdlib.h>
#include "FsmTiny.h"

struct Machine
{
	FsmTiny_Transition* Transitions;
	size_t Length;
	FsmTiny_State Current;
};

FsmTiny_Machine FsmTiny_Start(FsmTiny_Transition* transitions, size_t length, FsmTiny_State initialState)
{
	struct Machine* m = NULL;
	if (transitions && initialState)
	{
		if (m = malloc(sizeof(struct Machine)))
		{
			m->Transitions = transitions;
			m->Length = length;
			m->Current = initialState;
		}
	}
	return m;
}

unsigned char FsmTiny_Transit(FsmTiny_Machine machine, FsmTiny_Event event)
{
	unsigned char r=0;
	size_t i;
	struct Machine* m;
	if (m = machine)
	{
		for (i = 0; i < m->Length; i++)
		{
			if (m->Transitions[i].State == m->Current && m->Transitions[i].Event == event)
			{
				r = 1;
				m->Current = m->Transitions[i].Next;
				if (m->Transitions[i].Action)
				{
					m->Transitions[i].Action();
				}				
				break;
			}
		}
	}
	return r;
}

void FsmTiny_Stop(FsmTiny_Machine machine)
{
	free(machine);
}


