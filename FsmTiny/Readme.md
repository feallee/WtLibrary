# 摘要
一种超精简的事件驱动型有限状态机(Mealy)，使用函数指针和动态内存实现，非常适用于资源有限的和低功耗场景。
编码遵循 ANSI C 规范，易于扩展和学习。
其工作过程如下：
- 使用指定起始状态启动状态机。
- 在事件发生时，把关联事件类型和参数传递给状态机。
- 在不需要使用状态机时，停止状态机。
# 注意事项
- 部分开发环境需要预先初始化内存池作为使用动态分配内存的前置条件(如 Keil C51)。
- 状态机不需要工作时，一定要停止状态机释放占用资源，否则有可能造成内存泄露。
# 例程
```C
#pragma warning(disable : 4996)
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

//步骤1：包含头文件。
#include "FsmTiny.h"

//自定义状态机上下文。
static struct
{
	int FileIndex;
}Context;

//步骤2：定义动作函数。
static void PauseAction(void* args)
{
	printf("暂停播放\n");
}

static void ResumeAction(void* args)
{
	printf("继续播放，文件编号（%d）\n", Context.FileIndex);
}
static void StopAction(void* args)
{
	printf("停止播放\n");
}

static void PlayAction(void* args)
{
	printf("播放歌曲，文件编号（%d）\n", Context.FileIndex);
}

//步骤3：定义状态转换表。

#define STATE_PLAY	0
#define STATE_PAUSE	1
#define STATE_STOP	2

#define EVENT_PLAYPAUSE	0
#define EVENT_STOP	1
static FsmTiny_Transition Transitions[] =
{
	//状态        事件             动作          次态         
	//------------------------------------------------------------------------------
	{STATE_PLAY,  EVENT_PLAYPAUSE, PauseAction,  STATE_PAUSE},
	{STATE_PLAY,  EVENT_STOP,      StopAction,   STATE_STOP},
	{STATE_PAUSE, EVENT_STOP,      StopAction,   STATE_STOP},
	{STATE_PAUSE, EVENT_PLAYPAUSE, ResumeAction, STATE_PLAY},
	{STATE_STOP,  EVENT_PLAYPAUSE, PlayAction,   STATE_PLAY},
	//{STATE_STOP,  EVENT_STOP,      NULL,         STATE_STOP},//本条可以不要，只是为了演示无动作的状态转换。
};

int main(void)
{
	unsigned char r;
	char key;
	FsmTiny_Type machine;

	printf("本例程是使用状态机模拟一个播放器的工作过程。支持三个命令：\n");
	printf("P : 播放歌曲、暂停播放歌曲和继续播放歌曲。\n");
	printf("S : 停止播放歌曲。\n");
	printf("X : 退出程序。\n");
	printf("状态值：\n");
	printf("STATE_PLAY = 0\n");
	printf("STATE_PAUSE = 1\n");
	printf("STATE_STOP = 2\n");
	//步骤4：启动状态机。	
	if (machine = FsmTiny_Start(Transitions, sizeof(Transitions) / sizeof(Transitions[0]), STATE_STOP, FSMTINY_STATE_UNKNOW))
	{
		//步骤5：在事件中触发状态转换。
		while (1)
		{
			printf("\n当前状态：%lu,请输入命令：\n", FsmTiny_GetCurrent(machine));
			key = tolower(getch());//获取按键键值（此函数在Windows和VC下有效，其它环境没有测试过）			
			if (key == 'p')
			{
				//设置状态机上下文
				Context.FileIndex = 3;
				r = FsmTiny_Transit(machine, EVENT_PLAYPAUSE, NULL);
				printf("状态转换标志：%hu\n", r);
			}
			else if (key == 's')
			{
				r = FsmTiny_Transit(machine, EVENT_STOP, NULL);
				printf("状态转换标志：%hu\n", r);
			}
			else if (key == 'x')
			{
				break;
			}
			else
			{
				printf("命令错误！\n");
			}
		}
	}
	//步骤6：释放状态机。
	FsmTiny_Stop(machine);
	return 0;
}
```

# 更新日志
Version 1.2 2022/09/06 feallee@hotmail.com
1、增加支持最终状态。
2、增加动作参数。
3、修改演示例程。

Version 1.2 2022/08/27 feallee@hotmail.com
1、使用状态转换表实现状态机。
2、修改演示例程。

Version 1.1 2022/07/09 feallee@hotmail.com
1、精简和优化状态机功能。
2、修改演示例程。

Version 1.1 2022/06/21 feallee@hotmail.com
1、增加支持多状态机同时工作功能。
2、修改演示例程。

Version 1.0 2022/06/17 feallee@hotmail.com
1、创建项目，核心编码，取名为 FsmTiny。
2、增加演示例程。
