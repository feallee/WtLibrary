#include "LibMealy.h"

int LibMealy_Init(LibMealy_MachineType *machine, const LibMealy_TransitionType *transitionTable, uint8_t stateCount, uint8_t conditionCount)
{
	int r = 0;
	if (machine &&
		transitionTable &&
		stateCount &&
		conditionCount)
	{
		machine->CurrentState = 0;
		machine->StateCount = stateCount;
		machine->ConditionCount = conditionCount;
		machine->TransitionTable = transitionTable;
		r = 1;
	}
	return r;
}

int LibMealy_Raise(LibMealy_MachineType *machine, uint8_t condition, void *parameter)
{
	int r = 0;
	if (machine &&
		machine->TransitionTable &&
		condition < machine->ConditionCount &&
		machine->CurrentState < machine->StateCount)
	{
		const LibMealy_TransitionType *st = machine->TransitionTable + machine->CurrentState * machine->ConditionCount + condition;
		if (st->Next)
		{
			if (!st->Action ||
				st->Action(condition, parameter, machine->CurrentState, st->Next))
			{
				machine->CurrentState = st->Next;
			}
			r = 1;
		}
	}
	return r;
}
