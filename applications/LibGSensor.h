#ifndef __WT_GSENSOR_H_
#define __WT_GSENSOR_H_
/// @brief 根据 GSensor 的三轴加速度数据计算pitch和roll角度。
/// @param[in] x X轴加速度数据。
/// @param[in] y Y轴加速度数据。
/// @param[in] z Z轴加速度数据。
/// @param[out] pitch 俯仰角度。
/// @param[out] roll 翻滚角度。
extern void WtGSensor_ComputePitchRoll(double x, double y, double z, double *pitch, double *roll);

#endif
