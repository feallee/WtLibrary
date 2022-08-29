#pragma warning(disable : 4996)
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include "windows.h"
#include "winbase.h"
#include <threads.h>
#include "WtButton.h"

static unsigned char AValue = 0;
static DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	char ch;
	while (1)
	{
		ch = tolower(getch());
		if (ch == 'a') AValue = 1;
		else if (ch == 's') AValue = 0;
	}
}

static unsigned char GetValue(void)
{
	return AValue;//如果按键按下，返回1，抬起返回0
}

static void Report(WtButton_Event event, unsigned char count)
{
	printf("Event:%u,Count:%u\n", event, count);
}

int main(void)
{
	//创建一个模拟按键的任务。
	DWORD PidChildP;
	CreateThread(NULL, 0, ThreadProc, 0, 0, &PidChildP);//在Windows和VC下有效，其它环境需要更换库函数。
		
	printf("本例程演示按键扫描库函数的使用。支持的命令：\n");
	printf("A = 模拟按键按下。\n");
	printf("S = 模拟按键抬起。\n");
	//键盘扫描
	WtButton_Regist(0, 0, GetValue, Report);
	while (1)
	{
		WtButton_Scan();
		Sleep(10);//推荐扫描周期10ms
	}
	WtButton_Dispose();
	return 0;
}