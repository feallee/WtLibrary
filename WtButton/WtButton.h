#ifndef __WT_BUTTON_H_
#define __WT_BUTTON_H_
/// <summary>
/// 按键扫描库函数版本号。
/// </summary>
#define WT_BUTTON_VERSION	10
/// <summary>
/// 按键事件类型。
/// </summary>
typedef enum
{	
	/// <summary>
	/// 按键保持按下。
	/// </summary>
	WtButton_Hold,	
	/// <summary>
	/// 按键重复按下。
	/// </summary>
	WtButton_Repeat
}WtButton_Event;

/// <summary>
/// 获取按键键值回调函数。
/// </summary>
/// <returns>返回按键键值。0=抬起，1=按下。</returns>
typedef unsigned char(*WtButton_GetValue)(void);
/// <summary>
/// 按键事件报告回调函数。
/// </summary>
/// <param name="type">按键事件。</param>
/// <param name="count">按键事件关联的计数。</param>
typedef void(*WtButton_Report)(WtButton_Event event, unsigned char count);
/// <summary>
/// 注册一个按键。
/// </summary>
/// <param name="holdTicks">按键在保持按下时产生事件回调频度，单位为按键扫描周期。默认值：10</param>
/// <param name="repeatTicks">判断按键重复按下的时间依据，单位为按键扫描周期。默认值：10</param>
/// <param name="getValue">获取按键键值回调函数。在使用时必须自行实现。不允许为 NULL。</param>
/// <param name="callback">按键事件报告回调函数。不允许为 NULL。</param>
/// <returns>注册成功标志。0=失败，1=成功。</returns>
unsigned char WtButton_Regist(unsigned char holdTicks, unsigned char repeatTicks, WtButton_GetValue getValue, WtButton_Report report);
/// <summary>
/// 按键扫描。扫描周期推荐10ms。
/// </summary>
void WtButton_Scan(void);
/// <summary>
/// 释放占用的资源。
/// </summary>
void WtButton_Dispose(void);

#endif // !__WT_BUTTON_H_
