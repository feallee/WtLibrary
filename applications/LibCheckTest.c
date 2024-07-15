#include <stdio.h>
#include "LibCheck.h"
#include "LibCheckTest.h"
void LibCheckTest_Run(void)
{
    uint8_t buf1[] = {1, 2, 3, 4}, buf2[] = {5, 6, 7, 8}, buf3[] = {1, 2, 3, 4, 5, 6, 7, 8};

    uint32_t crc32 = 0xffffffff;
    crc32 = LibCheck_CRC32(crc32, buf1, sizeof(buf1));
    printf("crc32_1:%08lX\n", crc32);
    crc32 = LibCheck_CRC32(crc32, buf2, sizeof(buf2));
    printf("crc32_2:%08lX\n", crc32);
    crc32 = LibCheck_CRC32(0xffffffff, buf3, sizeof(buf3));
    printf("crc32_3:%08lX\n", crc32);

    uint16_t crc16 = 0xffff;
    crc16 = LibCheck_CRC16(crc16, buf1, sizeof(buf1));
    printf("crc16_1:%04X\n", crc16);
    crc16 = LibCheck_CRC16(crc16, buf2, sizeof(buf2));
    printf("crc16_2:%04X\n", crc16);
    crc16 = LibCheck_CRC16(0xffff, buf3, sizeof(buf3));
    printf("crc16_3:%04X\n", crc16);

    uint8_t bcc = 0;
    bcc = LibCheck_BCC(bcc, buf3, sizeof(buf3));
    printf("bcc:%02X\n", bcc);
}