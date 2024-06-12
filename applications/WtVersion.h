/**
 * @brief 应用程序版本管理。
 * @copyright Copyright(C) 2023 We as Top team. All rights reserved.
 * @section 修订日志
 * 日期         作者                内容
 * -------------------------------------------------------------------------
 * 2023/11/30   feallee@hotmail.com 初版。
 */
#ifndef __WT_VERSION_H_
#define __WT_VERSION_H_
#include "WtBuild.h"

/// @brief 产品名称。
#define WT_VERSION_PRODUCT_NAME "LGL" // TODO: 产品名称
/// @brief 网络制式。
#define WT_VERSION_PRODUCT_NETWORK "4G" // TODO: 网络制式，如 2G/3G/4G/5G/6G/NB/CAT1/CAT4/...
/// @brief 客户标识。
#define WT_VERSION_PRODUCT_CUSTOMER "MOBI" // TODO: 客户标识，如 QTK/ELC/MOBI/...
/// @brief 功能特性。
#define WT_VERSION_PRODUCT_FUNCTION "General" // TODO: 功能特性，如 General/Alarm/Security/...
/// @brief 通信协议。
#define WT_VERSION_PRODUCT_PROTOCOL "PT" // TODO: 通信协议，如 PT/JT808/...

/// @brief 主要版本号。
#define WT_VERSION_MAJOR 1 // TODO: 0 to 4293
/// @brief 次要版本号。
#define WT_VERSION_MINOR 0 // TODO: 0 to 999
/// @brief 修订版本号。
#define WT_VERSION_REVISION 1 // TODO: 0 to 999

#define WT_VERSION_TO_TEXT(v) #v
#define WT_VERSION_TO_TEXT3(a, b, c) WT_VERSION_TO_TEXT(a.b.c)
#define WT_VERSION_TO_TEXT1(a) WT_VERSION_TO_TEXT(a)
#define WT_VERSION_BUILD_DATE             \
    WT_VERSION_TO_TEXT1(WT_BUILD_YEAR_2)  \
    WT_VERSION_TO_TEXT1(WT_BUILD_YEAR_1)  \
    WT_VERSION_TO_TEXT1(WT_BUILD_MONTH_2) \
    WT_VERSION_TO_TEXT1(WT_BUILD_MONTH_1) \
    WT_VERSION_TO_TEXT1(WT_BUILD_DAY_2)   \
    WT_VERSION_TO_TEXT1(WT_BUILD_DAY_1)

/// @brief 版本号标量数值。如：1000001。
#define WT_VERSION_NUMBER WT_VERSION_MAJOR * 1000000 + WT_VERSION_MINOR * 1000 + WT_VERSION_REVISION
/// @brief 版本号紧凑字符串。如：V1.0.1。
#define WT_VERSION_TINY "V" WT_VERSION_TO_TEXT3(WT_VERSION_MAJOR, WT_VERSION_MINOR, WT_VERSION_REVISION)
/// @brief 版本号完整字符串。如：LGL_240311_4G_MOBI_General_PT_V1.0.1。
#define WT_VERSION_FULL \
    WT_VERSION_PRODUCT_NAME "_" WT_VERSION_BUILD_DATE "_" WT_VERSION_PRODUCT_NETWORK "_" WT_VERSION_PRODUCT_CUSTOMER "_" WT_VERSION_PRODUCT_FUNCTION "_" WT_VERSION_PRODUCT_PROTOCOL "_" WT_VERSION_TINY
#endif