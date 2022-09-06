#ifndef __WTBUTTON_H_
#define __WTBUTTON_H_
/// <summary>
/// 按键库函数版本号。
/// </summary>
#define WTBUTTON_VERSION	10

/// <summary>
/// 按键类型。
/// </summary>
typedef void* WtButton_Type;

/// <summary>
/// 按键事件类型。
/// HoldEvent：按键保持活动事件。参数 count 表示按键保持活动次数，为 0 时表示按键开始保持。
/// RepeatEvent：按键重复活动事件。参数 count 表示按键重复活动次数，为 0 时表示按键开始重复。
/// </summary>
/// <param name="id">按键标识符。</param>
/// <param name="id">按键事件计数。</param>
typedef void(*WtButton_Event)(char id, size_t count);

/// <summary>
/// 创建并返回按键实例。
/// </summary>
/// <param name="id">按键标识符。</param>
/// <param name="repeatCycles">重复活动周期范围，表示在多少个扫描周期内是重复活动。推荐 30。</param>
/// <param name="holdEvent">按键保持活动事件。</param>
/// <param name="repeatEvent">按键重复活动事件。</param>
/// <returns>返回按键实例。</returns>
WtButton_Type WtButton_Create(char id, size_t repeatCycles, WtButton_Event holdEvent, WtButton_Event repeatEvent);

/// <summary>
/// 按键扫描。扫描周期推荐 10ms。
/// </summary>
/// <param name="button">按键实例。</param>
/// <param name="value">按键状态值。</param>
void WtButton_Scan(WtButton_Type button, unsigned char value);

/// <summary>
/// 释放按键实例占用资源。
/// </summary>
/// <param name="button">按键实例。</param>
void WtButton_Dispose(WtButton_Type button);


#endif //__WTBUTTON_H_
