/**
 * @brief 应用程序命令管理模块。
 * @copyright Copyright(C) 2023 We As Top team. All rights reserved.
 * @section 修订日志
 * 日期         作者                内容
 * -------------------------------------------------------------------------
 * 2024/4/26   feallee@hotmail.com 初版。
 */

#ifndef __LIB_COMMAND_H_
#define __LIB_COMMAND_H_
#include <stdint.h>
#ifdef __cplusplus
extern "C"
{
#endif
     /// @brief 应用程序命令控制块类型。
     typedef struct
     {
          /// @brief 应用程序命令名称。
          char *Name;
          /// @brief 应用程序命令动作。
          void (*Action)(int sender, void *parameter);
     } LibCommand_Type;
#define LIB_COMMAND_REGISTER(group, name, action) \
     __attribute__((used, __section__(".LibCommand." #group))) const static LibCommand_Type mLibCommand_##group##_##action = {name, action}
/// @brief 应用程序命令来源为无。
#define LIB_COMMAND_SENDER_NONE 0x00000000
/// @brief 应用程序命令来源为所有。
#define LIB_COMMAND_SENDER_ALL 0xffffffff
// TODO: 补充其他来源开始。
/// @brief 应用程序命令来源为控制台。
#define LIB_COMMAND_SENDER_CONSOLE 0x00000001
/// @brief 应用程序命令来源为网络。
#define LIB_COMMAND_SENDER_NETWORK 0x00000002
/// @brief 应用程序命令来源为短信。
#define LIB_COMMAND_SENDER_SHORT_MESSAGE 0x00000004
// TODO: 补充其他来源结束。
/// @brief 向应用程序命令分组 1 注册应用程序命令。
/// @param[in] name 应用程序命令名称。
/// @param[in] action 应用程序命令动作函数。
#define LIB_COMMAND_REGISTER1(name, action) LIB_COMMAND_REGISTER(11, name, action)

/// @brief 向应用程序命令分组 2 注册应用程序命令。
/// @param[in] name 应用程序命令名称。
/// @param[in] action 应用程序命令动作函数。
#define LIB_COMMAND_REGISTER2(name, action) LIB_COMMAND_REGISTER(21, name, action)

/// @brief 向应用程序命令分组 3 注册应用程序命令。
/// @param[in] name 应用程序命令名称。
/// @param[in] action 应用程序命令动作函数。
#define LIB_COMMAND_REGISTER3(name, action) LIB_COMMAND_REGISTER(31, name, action)

/// @brief 向应用程序命令分组 4 注册应用程序命令。
/// @param[in] name 应用程序命令名称。
/// @param[in] action 应用程序命令动作函数。
#define LIB_COMMAND_REGISTER4(name, action) LIB_COMMAND_REGISTER(41, name, action)

     /// @brief 执行指定应用程序分组中匹配应用程序命令名称的应用程序命令动作函数。
     /// @param[in] group 应用程序命令分组(1-4)。
     /// @param[in] name 应用程序命令名称。
     /// @param[in] sender 应用程序命令来源。
     /// @param[in] parameter 应用程序命令参数。
     /// @return 返回匹配应用程序命令名称的数量。
     extern int LibCommand_Execute(uint8_t group, const char *name, int sender, void *parameter);
#ifdef __cplusplus
}
#endif
#endif
