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
		machine->FinalState = 0;
		machine->StateCount = stateCount;
		machine->ConditionCount = conditionCount;
		machine->TransitionTable = transitionTable;
		r = 1;
	}
	return r;
}

int LibMealy_Start(LibMealy_MachineType *machine, uint8_t initialState, uint8_t finalState)
{
	int r = 0;
	if (initialState != finalState &&
		machine &&
		initialState < machine->StateCount)
	{
		machine->CurrentState = initialState;
		machine->FinalState = finalState;
		r = 1;
	}
	return r;
}

void LibMealy_Stop(LibMealy_MachineType *machine)
{
	if (machine && machine->CurrentState != machine->FinalState)
	{
		machine->CurrentState = machine->FinalState;
	}
}

int LibMealy_Raise(LibMealy_MachineType *machine, uint8_t condition, void *parameter)
{
	int r = 0;
	if (machine &&
		!LibMealy_IsFinal(machine) &&
		machine->CurrentState < machine->StateCount &&
		condition < machine->ConditionCount &&
		machine->TransitionTable)
	{
		const LibMealy_TransitionType *st = &machine->TransitionTable[machine->CurrentState * machine->ConditionCount + condition]; // TC:O(1)
		if (st->Next < machine->StateCount)
		{
			r = 1;
			if (!st->Action ||
				st->Action(condition, parameter, machine->CurrentState, st->Next))
			{
				machine->CurrentState = st->Next;
			}
		}
	}
	return r;
}