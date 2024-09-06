#include <string.h>
#include "LibMealy.h"
#include "Application.h"

_APPLICATION_REGISTER_COMMAND(NULL, NULL, 10);
_APPLICATION_REGISTER_COMMAND(NULL, NULL, 20);
_APPLICATION_REGISTER_COMMAND(NULL, NULL, 30);
_APPLICATION_REGISTER_COMMAND(NULL, NULL, 40);
_APPLICATION_REGISTER_COMMAND(NULL, NULL, 50);
int Application_Execute(uint8_t group, const char *name, Application_CommandSenderType sender, void *parameter)
{
    int cnt = 0;
    const _Application_CommandType *b, *e;
    if (group == 1)
    {
        b = &_ApplicationCommand_10_NULL;
        e = &_ApplicationCommand_20_NULL;
    }
    else if (group == 2)
    {
        b = &_ApplicationCommand_20_NULL;
        e = &_ApplicationCommand_30_NULL;
    }
    else if (group == 3)
    {
        b = &_ApplicationCommand_30_NULL;
        e = &_ApplicationCommand_40_NULL;
    }
    else if (group == 4)
    {
        b = &_ApplicationCommand_40_NULL;
        e = &_ApplicationCommand_50_NULL;
    }
    else
    {
        b = e = NULL;
    }

    while (++b < e)
    {
        if (name)
        {
            if (b->Name)
            {
                if (strcmp(name, b->Name) == 0)
                {
                    if (b->Action)
                    {
                        b->Action(sender, parameter);
                    }
                    cnt++;
                }
            }
        }
        else
        {
            if (b->Name == NULL)
            {
                if (b->Action)
                {
                    b->Action(sender, parameter);
                }
                cnt++;
            }
        }
    }
    return cnt;
}

_APPLICATION_REGISTER_ENTRY(NULL, 0, 0);
_APPLICATION_REGISTER_ENTRY(NULL, 0, 9);
static int ExecuteProcedure(_Application_EntryProcedureType procedure, void *parameter)
{
    int cnt = 0;
    for (const _Application_EntryType *b = &_ApplicationEntry_NULL_0 + 1; b < &_ApplicationEntry_NULL_9; b++)
    {
        if (procedure == b->Procedure)
        {
            if (b->Action)
            {
                b->Action(parameter);
            }
            cnt++;
        }
    }
    return cnt;
}

static bool OnLoad(uint32_t event, void *parameter, uint32_t from, uint32_t to)
{
    ExecuteProcedure(APPLICATION_ENTRY_PROCEDURE_LOAD, parameter);
    return true;
}

static bool OnWork(uint32_t event, void *parameter, uint32_t from, uint32_t to)
{
    ExecuteProcedure(APPLICATION_ENTRY_PROCEDURE_WORK, parameter);
    return true;
}

static bool OnCheck(uint32_t event, void *parameter, uint32_t from, uint32_t to)
{
    ExecuteProcedure(APPLICATION_ENTRY_PROCEDURE_CHECK, parameter);
    return true;
}

static bool OnSleep(uint32_t event, void *parameter, uint32_t from, uint32_t to)
{
    ExecuteProcedure(APPLICATION_ENTRY_PROCEDURE_SLEEP, parameter);
    return true;
}

static bool OnWakeup(uint32_t event, void *parameter, uint32_t from, uint32_t to)
{
    ExecuteProcedure(APPLICATION_ENTRY_PROCEDURE_WAKEUP, parameter);
    return true;
}

static const LibMealy_TransitionType _Table[APPLICATION_STATE_COUNT][APPLICATION_EVENT_COUNT] = {
    [APPLICATION_STATE_INITIAL] = {
        [APPLICATION_EVENT_FORWARD] = {OnLoad, APPLICATION_STATE_CHECKING},
    },
    [APPLICATION_STATE_CHECKING] = {
        [APPLICATION_EVENT_FORWARD] = {OnWork, APPLICATION_STATE_WORKING},
    },
    [APPLICATION_STATE_WORKING] = {
        [APPLICATION_EVENT_FORWARD] = {OnSleep, APPLICATION_STATE_SLEEPING},
        [APPLICATION_EVENT_BACK] = {OnCheck, APPLICATION_STATE_CHECKING},
    },
    [APPLICATION_STATE_SLEEPING] = {
        [APPLICATION_EVENT_BACK] = {OnWakeup, APPLICATION_STATE_WORKING},
    },
};

static LibMealy_MachineType _Machine = NULL;
bool Application_Raise(Application_EventType event, void *parameter)
{
    return LibMealy_Raise(_Machine, event, parameter);
}

Application_StateType Application_GetState(void)
{
    return LibMealy_GetState(_Machine);
}

int Application_Run(void *parameter)
{
    if ((_Machine = LibMealy_Create(*_Table, APPLICATION_STATE_COUNT, APPLICATION_EVENT_COUNT)))
    {
        Application_Raise(APPLICATION_EVENT_FORWARD, parameter);
        // vTaskStartScheduler();
        LibMealy_Delete(_Machine);
    }
    return 0;
}
