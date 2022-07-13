#ifndef __WT_BUTTON_H_
#define __WT_BUTTON_H_
/// <summary>
/// 按键事件类型。
/// </summary>
typedef enum
{
	/// <summary>
	/// 按键按下。
	/// </summary>
	WtButton_Down,
	/// <summary>
	/// 按键保持。
	/// </summary>
	WtButton_Hold,
	/// <summary>
	/// 按键抬起。
	/// </summary>
	WtButton_Up,
	/// <summary>
	/// 按键重复。
	/// </summary>
	WtButton_Repeat
}WtButton_Type;

/// <summary>
/// 获取按键键值回调函数。在使用时必须自行实现。
/// </summary>
/// <returns>返回按键键值。0=抬起，1=按下。</returns>
typedef unsigned char(*WtButton_GetValue)(void);
/// <summary>
/// 按键事件回调函数。
/// </summary>
/// <param name="type">按键事件类型。</param>
/// <param name="count">按键事件关联的计数。</param>
typedef void(*WtButton_Callback)(WtButton_Type type, unsigned char count);
/// <summary>
/// 注册一个按键。
/// </summary>
/// <param name="holdTicks">按键在按下保持时产生事件回调频度，单位为按键扫描周期。</param>
/// <param name="repeatTicks">重复按键的时间依据，单位为按键扫描周期。</param>
/// <param name="getValue">获取按键键值回调函数。在使用时必须自行实现。不允许为 NULL。</param>
/// <param name="callback">按键事件回调函数。不允许为 NULL。</param>
/// <returns>注册成功标志。0=失败，1=成功。</returns>
unsigned char WtButton_Regist(unsigned char holdTicks, unsigned char repeatTicks, WtButton_GetValue getValue, WtButton_Callback callback);
/// <summary>
/// 按键扫描。
/// </summary>
void WtButton_Scan(void);
/// <summary>
/// 释放占用的资源。
/// </summary>
void WtButton_Dispose(void);

#endif // !__WT_BUTTON_H_
