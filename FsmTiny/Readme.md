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
- 为了精简功能，本状态机不支持“最终状态”，也就是说状态机启动后一直工作直到主动停止。
- 如果有需要，可以自行修改源码支持支持“最终状态”。
# 编写状态函数
```C
//
// ...
//
static void StopAction(void)
{	
	printf("停止播放\n");
}

static void PlayAction(void)
{	
	printf("播放歌曲，文件编号（%d）\n", Context.FileIndex);
}

//步骤3：定义状态转换表。
static FsmTiny_Transition Transitions[] =
{
	//状态		事件		次态		动作
	//--------------------------------------------------------
	{PlayState,	PlayPauseEvent,	PauseState,	PauseAction},
	{PlayState,	StopEvent,	StopState,	StopAction},
	{PauseState,	StopEvent,	StopState,	StopAction},
	{PauseState,	PlayPauseEvent,	PlayState,	ResumeAction},
	{StopState,	PlayPauseEvent,	PlayState,	PlayAction},
	//{StopState,	StopEvent,	StopState,	NULL}//本条可以不要，只是为了演示无动作的状态转换。
};
//
// ...
//
```

# 更新日志
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
