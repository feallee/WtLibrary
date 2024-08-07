#ifndef __APPLICATION_H__
#define __APPLICATION_H__
#ifdef __cplusplus
extern "C"
{
#endif
#include "AppConfig.h"
#include "LibEntry.h"
	//
	//            APPLICATION STATE DIAGRAM
	//
	//                       ( )
	//                        |
	//              GO FORWARD EVENT(CatA)
	//                        |
	//                        v
	//               +-----------------+
	//               | CHECKING  STATE |<--------
	//               +-----------------+         |
	//                        |                  |
	//              GO FORWARD EVENT(CatB)     GO BACK
	//                        |              EVENT(CatC)
	//                        v                  |
	//               +-----------------+         |
	//      -------->|  WORKING STATE  |---------
	//     |         +-----------------+
	//     |                  |
	//  GO BACK     GO FORWARD EVENT(CatE)
	// EVENT(CatD)            |
	//     |                  v
	//     |         +-----------------+
	//      ---------| SLEEPING  STATE |
	//               +-----------------+
	//                        |
	//              GO FORWARD EVENT(CatF)
	//                        |
	//                        v
	//                       (O)
	//
	//  Powered by feallee@hotmail.com on 2024/7/18.
	//

#define APPLICATION_ENTRY_CATEGORY_Z "AppCatZ"

#define APPLICATION_ENTRY_CATEGORY_A "AppCatA"
#define APPLICATION_ENTRY_CATEGORY_B "AppCatB"
#define APPLICATION_ENTRY_CATEGORY_C "AppCatC"
#define APPLICATION_ENTRY_CATEGORY_D "AppCatD"
#define APPLICATION_ENTRY_CATEGORY_E "AppCatE"
#define APPLICATION_ENTRY_CATEGORY_F "AppCatF"

#define APPLICATION_ENTRY_REGISTER_Z(level, entry) LIB_ENTRY_REGISTER(level, APPLICATION_ENTRY_CATEGORY_Z, entry)
#define APPLICATION_ENTRY_REGISTER_A(level, entry) LIB_ENTRY_REGISTER(level, APPLICATION_ENTRY_CATEGORY_A, entry)
#define APPLICATION_ENTRY_REGISTER_B(level, entry) LIB_ENTRY_REGISTER(level, APPLICATION_ENTRY_CATEGORY_B, entry)
#define APPLICATION_ENTRY_REGISTER_C(level, entry) LIB_ENTRY_REGISTER(level, APPLICATION_ENTRY_CATEGORY_C, entry)
#define APPLICATION_ENTRY_REGISTER_D(level, entry) LIB_ENTRY_REGISTER(level, APPLICATION_ENTRY_CATEGORY_D, entry)
#define APPLICATION_ENTRY_REGISTER_E(level, entry) LIB_ENTRY_REGISTER(level, APPLICATION_ENTRY_CATEGORY_E, entry)
#define APPLICATION_ENTRY_REGISTER_F(level, entry) LIB_ENTRY_REGISTER(level, APPLICATION_ENTRY_CATEGORY_F, entry)

	typedef enum
	{
		APPLICATION_STATE_INITIAL = 0,
		APPLICATION_STATE_NONE = APPLICATION_STATE_INITIAL,

		APPLICATION_STATE_CHECKING,
		APPLICATION_STATE_WORKING,
		APPLICATION_STATE_SLEEPING,

		APPLICATION_STATE_FIANL,
		APPLICATION_STATE_COUNT = APPLICATION_STATE_FIANL
	} Application_StateType;

	typedef enum
	{
		APPLICATION_EVENT_FORWARD = 0,
		APPLICATION_EVENT_BACK,

		APPLICATION_EVENT_COUNT
	} Application_EventType;

	extern int Application_Change(Application_EventType event, void *paramater);
	extern Application_StateType Application_GetState(void);
#ifdef __cplusplus
}
#endif
#endif