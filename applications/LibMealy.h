/**
 * @brief 有限状态机管理模块。
 * @copyright Copyright(C) 2023 We As Top team. All rights reserved.
 * @section 修订日志
 * 日期         作者                内容
 * -------------------------------------------------------------------------
 * 2024/7/10   feallee@hotmail.com 初版。
 */

#ifndef __LIB_MEALY_H__
#define __LIB_MEALY_H__
#include <stdint.h>
#ifdef __cplusplus
extern "C"
{
#endif
	/// @brief 状态机转移表类型。
	typedef struct
	{
		/// @brief 动作。
		/// @param from 当前状态。
		/// @param condition 条件。
		/// @param to 目标状态。
		/// @param parameter 关联参数。
		/// @return 返回 1 继续转换状态；0 强制中止转换状态，并保持在当前状态。
		int (*Action)(uint8_t condition, void *parameter, uint8_t from, uint8_t to);
		/// @brief 次态。
		uint8_t Next;
	} LibMealy_TransitionType;

	/// @brief 状态机类型。
	typedef struct
	{
		/// @brief 当前状态。
		uint8_t CurrentState;
		/// @brief 状态数量。
		uint8_t StateCount;
		/// @brief 条件数量。
		uint8_t ConditionCount;
		/// @brief 转移表。
		const LibMealy_TransitionType *TransitionTable;
	} LibMealy_MachineType;

	/// @brief 初始化状态机。
	/// @param machine 状态机。
	/// @param transitionTable  转换表。
	/// @param stateCount 状态数量。
	/// @param conditionCount 条件数量。
	/// @return 返回 1 成功，0 失败。
	extern int LibMealy_Init(LibMealy_MachineType *machine, const LibMealy_TransitionType *transitionTable, uint8_t stateCount, uint8_t conditionCount);

	/// @brief 状态机转移。
	/// @param machine 状态机。
	/// @param condition 条件。
	/// @param parameter 关联参数。
	/// @return 返回 1 成功，0 失败。
	extern int LibMealy_Raise(LibMealy_MachineType *machine, uint8_t condition, void *parameter);

	/// @brief 获取当前状态。
	/// @param machine 状态机。
	/// @return 返回当前状态。
	static inline uint8_t LibMealy_GetState(LibMealy_MachineType *machine)
	{
		return machine ? machine->CurrentState : 0;
	}
#ifdef __cplusplus
}
#endif
#endif
