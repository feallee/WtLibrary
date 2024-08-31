/**
 * @brief 有限状态机管理模块。
 * @copyright Copyright(C) 2023 We As Top team. All rights reserved.
 * @section 修订日志
 * 日期         作者                内容
 * -------------------------------------------------------------------------
 * 2024/8/30   feallee@hotmail.com 修改状态机实现方式。
 * 2024/7/10   feallee@hotmail.com 初版。
 */

#ifndef __LIB_MEALY_H__
#define __LIB_MEALY_H__
#include <stdbool.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C"
{
#endif
/// @brief 状态机未知状态。
#define LIB_MEALY_STATE_UNKNOWN 0xFFFFFFFFU
	/// @brief 状态机转移表类型。
	typedef struct
	{
		/// @brief 动作。
		/// @param from 当前状态。
		/// @param event 事件。
		/// @param to 目标状态。
		/// @param parameter 关联参数。
		/// @return 返回 true 继续转换状态；false 强制中止转换状态，并保持在当前状态。
		bool (*Action)(uint32_t event, void *parameter, uint32_t from, uint32_t to);
		/// @brief 次态。
		uint32_t Next;
	} LibMealy_TransitionType;

	/// @brief 状态机类型。
	typedef void *LibMealy_MachineType;

	/// @brief 创建新的状态机实例。
	/// @param transitionTable 状态转换表。
	/// @param stateCount 转换表中状态数量。
	/// @param eventCount 转换表中事件数量。
	/// @return 返回新的状态机实例。如果创建失败，返回 NULL。
	LibMealy_MachineType LibMealy_Create(LibMealy_TransitionType *transitionTable, uint32_t stateCount, uint32_t eventCount);

	/// @brief 删除状态机实例。
	/// @param machine 状态机实例。
	void LibMealy_Delete(LibMealy_MachineType machine);

	/// @brief 向状态机实例引发事件。
	/// @param machine 状态机实例。
	/// @param event 事件。
	/// @param parameter 事件关联参数。
	/// @return 返回是否成功向状态机实例引发事件。
	bool LibMealy_Raise(LibMealy_MachineType machine, uint32_t event, void *parameter);

	/// @brief 获取状态机实例的当前状态。
	/// @param machine 状态机实例。
	/// @return 返回状态机实例的当前状态。如果状态机实例为 NULL，返回 LIB_MEALY_STATE_UNKNOWN。
	uint32_t LibMealy_GetState(LibMealy_MachineType machine);

#ifdef __cplusplus
}
#endif
#endif
