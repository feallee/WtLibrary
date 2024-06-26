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
#define WT_ENTRY_REGISTER(level, category, action) \
     __attribute__((used, __section__(".WtEntry." #level))) const static WtEntry_Type mWtEntry##_##level##_##action = {category, action}
/// @brief 应用程序入口控制块类型。
typedef struct
{
     /// @brief 应用程序入口分类名称。
     char *Category;
     /// @brief 应用程序入口动作函数。
     void (*Action)(void);
} WtEntry_Type;

/// @brief 向应用程序入口级别 1 注册应用程序入口。
/// @param[in] category 应用程序入口分类名称。
/// @param[in] action 应用程序入口动作函数。
#define WT_ENTRY_REGISTER1(category, action) WT_ENTRY_REGISTER(1, category, action)

/// @brief 向应用程序入口级别 2 注册应用程序入口。
/// @param[in] category 应用程序入口分类名称。
/// @param[in] action 应用程序入口动作函数。
#define WT_ENTRY_REGISTER2(category, action) WT_ENTRY_REGISTER(2, category, action)

/// @brief 向应用程序入口级别 3 注册应用程序入口。
/// @param[in] category 应用程序入口分类名称。
/// @param[in] action 应用程序入口动作函数。
#define WT_ENTRY_REGISTER3(category, action) WT_ENTRY_REGISTER(3, category, action)

/// @brief 向应用程序入口级别 4 注册应用程序入口。
/// @param[in] category 应用程序入口分类名称。
/// @param[in] action 应用程序入口动作函数。
#define WT_ENTRY_REGISTER4(category, action) WT_ENTRY_REGISTER(4, category, action)

/// @brief 向应用程序入口级别 5 注册应用程序入口。
/// @param[in] category 应用程序入口分类名称。
/// @param[in] action 应用程序入口动作函数。
#define WT_ENTRY_REGISTER5(category, action) WT_ENTRY_REGISTER(5, category, action)

/// @brief 向应用程序入口级别 6 注册应用程序入口。
/// @param[in] category 应用程序入口分类名称。
/// @param[in] action 应用程序入口动作函数。
#define WT_ENTRY_REGISTER6(category, action) WT_ENTRY_REGISTER(6, category, action)

/// @brief 向应用程序入口级别 7 注册应用程序入口。
/// @param[in] category 应用程序入口分类名称。
/// @param[in] action 应用程序入口动作函数。
#define WT_ENTRY_REGISTER7(category, action) WT_ENTRY_REGISTER(7, category, action)

/// @brief 向应用程序入口级别 8 注册应用程序入口。
/// @param[in] category 应用程序入口分类名称。
/// @param[in] action 应用程序入口动作函数。
#define WT_ENTRY_REGISTER8(category, action) WT_ENTRY_REGISTER(8, category, action)

/// @brief 执行匹配应用程序入口分类名称的动作函数（按应用程序入口级别顺序执行：1->2->3->4->5->6->7->8）。
/// @param[in] category 应用程序入口分类名称。
/// @return 返回匹配应用程序入口分类名称的数量。
extern int WtEntry_Execute(const char *category);
#endif
