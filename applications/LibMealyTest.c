#include <stdio.h>
#include "LibMealy.h"
#include "LibMealyTest.h"

enum
{
	STATE_NONE = 0, // fixed

	STATE_STOP,
	STATE_PLAY,
	STATE_PAUSE,

	STATE_COUNT, // fixed
};
enum
{
	KEY_PLAY_PAUSE = 0,
	KEY_STOP,

	KEY_COUNT, // fixed
};

static int PlayAction(uint8_t condition, void *parameter, uint8_t from, uint8_t to)
{
	if (from == STATE_PAUSE)
	{
		printf("Need to resume => Condition:%hhu,Parameter:%p,From:%hhu,To:%hhu\n", condition, parameter, from, to);
	}
	else
	{
		printf("Need to play => Condition:%hhu,Parameter:%p,From:%hhu,To:%hhu\n", condition, parameter, from, to);
	}
	return 1;
}

static int PauseAction(uint8_t condition, void *parameter, uint8_t from, uint8_t to)
{
	printf("Need to pause => Condition:%hhu,Parameter:%p,From:%hhu,To:%hhu\n", condition, parameter, from, to);
	return 1;
}

static int StopAction(uint8_t condition, void *parameter, uint8_t from, uint8_t to)
{
	printf("Need to stop => Condition:%hhu,Parameter:%p,From:%hhu,To:%hhu\n", condition, parameter, from, to);
	return 1;
}

const static LibMealy_TransitionType mTable[STATE_COUNT][KEY_COUNT] = {
	//                  KEY_PLAY_PAUSE               KEY_STOP
	//----------------------------------------------------------------
	/* STATE_INITIAL */ {{NULL, STATE_STOP}, {NULL, STATE_STOP}}, // fixed
	/* STATE_STOP    */ {{PlayAction, STATE_PLAY}, {NULL, STATE_NONE}},
	/* STATE_PLAY    */ {{PauseAction, STATE_PAUSE}, {StopAction, STATE_STOP}},
	/* STATE_PAUSE   */ {{PlayAction, STATE_PLAY}, {StopAction, STATE_STOP}},
};

void LibMealyTest_Run(void)
{
	LibMealy_MachineType m;
	LibMealy_Init(&m, *mTable, STATE_COUNT, KEY_COUNT);
	LibMealy_Raise(&m, KEY_STOP, NULL);
	printf("Mealy started\n");
	LibMealy_Raise(&m, KEY_PLAY_PAUSE, NULL);
	LibMealy_Raise(&m, KEY_PLAY_PAUSE, NULL);
	LibMealy_Raise(&m, KEY_PLAY_PAUSE, NULL);
	LibMealy_Raise(&m, KEY_STOP, NULL);
	printf("\n");
	LibMealy_Raise(&m, KEY_PLAY_PAUSE, NULL);
	LibMealy_Raise(&m, KEY_PLAY_PAUSE, NULL);
	LibMealy_Raise(&m, KEY_STOP, NULL);
	printf("\n");
	LibMealy_Raise(&m, KEY_PLAY_PAUSE, NULL);
	LibMealy_Raise(&m, KEY_STOP, NULL);
	printf("\n");
	LibMealy_Raise(&m, KEY_STOP, NULL);
}