/**
 * @brief 应用程序管理模块。
 * @copyright Copyright(C) 2024 WeasTop team. All rights reserved.
 * @note 应用程序推荐框架。
 *               SYSTEM LAYERED DESIGN DIAGRAM
 * +------------------------------------------------+
 * |                USER APPLICATION                | LAYER 3
 * +------------------------------------------------+
 * +-----+ +--------------+ +-----------------------+
 * |     | | USER LIBRARY | | BOARD SUPPORT PACKAGE | LAYER 2
 * |     | +--------------+ +-----------------------+
 * |     +-----------------------+ +----------------+
 * |       OPERATE SYSTEM        | | DEVICE LIBRARY | LAYER 1
 * +-----------------------------+ +----------------+
 * +------------------------------------------------+
 * |                     DEVICE                     | LAYER 0
 * +------------------------------------------------+
 * Access restrictions on the same or next layer.
 * @section 修订日志
 * 日期         作者                内容
 * -------------------------------------------------------------------------
 * 2024/8/31   feallee@hotmail.com 初版。
 */

#ifndef __APPLICATION_H__
#define __APPLICATION_H__
#include <stdint.h>
#include "AppConfig.h"
#include "WtBuild.h"
#ifdef __cplusplus
extern "C"
{
#endif

/*应用程序版本*/
#define _APPLICATION_VERSION_TO_TEXT(A) #A
#define _APPLICATION_VERSION_TO_TEXT4(A, B, C, D) _APPLICATION_VERSION_TO_TEXT(A.B.C.D)
#define _APPLICATION_VERSION_TO_TEXT3(A, B, C) _APPLICATION_VERSION_TO_TEXT(A.B.C)
#define _APPLICATION_VERSION_TO_TEXT1(A) _APPLICATION_VERSION_TO_TEXT(A)

#if APP_CONFIG_PRODUCT_NAME_CURRENT == APP_CONFIG_PRODUCT_NAME_FL500
#define _APPLICATION_VERSION_TO_PRODUCT_NAME "F500"
#elif APP_CONFIG_PRODUCT_NAME_CURRENT == APP_CONFIG_PRODUCT_NAME_FL600
#define _APPLICATION_VERSION_TO_PRODUCT_NAME "F600"
#else
#error Configuration error, please configure macro APP_CONFIG_PRODUCT_NAME_CURRENT in AppConfig.h.
#endif

#if APP_CONFIG_CUSTOMER_NAME_CURRENT == APP_CONFIG_CUSTOMER_NAME_QTK
#define _APPLICATION_CONFIG_CUSTOMER_NAME "QTK"
#elif APP_CONFIG_CUSTOMER_NAME_CURRENT == APP_CONFIG_CUSTOMER_NAME_ELC
#define _APPLICATION_CONFIG_CUSTOMER_NAME "ELC"
#elif APP_CONFIG_CUSTOMER_NAME_CURRENT == APP_CONFIG_CUSTOMER_NAME_MOBI
#define _APPLICATION_CONFIG_CUSTOMER_NAME "MOBI"
#else
#error Configuration error, please configure macro APP_CONFIG_CUSTOMER_NAME_CURRENT in AppConfig.h.
#endif

#if APP_CONFIG_FUNCTION_NAME_CURRENT == APP_CONFIG_FUNCTION_NAME_GENERAL
#define _APPLICATION_CONFIG_FUNCTION_NAME "Net"
#elif APP_CONFIG_FUNCTION_NAME_CURRENT == APP_CONFIG_FUNCTION_NAME_NET
#define _APPLICATION_CONFIG_FUNCTION_NAME "Bt"
#elif APP_CONFIG_FUNCTION_NAME_CURRENT == APP_CONFIG_FUNCTION_NAME_BT
#define _APPLICATION_CONFIG_FUNCTION_NAME "General"
#else
#error Configuration error, please configure macro APP_CONFIG_FUNCTION_NAME_CURRENT in AppConfig.h.
#endif

#if APP_CONFIG_PROTOCOL_NAME_CURRENT == APP_CONFIG_PROTOCOL_NAME_NONE
#define _APPLICATION_CONFIG_PROTOCOL_NAME "None"
#elif APP_CONFIG_PROTOCOL_NAME_CURRENT == APP_CONFIG_PROTOCOL_NAME_PT100
#define _APPLICATION_CONFIG_PROTOCOL_NAME "PT100"
#elif APP_CONFIG_PROTOCOL_NAME_CURRENT == APP_CONFIG_PROTOCOL_NAME_JT808
#define _APPLICATION_CONFIG_PROTOCOL_NAME "JT808"
#elif APP_CONFIG_PROTOCOL_NAME_CURRENT == APP_CONFIG_PROTOCOL_NAME_ALL
#define _APPLICATION_CONFIG_PROTOCOL_NAME "ALL"
#else
#error Configuration error, please configure macro APP_CONFIG_PROTOCOL_NAME_CURRENT in AppConfig.h.
#endif

#define _APPLICATION_VERSION_DATE                   \
	_APPLICATION_VERSION_TO_TEXT1(WT_BUILD_YEAR_2)  \
	_APPLICATION_VERSION_TO_TEXT1(WT_BUILD_YEAR_1)  \
	_APPLICATION_VERSION_TO_TEXT1(WT_BUILD_MONTH_2) \
	_APPLICATION_VERSION_TO_TEXT1(WT_BUILD_MONTH_1) \
	_APPLICATION_VERSION_TO_TEXT1(WT_BUILD_DAY_2)   \
	_APPLICATION_VERSION_TO_TEXT1(WT_BUILD_DAY_1)
#define _APPLICATION_VERSION_TIME                    \
	_APPLICATION_VERSION_TO_TEXT1(WT_BUILD_HOUR_2)   \
	_APPLICATION_VERSION_TO_TEXT1(WT_BUILD_HOUR_1)   \
	_APPLICATION_VERSION_TO_TEXT1(WT_BUILD_MINUTE_2) \
	_APPLICATION_VERSION_TO_TEXT1(WT_BUILD_MINUTE_1) \
	_APPLICATION_VERSION_TO_TEXT1(WT_BUILD_SECOND_2) \
	_APPLICATION_VERSION_TO_TEXT1(WT_BUILD_SECOND_1)

/// @brief 应用程序版本精简字符串。
#define APPLICATION_VERSION_TINY "V" _APPLICATION_VERSION_TO_TEXT4(APP_CONFIG_VERSION_MAJOR, APP_CONFIG_VERSION_MINOR, APP_CONFIG_VERSION_REVISION, WT_BUILD_NUMBER)
/// @brief 应用程序版本完整字符串。
#define APPLICATION_VERSION_FULL _APPLICATION_VERSION_TO_PRODUCT_NAME "_" _APPLICATION_VERSION_DATE "_" _APPLICATION_VERSION_TIME "_" _APPLICATION_CONFIG_CUSTOMER_NAME "_" _APPLICATION_CONFIG_FUNCTION_NAME "_" _APPLICATION_CONFIG_PROTOCOL_NAME "_" APPLICATION_VERSION_TINY
/// @brief 应用程序版本号。
#define APPLICATION_VERSION_NUMBER (APP_CONFIG_VERSION_MAJOR << 24 | APP_CONFIG_VERSION_MINOR << 16 | APP_CONFIG_VERSION_REVISION << 8)

	/*应用程序命令*/
	/// @brief 应用程序命令来源类型。
	typedef enum
	{
		/// @brief 应用程序命令来源未知。
		APPLICATION_COMMAND_SENDER_UNKNOWN = 0U,
		/// @brief 应用程序命令来源为所有。
		APPLICATION_COMMAND_SENDER_ALL = 0xFFFFFFFFU,

		/// @brief 应用程序命令来源为控制台。
		APPLICATION_COMMAND_SENDER_CONSOLE = 0x00000001U,
		/// @brief 应用程序命令来源为网络。
		APPLICATION_COMMAND_SENDER_NETWORK = 0x00000002U,
		/// @brief 应用程序命令来源为短信。
		APPLICATION_COMMAND_SENDER_SHORT_MESSAGE = 0x00000004U,

	} Application_CommandSenderType;

	typedef struct
	{
		/// @brief 应用程序命令动作函数。
		/// @param[in] sender 应用程序命令来源。
		/// @param[in,out] parameter 应用程序命令关联参数。
		void (*Action)(Application_CommandSenderType sender, void *parameter);
		const char *Name;
	} _Application_CommandType;

#define _APPLICATION_REGISTER_COMMAND(action, name, group)            \
	__attribute__((used, __section__(".ApplicationCommand." #group))) \
	const static _Application_CommandType _ApplicationCommand_##group##_##action = {action, name}

/// @brief 注册应用程序命令(分组 1)。
/// @param[in] name 应用程序命令名称。
/// @param[in] action 应用程序命令动作函数。
#define APPLICATION_REGISTER_COMMAND_1(action, name) _APPLICATION_REGISTER_COMMAND(action, name, 11)

/// @brief 注册应用程序命令(分组 2)。
/// @param[in] name 应用程序命令名称。
/// @param[in] action 应用程序命令动作函数。
#define APPLICATION_REGISTER_COMMAND_2(action, name) _APPLICATION_REGISTER_COMMAND(action, name, 21)

/// @brief 注册应用程序命令(分组 3)。
/// @param[in] name 应用程序命令名称。
/// @param[in] action 应用程序命令动作函数。
#define APPLICATION_REGISTER_COMMAND_3(action, name) _APPLICATION_REGISTER_COMMAND(action, name, 31)

/// @brief 注册应用程序命令(分组 4)。
/// @param[in] name 应用程序命令名称。
/// @param[in] action 应用程序命令动作函数。
#define APPLICATION_REGISTER_COMMAND_4(action, name) _APPLICATION_REGISTER_COMMAND(action, name, 41)

	/// @brief 执行指定分组中匹配名称的应用程序命令动作函数。
	/// @param[in] group 应用程序命令分组(1-4)。
	/// @param[in] name 应用程序命令名称。
	/// @param[in] sender 应用程序命令来源。
	/// @param[in,out] parameter 应用程序命令关联参数。
	/// @return 返回成功执行的命令数量。
	int Application_Execute(uint8_t group, const char *name, Application_CommandSenderType sender, void *parameter);

	/*应用程序入口和状态*/
	/*
	 * ********************************************************
	 *               APPLICATION STATE DIAGRAM
	 * ********************************************************
	 *                          ( )
	 *                           |
	 *                GO FORWARD EVENT(LOAD)
	 *                           |
	 *                           v
	 *                +---------------------+
	 *                |   CHECKING STATE    |<-------
	 *                +---------------------+        |
	 *                           |                   |
	 *                GO FORWARD EVENT(WORK)   GO BACK EVENT
	 *                           |                (CHECK)
	 *                           v                   |
	 *                +---------------------+        |
	 *        ------->|    WORKING STATE    |--------
	 *       |        +---------------------+
	 *       |                   |
	 * GO BACK EVENT  GO FORWARD EVENT(SLEEP)
	 *   (WAKEUP)                |
	 *       |                   v
	 *       |        +---------------------+
	 *        --------|   SLEEPING STATE    |
	 *                +---------------------+
	 *
	 * Powered by feallee@hotmail.com on 2024/7/18.
	 */

	typedef enum
	{
		/// @brief 应用程序入口加载过程。
		APPLICATION_ENTRY_PROCEDURE_LOAD,
		/// @brief 应用程序工作过程。
		APPLICATION_ENTRY_PROCEDURE_WORK,
		/// @brief 应用程序自检过程。
		APPLICATION_ENTRY_PROCEDURE_CHECK,
		/// @brief 应用程序唤醒过程。
		APPLICATION_ENTRY_PROCEDURE_WAKEUP,
		/// @brief 应用程序休眠过程。
		APPLICATION_ENTRY_PROCEDURE_SLEEP,
	} _Application_EntryProcedureType;

	typedef struct
	{
		/// @brief 应用程序入口函数。
		/// @param[in,out] parameter 应用程序入口函数关联参数。
		void (*Action)(void *parameter);
		_Application_EntryProcedureType Procedure;
	} _Application_EntryType;

#define _APPLICATION_REGISTER_ENTRY(action, procedure, level)       \
	__attribute__((used, __section__(".ApplicationEntry." #level))) \
	const static _Application_EntryType _ApplicationEntry_##action##_##level = {action, procedure}

/// @brief 注册应用程序过程函数(优先级 1)，执行顺序按优先级：1->2->3->4->5->6->7->8。
/// @param[in] action 应用程序过程函数。注意：函数中禁止调用函数 Application_Raise。
/// @param[in] procedure 应用程序过程。
#define APPLICATION_REGISTER_ENTRY_1(action, procedure) _APPLICATION_REGISTER_ENTRY(action, procedure, 1)

/// @brief 注册应用程序过程函数(优先级 2)，执行顺序按优先级：1->2->3->4->5->6->7->8。
/// @param[in] action 应用程序过程函数。注意：函数中禁止调用函数 Application_Raise。
/// @param[in] procedure 应用程序过程。
#define APPLICATION_REGISTER_ENTRY_2(action, procedure) _APPLICATION_REGISTER_ENTRY(action, procedure, 2)

/// @brief 注册应用程序过程函数(优先级 3)，执行顺序按优先级：1->2->3->4->5->6->7->8。
/// @param[in] action 应用程序过程函数。注意：函数中禁止调用函数 Application_Raise。
/// @param[in] procedure 应用程序过程。
#define APPLICATION_REGISTER_ENTRY_3(action, procedure) _APPLICATION_REGISTER_ENTRY(action, procedure, 3)

/// @brief 注册应用程序过程函数(优先级 4)，执行顺序按优先级：1->2->3->4->5->6->7->8。
/// @param[in] action 应用程序过程函数。注意：函数中禁止调用函数 Application_Raise。
/// @param[in] procedure 应用程序过程。
#define APPLICATION_REGISTER_ENTRY_4(action, procedure) _APPLICATION_REGISTER_ENTRY(action, procedure, 4)

/// @brief 注册应用程序过程函数(优先级 5)，执行顺序按优先级：1->2->3->4->5->6->7->8。
/// @param[in] action 应用程序过程函数。注意：函数中禁止调用函数 Application_Raise。
/// @param[in] procedure 应用程序过程。
#define APPLICATION_REGISTER_ENTRY_5(action, procedure) _APPLICATION_REGISTER_ENTRY(action, procedure, 5)

/// @brief 注册应用程序过程函数(优先级 6)，执行顺序按优先级：1->2->3->4->5->6->7->8。
/// @param[in] action 应用程序过程函数。注意：函数中禁止调用函数 Application_Raise。
/// @param[in] procedure 应用程序过程。
#define APPLICATION_REGISTER_ENTRY_6(action, procedure) _APPLICATION_REGISTER_ENTRY(action, procedure, 6)

/// @brief 注册应用程序过程函数(优先级 7)，执行顺序按优先级：1->2->3->4->5->6->7->8。
/// @param[in] action 应用程序过程函数。注意：函数中禁止调用函数 Application_Raise。
/// @param[in] procedure 应用程序过程。
#define APPLICATION_REGISTER_ENTRY_7(action, procedure) _APPLICATION_REGISTER_ENTRY(action, procedure, 7)

/// @brief 注册应用程序过程函数(优先级 8)，执行顺序按优先级：1->2->3->4->5->6->7->8。
/// @param[in] action 应用程序过程函数。注意：函数中禁止调用函数 Application_Raise。
/// @param[in] procedure 应用程序过程。
#define APPLICATION_REGISTER_ENTRY_8(action, procedure) _APPLICATION_REGISTER_ENTRY(action, procedure, 8)

	/// @brief 应用程序状态类型。
	typedef enum
	{
		/// @brief 应用程序起始状态。
		APPLICATION_STATE_INITIAL = 0,
		/// @brief 应用程序空状态。
		APPLICATION_STATE_NONE = APPLICATION_STATE_INITIAL,

		/// @brief 应用程序自检状态。
		APPLICATION_STATE_CHECKING,
		/// @brief 应用程序工作状态。
		APPLICATION_STATE_WORKING,
		/// @brief 应用程序休眠状态。
		APPLICATION_STATE_SLEEPING,

		/// @brief 应用程序最终状态。
		APPLICATION_STATE_FIANL,
		/// @brief 应用程序状态数量。
		APPLICATION_STATE_COUNT = APPLICATION_STATE_FIANL
	} Application_StateType;

	/// @brief 应用程序事件类型。
	typedef enum
	{
		/// @brief 应用程序前进事件。
		APPLICATION_EVENT_FORWARD = 0,
		/// @brief 应用程序后退事件。
		APPLICATION_EVENT_BACK,

		/// @brief 应用程序事件数量。
		APPLICATION_EVENT_COUNT
	} Application_EventType;

	/// @brief 向应用程序引发事件。
	/// @param[in] event 应用程序事件。
	/// @param[in,out] parameter 应用程序事件关联参数。
	/// @return 返回成功引发的事件数量。
	int Application_Raise(Application_EventType event, void *parameter);

	/// @brief 获取应用程序当前状态。
	/// @return 返回应用程序当前状态。
	Application_StateType Application_GetState(void);

	/// @brief 在当前线程运行应用程序消息循环。
	/// @param[in,out] parameter 应用程序消息循环关联参数。
	/// @return 返回应用程序退出状态。
	int Application_Run(void *parameter);

#ifdef __cplusplus
}
#endif
#endif