# 摘要
一种超精简的事件型按键扫描库函数，使用状态机和动态内存实现，非常适用于资源有限的和低功耗场景。
编码遵循 ANSI C 规范，易于扩展和学习。其工作详情参见：按键状态图.vsdx。


# 注意事项
- 部分开发环境需要预先初始化内存池作为使用动态分配内存的前置条件(如 Keil C51)。
- 按键扫描库不需要工作时，一定要释放占用资源，否则有可能造成内存泄露。

# 例程
```C
#pragma warning(disable : 4996)
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include "windows.h"
#include "winbase.h"
#include "WtButton.h"

static unsigned char AValue = 0;
static DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	char ch;
	while (1)
	{
		ch = tolower(getch());//在Windows和VC下有效，其它环境需要更换库函数。
		if (ch == 'a') AValue = 1;
		else if (ch == 's') AValue = 0;
		else if (ch == 'x') AValue = 2;
	}
}

static void Button_Hold(char id, size_t count)
{
	printf("Hold:Id = %d, Count = %zu\n", id, count);
}

static void Button_Repeat(char id, size_t count)
{
	printf("Repeat:Id = %d, Count = %zu\n", id, count);
}

int main(void)
{
	WtButton_Type bt;
	//创建一个模拟按键的任务。
	DWORD PidChildP;
	CreateThread(NULL, 0, ThreadProc, 0, 0, &PidChildP);//在Windows和VC下有效，其它环境需要更换库函数。

	if (bt = WtButton_Create('A', 30, Button_Hold, Button_Repeat))
	{
		printf("本例程演示按键扫描库函数的使用。支持的命令：\n");
		printf("A = 模拟按键按下。\n");
		printf("S = 模拟按键抬起。\n");
		printf("X = 退出。\n");
		//键盘扫描	
		while (AValue < 2)
		{
			WtButton_Scan(bt, AValue);
			Sleep(10);//推荐扫描周期10ms
		}
		WtButton_Dispose(bt);
	}
	else
	{
		printf("内存不足！！！");
	}
	return 0;
}
```

# 更新日志
Version 1.0 2022/09/06 feallee@hotmail.com
1、使用状态机 FsmTiny 重新实现功能。
2、修改演示例程。


Version 1.0 2022/07/14 feallee@hotmail.com
1、实现按键扫描库函数功能。
2、修改演示例程。
