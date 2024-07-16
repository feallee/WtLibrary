#ifndef __LIB_GSENSOR_H_
#define __LIB_GSENSOR_H_
#ifdef __cplusplus
extern "C"
{
#endif
    /// @brief 计算三轴归一化加速度数据。
    /// @param[in] x X轴加速度数据。
    /// @param[in] y Y轴加速度数据。
    /// @param[in] z Z轴加速度数据。
    /// @return 三轴归一化加速度数据。
    extern double LibGSensor_GetNormalized(double x, double y, double z);
    /// @brief 根据 GSensor 的三轴加速度数据计算pitch和roll角度。
    /// @param[in] x X轴加速度数据。
    /// @param[in] y Y轴加速度数据。
    /// @param[in] z Z轴加速度数据。
    /// @param[out] pitch 俯仰角度。
    /// @param[out] roll 翻滚角度。
    extern void LibGSensor_GetPitchRoll(double x, double y, double z, double *pitch, double *roll);
#ifdef __cplusplus
}
#endif
#endif
