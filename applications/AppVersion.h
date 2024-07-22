/**
 * @brief 应用程序版本管理。
 * @copyright Copyright(C) 2023 We as Top team. All rights reserved.
 * @section 修订日志
 * 日期         作者                内容
 * -------------------------------------------------------------------------
 * 2023/11/30   feallee@hotmail.com 初版。
 */
#ifndef __APP_VERSION_H_
#define __APP_VERSION_H_
#include "WtBuild.h"

/// @brief 产品名称。// TODO
#define APP_VERSION_PRODUCT_NAME "LGL"
/// @brief 网络制式。如 2G/3G/4G/5G/6G/NB/CAT1/CAT4/... // TODO
#define APP_VERSION_PRODUCT_NETWORK "4G"
/// @brief 客户标识。如 QTK/ELC/MOBI/... // TODO
#define APP_VERSION_PRODUCT_CUSTOMER "MOBI"
/// @brief 功能特性。如 General/Alarm/Security/... // TODO
#define APP_VERSION_PRODUCT_FUNCTION "General"
/// @brief 通信协议。如 PT/JT808/... // TODO
#define APP_VERSION_PRODUCT_PROTOCOL "PT"

/// @brief 主要版本号。如 0 to 999。// TODO
#define APP_VERSION_MAJOR 1 // WT_BUILD_VERSION_MAJOR
/// @brief 次要版本号。如 0 to 999。// TODO
#define APP_VERSION_MINOR 0 // WT_BUILD_VERSION_MINOR
/// @brief 构建版本号。如 0 to 999。// TODO
#define APP_VERSION_BUILD WT_BUILD_NUMBER

#define APP_VERSION_TO_TEXT(v) #v
#define APP_VERSION_TO_TEXT3(a, b, c) APP_VERSION_TO_TEXT(a.b.c)
#define APP_VERSION_TO_TEXT1(a) APP_VERSION_TO_TEXT(a)
#define APP_VERSION_DATE                   \
    APP_VERSION_TO_TEXT1(WT_BUILD_YEAR_2)  \
    APP_VERSION_TO_TEXT1(WT_BUILD_YEAR_1)  \
    APP_VERSION_TO_TEXT1(WT_BUILD_MONTH_2) \
    APP_VERSION_TO_TEXT1(WT_BUILD_MONTH_1) \
    APP_VERSION_TO_TEXT1(WT_BUILD_DAY_2)   \
    APP_VERSION_TO_TEXT1(WT_BUILD_DAY_1)

/// @brief 版本号标量数值，如 1000001。
#define APP_VERSION_NUMBER APP_VERSION_MAJOR * 1000000 + APP_VERSION_MINOR * 1000 + APP_VERSION_BUILD
/// @brief 版本号紧凑字符串，如 V1.0.1。
#define APP_VERSION_TINY "V" APP_VERSION_TO_TEXT3(APP_VERSION_MAJOR, APP_VERSION_MINOR, APP_VERSION_BUILD)
/// @brief 版本号完整字符串，如 LGL_240311_4G_MOBI_General_PT_V1.0.1。
#define APP_VERSION_FULL \
    APP_VERSION_PRODUCT_NAME "_" APP_VERSION_DATE "_" APP_VERSION_PRODUCT_NETWORK "_" APP_VERSION_PRODUCT_CUSTOMER "_" APP_VERSION_PRODUCT_FUNCTION "_" APP_VERSION_PRODUCT_PROTOCOL "_" APP_VERSION_TINY
#endif