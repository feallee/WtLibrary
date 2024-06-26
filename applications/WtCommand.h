/**
 * @brief 应用程序命令管理模块。
 * @copyright Copyright(C) 2023 We As Top team. All rights reserved.
 * @section 修订日志
 * 日期         作者                内容
 * -------------------------------------------------------------------------
 * 2024/4/26   feallee@hotmail.com 初版。
 */

#ifndef __WT_COMMAND_H_
#define __WT_COMMAND_H_
#include <stdint.h>
#define WT_COMMAND_REGISTER(group, name, action) \
     __attribute__((used, __section__(".WtCommand." #group))) const static WtCommand_Type mWtCommand##_##group##_##action = {name, action}

/// @brief 应用程序命令来源为无。
#define WT_COMMAND_SENDER_NONE 0x00000000
/// @brief 应用程序命令来源为所有。
#define WT_COMMAND_SENDER_ALL 0xffffffff
// TODO: 补充其他来源。
/// @brief 应用程序命令来源为控制台。
#define WT_COMMAND_SENDER_CONSOLE 0x00000001
/// @brief 应用程序命令来源为网络。
#define WT_COMMAND_SENDER_NETWORK 0x00000002
/// @brief 应用程序命令来源为短信。
#define WT_COMMAND_SENDER_SHORT_MESSAGE 0x00000004

/// @brief 向应用程序命令分组 1 注册应用程序命令。
/// @param[in] name 应用程序命令名称。
/// @param[in] action 应用程序命令动作函数。
#define WT_COMMAND_REGISTER1(name, action) WT_COMMAND_REGISTER(11, name, action)

/// @brief 向应用程序命令分组 2 注册应用程序命令。
/// @param[in] name 应用程序命令名称。
/// @param[in] action 应用程序命令动作函数。
#define WT_COMMAND_REGISTER2(name, action) WT_COMMAND_REGISTER(21, name, action)

/// @brief 向应用程序命令分组 3 注册应用程序命令。
/// @param[in] name 应用程序命令名称。
/// @param[in] action 应用程序命令动作函数。
#define WT_COMMAND_REGISTER3(name, action) WT_COMMAND_REGISTER(31, name, action)

/// @brief 向应用程序命令分组 4 注册应用程序命令。
/// @param[in] name 应用程序命令名称。
/// @param[in] action 应用程序命令动作函数。
#define WT_COMMAND_REGISTER4(name, action) WT_COMMAND_REGISTER(41, name, action)

/// @brief 向应用程序命令分组 5 注册应用程序命令。
/// @param[in] name 应用程序命令名称。
/// @param[in] action 应用程序命令动作函数。
#define WT_COMMAND_REGISTER5(name, action) WT_COMMAND_REGISTER(51, name, action)

/// @brief 向应用程序命令分组 6 注册应用程序命令。
/// @param[in] name 应用程序命令名称。
/// @param[in] action 应用程序命令动作函数。
#define WT_COMMAND_REGISTER6(name, action) WT_COMMAND_REGISTER(61, name, action)

/// @brief 向应用程序命令分组 7 注册应用程序命令。
/// @param[in] name 应用程序命令名称。
/// @param[in] action 应用程序命令动作函数。
#define WT_COMMAND_REGISTER7(name, action) WT_COMMAND_REGISTER(71, name, action)

/// @brief 向应用程序命令分组 8 注册应用程序命令。
/// @param[in] name 应用程序命令名称。
/// @param[in] action 应用程序命令动作函数。
#define WT_COMMAND_REGISTER8(name, action) WT_COMMAND_REGISTER(81, name, action)

/// @brief 应用程序命令控制块类型。
typedef struct
{
     /// @brief 应用程序命令名称。
     char *Name;
     /// @brief 应用程序命令动作。
     void (*Action)(int32_t sender, void *parameter);
} WtCommand_Type;

/// @brief 执行指定应用程序分组中匹配应用程序命令名称的应用程序命令动作函数。
/// @param[in] group 应用程序命令分组(1-8)。
/// @param[in] name 应用程序命令名称。
/// @param[in] sender 应用程序命令来源。
/// @param[in] parameter 应用程序命令参数。
/// @return 返回匹配应用程序命令名称的数量。
extern int WtCommand_Execute(uint8_t group, const char *name, int32_t sender, void *parameter);

#endif
