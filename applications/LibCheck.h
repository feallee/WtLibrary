/**
 * @brief 检验管理模块。
 * @copyright Copyright(C) 2023 We As Top team. All rights reserved.
 * @section 修订日志
 * 日期         作者                内容
 * -------------------------------------------------------------------------
 * 2024/7/10   feallee@hotmail.com 初版。
 */

#ifndef __LIB_CHECK_H__
#define __LIB_CHECK_H__
#include <stdint.h>
#ifdef __cplusplus
extern "C"
{
#endif
    /// @brief CRC32算法(CRC-32/JAMCRC 0x340BC6D9	0x04C11DB7	0xFFFFFFFF	true	true	0x00000000)。https://crccalc.com/
    /// @param crc 初值。
    /// @param buffer 数据缓冲区。
    /// @param length 数据长度。
    /// @return 返回CRC16-Modbus算法计算结果。
    extern uint32_t LibCheck_CRC32(uint32_t crc, const uint8_t *buffer, uint32_t length);
    /// @brief CRC16算法(CRC-16/MODBUS 0x4B37	0x8005	0xFFFF	true	true	0x0000)。https://crccalc.com/
    /// @param crc 初值。
    /// @param buffer 数据缓冲区。
    /// @param length 数据长度。
    /// @return 返回CRC16-Modbus算法计算结果。
    extern uint16_t LibCheck_CRC16(uint16_t crc, const uint8_t *buffer, uint16_t length);
    /// @brief BCC算法。
    /// @param bcc 初值。
    /// @param buffer 数据缓冲区。
    /// @param length 数据长度。
    /// @return 返回BCC算法计算结果。
    extern uint8_t LibCheck_BCC(uint8_t bcc, const uint8_t *buffer, uint16_t length);
#ifdef __cplusplus
}
#endif
#endif
