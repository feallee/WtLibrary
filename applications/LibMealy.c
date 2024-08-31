#include <stdlib.h>
#include "LibMealy.h"

typedef struct
{
	uint32_t Current;
	uint32_t StateCount;
	uint32_t EventCount;
	LibMealy_TransitionType *Table;
} MachineType;

LibMealy_MachineType LibMealy_Create(LibMealy_TransitionType *transitionTable, uint32_t stateCount, uint32_t eventCount)
{
	MachineType *machine = NULL;
	if (transitionTable && stateCount && eventCount)
	{
		if ((machine = malloc(sizeof(MachineType))))
		{
			machine->Current = 0;
			machine->StateCount = stateCount;
			machine->EventCount = eventCount;
			machine->Table = transitionTable;
		}
	}
	return machine;
}

void LibMealy_Delete(LibMealy_MachineType machine)
{
	free(machine);
	machine = NULL;
}

bool LibMealy_Raise(LibMealy_MachineType machine, uint32_t event, void *parameter)
{
	bool r = false;
	if (machine)
	{
		MachineType *m = machine;
		if (m->Current < m->StateCount && event < m->EventCount)
		{
			const LibMealy_TransitionType *st = m->Table + m->Current * m->EventCount + event;
			if (st->Next)
			{
				if (!st->Action ||
					st->Action(event, parameter, m->Current, st->Next))
				{
					m->Current = st->Next;
				}
				r = true;
			}
		}
	}
	return r;
}

uint32_t LibMealy_GetState(LibMealy_MachineType machine)
{
	uint32_t r = LIB_MEALY_STATE_UNKNOWN;
	if (machine)
	{
		MachineType *m = machine;
		r = m->Current;
	}
	return r;
}