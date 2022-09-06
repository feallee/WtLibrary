/*--------------------------------------------------------------------------
FSMTINY.H
Finite state machine(Mealy) tiny version 1.1 functions for ANSI C.
Powered by feallee@hotmail.com at #2022/06/17#.
--------------------------------------------------------------------------*/
#ifndef __FSMTINY_H_
#define __FSMTINY_H_
#include <stddef.h>

/// <summary>
/// 状态机（精简）库函数版本号。
/// </summary>
#define FSMTNY_VERSION	12

/// <summary>
/// 未知状态，在定义状态时不允许使用此状态值。
/// </summary>
#define FSMTINY_STATE_UNKNOW	0xFF 

/// <summary>
/// 状态转换标志。
/// </summary>
#define FSMTNY_TRANSIT_SUCCESS   0//状态转换成功。
#define FSMTNY_TRANSIT_FINAL     1//状态转换失败。停机，状态机实例进入了最终状态。
#define FSMTNY_TRANSIT_UNKNOW    2//状态转换失败。状态机实例为 NULL。
#define FSMTNY_TRANSIT_UNDEFINED 3//状态转换失败。没有定义状态或事件。

/// <summary>
/// 状态机类型。
/// </summary>
typedef void* FsmTiny_Type;

/// <summary>
/// 状态类型。
/// </summary>
typedef unsigned char FsmTiny_State;

/// <summary>
/// 事件类型。
/// </summary>
typedef unsigned char FsmTiny_Event;

///// <summary>
///// 状态动作参数的存储位置(如 KEIL C51 中：data,idata,xdata,...)。
///// </summary>
//#define FSMTNY_ACTION_RAM

/// <summary>
/// 动作类型。
/// </summary>
/// <param name="args">动作关联参数。</param>
typedef void (*FsmTiny_Action)(void* args);

/// <summary>
/// 状态转换类型。
/// 表示在当前状态 State 下，发生事件 Event 时，状态机将转换到下一状态 Next，并执行动作 Action。
/// 如果不需要执行动作 Action，设置为 NULL。
/// </summary>
typedef struct
{
	/// <summary>
	/// 获取状态。
	/// </summary>
	FsmTiny_State State;
	/// <summary>
	/// 获取事件。
	/// </summary>
	FsmTiny_Event Event;
	/// <summary>
	/// 获取动作。
	/// </summary>
	FsmTiny_Action Action;
	/// <summary>
	/// 获取事件。
	/// </summary>
	FsmTiny_State Next;
}FsmTiny_Transition;

/// <summary>
/// 创建并启动一个新的状态机实例。
/// </summary>
/// <param name="id">状态机标识符。</param>
/// <param name="transitions">状态转换表。</param>
/// <param name="length">状态转换表数量。</param>
/// <param name="initialState">起始状态。</param>
/// <param name="finalState">最终状态。</param>
/// <returns>返回一个新的状态机实例。如果创建失败，返回 NULL。</returns>
FsmTiny_Type FsmTiny_Start(FsmTiny_Transition* transitions, unsigned char length, FsmTiny_State initialState, FsmTiny_State finalState);

/// <summary>
/// 根据事件执行状态转换（在事件发生时调用）。
/// </summary>
/// <param name="machine">状态机实例。</param>
/// <param name="event">事件。</param>
/// <param name="args">动作关联参数。</param>
/// <returns>
/// 返回状态转换标志：
/// FSMTNY_TRANSIT_SUCCESS   = 转换成功。
/// FSMTNY_TRANSIT_FINAL     = 停机，状态机实例当着状态为最终状态。
/// FSMTNY_TRANSIT_UNKNOW    = 状态机实例为 NULL。
/// FSMTNY_TRANSIT_UNDEFINED = 没有定义状态或事件。
/// </returns>
unsigned char FsmTiny_Transit(FsmTiny_Type machine, FsmTiny_Event event, void* args);

/// <summary>
/// 获取当前状态。
/// </summary>
/// <param name="machine">状态机实例。</param>
/// <returns>返回当前状态。如果状态机实例为 NULL，返回 FSMTINY_STATE_UNKNOW。</returns>
FsmTiny_State FsmTiny_GetCurrent(FsmTiny_Type machine);

/// <summary>
/// 停止并释放状态机实例。
/// </summary>
/// <param name="machine">状态机实例。</param>
void FsmTiny_Stop(FsmTiny_Type machine);

#endif