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