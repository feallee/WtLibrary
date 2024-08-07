#ifndef __APP_VERSION_H__
#define __APP_VERSION_H__
#ifdef __cplusplus
extern "C"
{
#endif
#include "AppConfig.h"

#define _APP_VERSION_TO_TEXT(A) #A
#define _APP_VERSION_TO_TEXT3(A,B,C) _APP_VERSION_TO_TEXT(A.B.C)
#define _APP_VERSION_TO_TEXT1(A) _APP_VERSION_TO_TEXT(A)

#if APP_CONFIG_PRODUCT_NAME_CURRENT == APP_CONFIG_PRODUCT_NAME_FL500
#define _APP_VERSION_TO_PRODUCT_NAME "F500"
#elif APP_CONFIG_PRODUCT_NAME_CURRENT == APP_CONFIG_PRODUCT_NAME_FL600
#define _APP_VERSION_TO_PRODUCT_NAME "F600"
#else
#define _APP_VERSION_TO_PRODUCT_NAME "F100"
#endif

#if APP_CONFIG_CUSTOMER_NAME_CURRENT == APP_CONFIG_CUSTOMER_NAME_QTK
#define _APP_CONFIG_CUSTOMER_NAME "QTK"
#elif APP_CONFIG_CUSTOMER_NAME_CURRENT == APP_CONFIG_CUSTOMER_NAME_ELC
#define _APP_CONFIG_CUSTOMER_NAME "ELC"
#else
#define _APP_CONFIG_CUSTOMER_NAME "MOBI"
#endif

#if APP_CONFIG_FUNCTION_NAME_CURRENT == APP_CONFIG_FUNCTION_NAME_NET
#define _APP_CONFIG_FUNCTION_NAME "Net"
#elif APP_CONFIG_FUNCTION_NAME_CURRENT == APP_CONFIG_FUNCTION_NAME_BT
#define _APP_CONFIG_FUNCTION_NAME "Bt"
#elif APP_CONFIG_FUNCTION_NAME_CURRENT == APP_CONFIG_FUNCTION_NAME_NET | APP_CONFIG_FUNCTION_NAME_BT
#define _APP_CONFIG_FUNCTION_NAME "BtNet"
#else
#error Configuration error, please modify macro APP_CONFIG_FUNCTION_NAME_CURRENT in AppConfig.h.
#endif

#if APP_CONFIG_PROTOCOL_NAME_CURRENT == APP_CONFIG_PROTOCOL_NAME_PT
#define _APP_CONFIG_PROTOCOL_NAME "PT"
#elif APP_CONFIG_PROTOCOL_NAME_CURRENT == APP_CONFIG_PROTOCOL_NAME_JT808
#define _APP_CONFIG_PROTOCOL_NAME "JT808"
#elif APP_CONFIG_PROTOCOL_NAME_CURRENT == APP_CONFIG_PROTOCOL_NAME_PT | APP_CONFIG_PROTOCOL_NAME_JT808
#define _APP_CONFIG_PROTOCOL_NAME "JT808_PT"
#else
#error Configuration error, please modify macro APP_CONFIG_FUNCTION_NAME_CURRENT in AppConfig.h.
#endif

#define _APP_VERSION_DATE _APP_VERSION_TO_TEXT1(WT_BUILD_YEAR_4) _APP_VERSION_TO_TEXT1(WT_BUILD_YEAR_3) _APP_VERSION_TO_TEXT1(WT_BUILD_YEAR_2) _APP_VERSION_TO_TEXT1(WT_BUILD_YEAR_1) _APP_VERSION_TO_TEXT1(WT_BUILD_MONTH_2) _APP_VERSION_TO_TEXT1(WT_BUILD_MONTH_1) _APP_VERSION_TO_TEXT1(WT_BUILD_DAY_2) _APP_VERSION_TO_TEXT1(WT_BUILD_DAY_1)

#define APP_VERSION_TINY "V" _APP_VERSION_TO_TEXT3(APP_CONFIG_VERSION_MAJOR,APP_CONFIG_VERSION_MINOR,APP_CONFIG_VERSION_REVISION)
#define APP_VERSION_FULL _APP_VERSION_TO_PRODUCT_NAME "_" _APP_VERSION_DATE "_" _APP_VERSION_TO_TEXT1(WT_BUILD_NUMBER)  "_" _APP_CONFIG_FUNCTION_NAME "_" _APP_CONFIG_CUSTOMER_NAME "_" _APP_CONFIG_PROTOCOL_NAME "_" APP_VERSION_TINY
#define APP_VERSION_NUMBER APP_CONFIG_VERSION_MAJOR << 24 | APP_CONFIG_VERSION_MINOR << 16 | APP_CONFIG_VERSION_REVISION << 8 | APP_CONFIG_VERSION_BUILD
#ifdef __cplusplus
}
#endif
#endif