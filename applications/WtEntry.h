/**
 * @brief 应用程序入口管理模块。
 * @copyright Copyright(C) 2023 We As Top team. All rights reserved.
 * @section 修订日志
 * 日期         作者                内容
 * -------------------------------------------------------------------------
 * 2024/4/26   feallee@hotmail.com 初版。
 */

#ifndef __WT_ENTRY_H_
#define __WT_ENTRY_H_
#include <stdint.h>
/// @brief 应用程序入口无执行者。
#define WT_ENTRY_EXECUTER_NONE 0x00000000
/// @brief 应用程序入口执行者为所有。
#define WT_ENTRY_EXECUTER_ALL 0xffffffff
// TODO: 补充其他执行者。
/// @brief 应用程序入口执行者为控制台。
#define WT_ENTRY_EXECUTER_CONSOLE 0x00000001
/// @brief 应用程序入口执行者为网络。
#define WT_ENTRY_EXECUTER_NETWORK 0x00000002
/// @brief 应用程序入口执行者为短信。
#define WT_ENTRY_EXECUTER_SHORT_MESSAGE 0x00000004

/// @brief 应用程序入口分组类型。
typedef enum
{
     /// @brief 应用程序入口分组 1。
     WT_ENTRY_GROUP_1 = 1,
     /// @brief 应用程序入口分组 2。
     WT_ENTRY_GROUP_2,
     /// @brief 应用程序入口分组 3。
     WT_ENTRY_GROUP_3,
     /// @brief 应用程序入口分组 4。
     WT_ENTRY_GROUP_4,
     /// @brief 应用程序入口分组 5。
     WT_ENTRY_GROUP_5,
     /// @brief 应用程序入口分组 6。
     WT_ENTRY_GROUP_6,
     /// @brief 应用程序入口分组 7。
     WT_ENTRY_GROUP_7,
     /// @brief 应用程序入口分组 8。
     WT_ENTRY_GROUP_8,
} WtEntry_GroupType;

/// @brief 应用程序入口控制块类型。
typedef struct
{
     /// @brief 应用程序入口名称。
     char *Name;
     /// @brief 应用程序入口动作。
     void (*Action)(uint32_t executer, void *parameter);
} WtEntry_Type;

/// @brief 注册应用程序入口(分组 1)。
/// @param[in] action 应用程序入口动作。
/// @param[in] name 应用程序入口名称。
#define WT_ENTRY_REGISTER1(name, action) \
     __attribute__((used, __section__(".WtEntry.11"))) const static WtEntry_Type mWtCommand_##action = {name, action}

/// @brief 注册应用程序入口(分组 2)。
/// @param[in] action 应用程序入口动作。
/// @param[in] name 应用程序入口名称。不允许为 NULL。
#define WT_ENTRY_REGISTER2(name, action) \
     __attribute__((used, __section__(".WtEntry.21"))) const static WtEntry_Type mWtCommand_##action = {name, action}

/// @brief 注册应用程序入口(分组 3)。
/// @param[in] action 应用程序入口动作。
/// @param[in] name 应用程序入口名称。不允许为 NULL。
#define WT_ENTRY_REGISTER3(name, action) \
     __attribute__((used, __section__(".WtEntry.31"))) const static WtEntry_Type mWtCommand_##action = {name, action}

/// @brief 注册应用程序入口(分组 4)。
/// @param[in] action 应用程序入口动作。
/// @param[in] name 应用程序入口名称。不允许为 NULL。
#define WT_ENTRY_REGISTER4(name, action) \
     __attribute__((used, __section__(".WtEntry.41"))) const static WtEntry_Type mWtCommand_##action = {name, action}

/// @brief 注册应用程序入口(分组 5)。
/// @param[in] action 应用程序入口动作。
/// @param[in] name 应用程序入口名称。不允许为 NULL。
#define WT_ENTRY_REGISTER5(name, action) \
     __attribute__((used, __section__(".WtEntry.51"))) const static WtEntry_Type mWtCommand_##action = {name, action}

/// @brief 注册应用程序入口(分组 6)。
/// @param[in] action 应用程序入口动作。
/// @param[in] name 应用程序入口名称。不允许为 NULL。
#define WT_ENTRY_REGISTER6(name, action) \
     __attribute__((used, __section__(".WtEntry.61"))) const static WtEntry_Type mWtCommand_##action = {name, action}

/// @brief 注册应用程序入口(分组 7)。
/// @param[in] action 应用程序入口动作。
/// @param[in] name 应用程序入口名称。不允许为 NULL。
#define WT_ENTRY_REGISTER7(name, action) \
     __attribute__((used, __section__(".WtEntry.71"))) const static WtEntry_Type mWtCommand_##action = {name, action}

/// @brief 注册应用程序入口(分组 8)。
/// @param[in] action 应用程序入口动作。
/// @param[in] name 应用程序入口名称。不允许为 NULL。
#define WT_ENTRY_REGISTER8(name, action) \
     __attribute__((used, __section__(".WtEntry.81"))) const static WtEntry_Type mWtCommand_##action = {name, action}

/// @brief 执行匹配分组和名称的应用程序入口。
/// @param[in] group 应用程序入口分组。
/// @param[in] name 应用程序入口名称。如果为 NULL,忽略匹配应用程序入口名称，只匹配应用程序入口分组。
/// @param[in] executer 应用程序入口执行者。
/// @param[in] parameter  应用程序入口参数。
/// @return 返回执行应用程序入口的数量。
extern int WtEntry_Execute(WtEntry_GroupType group, const char *name, uint32_t executer, void *parameter);

#endif
