/*--------------------------------------------------------------------------
FSMTINY.H
Finite state machine(Mealy) tiny version 1.1 functions for ANSI C.
Powered by feallee@hotmail.com at #2022/06/17#.
--------------------------------------------------------------------------*/
#ifndef __FSM_TINY_H_
#define __FSM_TINY_H_
#include <stddef.h>
/// <summary>
/// 状态机库函数（精简）版本号。
/// </summary>
#define FSMTNY_VERSION	12

/// <summary>
/// 状态类型。其中字段可以自定义。
/// </summary>
typedef enum
{
	UnknowState = 0xFF,//未知状态，固定，不允许更改。
	//在这里自定义事件。
	PlayState,
	PauseState,
	StopState,
	
}FsmTiny_State;

/// <summary>
/// 事件类型。其中字段可以自定义。
/// </summary>
typedef enum
{
	//在这里自定义事件。
	PlayPauseEvent,
	StopEvent
}FsmTiny_Event;

/// <summary>
/// 动作类型。
/// </summary>
typedef void (*FsmTiny_Action)(void);

/// <summary>
/// 状态转换类型。表示在当前状态 State 下，发生事件 Event 时，状态机将转换到下一状态 Next，并执行动作 Action。
/// 如果没有动作，设置 Action 为 NULL。
/// </summary>
typedef struct
{	
	FsmTiny_State State;	
	FsmTiny_Event Event;
	FsmTiny_State Next;
	FsmTiny_Action Action;
}FsmTiny_Transition;

/// <summary>
/// 状态机类型。
/// </summary>
typedef void* FsmTiny_Machine;

/// <summary>
/// 创建并启动一个新的状态机实例。
/// </summary>
/// <param name="transitions">状态转换表。</param>
/// <param name="length">状态转换表数量。</param>
/// <param name="initialState">起始状态。</param>
/// <returns>返回一个新的状态机实例。如果创建失败，返回 NULL。</returns>
FsmTiny_Machine FsmTiny_Start(FsmTiny_Transition* transitions, size_t length, FsmTiny_State initialState);

/// <summary>
/// 执行状态转换（在事件发生时调用）。
/// </summary>
/// <param name="machine">状态机实例。</param>
/// <returns>返回状态转换成功标志。0=失败（状态机实例为 NULL 和没有定义事件 event），1=成功。</returns>
unsigned char FsmTiny_Transit(FsmTiny_Machine machine, FsmTiny_Event event);

/// <summary>
/// 获取当前状态。
/// </summary>
/// <param name="machine">状态机实例。</param>
/// <returns>返回当前状态。如果获取失败，返回 UnknowState。</returns>
FsmTiny_State FsmTiny_GetCurrent(FsmTiny_Machine machine);

/// <summary>
/// 停止并释放状态机实例。
/// </summary>
/// <param name="machine">状态机实例。</param>
void FsmTiny_Stop(FsmTiny_Machine machine);

#endif