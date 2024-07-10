#include <stdio.h>
#include "LibMealy.h"

static int PlayAction(uint8_t condition, void* parameter, uint8_t from, uint8_t to)
{
	printf("Need to play => Condition:%hhu,Parameter:%pH,From:%hhu,To:%hhu\n", condition, parameter, from, to);
	return 1;
}

static int PauseAction(uint8_t condition, void* parameter, uint8_t from, uint8_t to)
{
	printf("Need to pause => Condition:%hhu,Parameter:%pH,From:%hhu,To:%hhu\n", condition, parameter, from, to);
	return 1;
}

static int StopAction(uint8_t condition, void* parameter, uint8_t from, uint8_t to)
{
	printf("Need to stop => Condition:%hhu,Parameter:%pH,From:%hhu,To:%hhu\n", condition, parameter, from, to);
	return 1;
}

enum
{
	STATE_STOP,  // Í£Ö¹×´Ì¬
	STATE_PLAY,  // ²¥·Å×´Ì¬
	STATE_PAUSE, // ÔÝÍ£×´Ì¬

	STATE_COUNT, // ×´Ì¬ÊýÁ¿£¬¹Ì¶¨Î»ÖÃÇÒÐ¡ÓÚ255
};
enum
{
	CONDITION_PLAY_PAUSE, // ²¥·ÅÔÝÍ£¼ü
	CONDITION_STOP,	   // Í£Ö¹¼ü

	CONDITION_COUNT,	   // °´¼üÊýÁ¿£¬¹Ì¶¨Î»ÖÃÇÒÐ¡ÓÚ255
};
const static LibMealy_TransitionType mTable[STATE_COUNT][CONDITION_COUNT] = {
	//            condition 0               condition 1
	//----------------------------------------------------------------
	/* state 0*/ {{PlayAction, STATE_PLAY}, {NULL, STATE_COUNT}},
	/* state 1*/ {{PauseAction, STATE_PAUSE}, {StopAction, STATE_STOP}},
	/* state 2*/ {{PlayAction, STATE_PLAY}, {StopAction, STATE_STOP}},
};

int LibMealy_Test(void)
{
	LibMealy_MachineType m;
	LibMealy_Init(&m, *mTable, STATE_COUNT, CONDITION_COUNT);
	printf("is final:%d\n", LibMealy_IsFinal(&m));
	LibMealy_Start(&m, STATE_STOP, STATE_COUNT);
	printf("is final:%d\n", LibMealy_IsFinal(&m));
	LibMealy_Raise(&m, CONDITION_PLAY_PAUSE, NULL);
	LibMealy_Raise(&m, CONDITION_PLAY_PAUSE, NULL);
	LibMealy_Raise(&m, CONDITION_PLAY_PAUSE, NULL);
	LibMealy_Raise(&m, CONDITION_STOP, NULL);
	printf("\n");
	LibMealy_Raise(&m, CONDITION_PLAY_PAUSE, NULL);
	LibMealy_Raise(&m, CONDITION_PLAY_PAUSE, NULL);
	LibMealy_Raise(&m, CONDITION_STOP, NULL);
	printf("\n");
	LibMealy_Raise(&m, CONDITION_PLAY_PAUSE, NULL);
	LibMealy_Raise(&m, CONDITION_STOP, NULL);
	printf("\n");
	LibMealy_Raise(&m, CONDITION_STOP, NULL);
	printf("\n");
	LibMealy_Stop(&m);
	printf("is final:%d\n", LibMealy_IsFinal(&m));
	return 0;
}