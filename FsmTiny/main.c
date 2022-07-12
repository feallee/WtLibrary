#pragma warning(disable : 4996)
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
//步骤1：包含头文件。
#include "FsmTiny.h"

#define MP3	"国歌.mp3"

//步骤2：声明所有状态函数（表示状态机的状态集）。
static void* StopState(size_t  eventArgs);
static void* PlayState(size_t  eventArgs);
static void* PauseState(size_t  eventArgs);

//步骤3：定义所有状态函数。
static void* StopState(size_t  eventArgs)
{
	printf("\n停止状态:接收到命令=%c\n", (char)eventArgs);
	if (eventArgs == 'p')
	{
		printf("播放歌曲:%s\n", MP3);//表示状态机中动作
		return PlayState;//切换到播放状态
	}
	else
	{
		return NULL;//保持在当前状态
	}
}

static void* PlayState(size_t  eventArgs)
{
	printf("\n播放状态:接收到命令=%c\n", (char)eventArgs);
	if (eventArgs == 'p')
	{
		printf("暂停播放歌曲\n");//表示状态机中动作
		return PauseState;//切换到暂停状态
	}
	else if (eventArgs == 's')
	{
		printf("停止播放歌曲\n");//表示状态机中动作
		return StopState;//切换到停止状态
	}
	else
	{
		return NULL;//保持在当前状态
	}
}

static void* PauseState(size_t  eventArgs)
{
	printf("\n暂停状态:接收到命令=%c\n", (char)eventArgs);
	if (eventArgs == 'p')
	{
		printf("继续播放歌曲:%s\n", MP3);//表示状态机中动作
		return PlayState;//切换到播放状态
	}
	else if (eventArgs == 's')
	{
		printf("停止播放歌曲\n");//表示状态机中动作
		return StopState;//切换到停止状态
	}
	else
	{
		return NULL;//保持在当前状态
	}
}

int main(void)
{
	char cmd;
	void* fsm;

	printf("本例程是使用状态机模拟一个播放器的工作过程。支持三个命令：\n");
	printf("P : 播放歌曲、暂停播放歌曲和继续播放歌曲。\n");
	printf("S : 停止播放歌曲。\n");
	printf("X : 退出程序。\n");
	//步骤4：创建状态机。	
	if (fsm = FsmTiny_Start(StopState))
	{
		//步骤5：在事件中触发状态转换。
		while (1)
		{
			printf("\n请输入命令：");
			cmd = tolower(getch());//获取按键键值（此函数在Windows和VC下有效，其它环境没有测试过）
			if (cmd == 'p' || cmd == 's')
			{
				FsmTiny_Transit(fsm, cmd);
			}
			else if (cmd == 'x')
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
	FsmTiny_Stop(fsm);
	return 0;
}