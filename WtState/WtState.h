#ifndef __WT_STATE_H_
#define __WT_STATE_H_

typedef enum
{
	PlayState,
	PauseState,
	StopState
}WtState;

typedef enum
{
	PlayPauseEvent,
	StopEvent
}WtEvent;

typedef enum
{
	NoneAction,//±íÊ¾¿Õ²Ù×÷
	PlayAction,
	ResumeAction,
	StopAction
}WtAction;

typedef struct
{
	WtState Current;
	WtEvent Event;
	WtState Next;
	WtAction Action;
}WtTransition;

typedef struct
{
	WtState Initial;
	WtState Final;
	WtTransition* Transitions;
	unsigned int 
}WtMachine;

#endif