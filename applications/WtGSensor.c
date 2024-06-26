#include <math.h>
#define M_PI 3.14159265358979323846

void WtGSensor_ComputePitchRoll(double x, double y, double z, double *pitch, double *roll)
{
    // 归一化gsensor数据（如果数据不是单位向量）
    double norm = sqrt(x * x + y * y + z * z);
    if (norm > 0.0)
    {
        x /= norm;
        y /= norm;
        z /= norm;
    }

    // 计算俯仰角和翻滚角（以弧度为单位）
    // 假设z轴是垂直方向（正值向上），x轴是设备宽度方向，y轴是设备前后方向
    *pitch = atan2(-y, sqrt(x * x + z * z)); // 设备绕其y轴旋转的角度。注意：这里使用-y，因为通常z轴向上时y轴向前是负值
    *roll = atan2(x, z);                     // 设备绕其x轴旋转的角度。

    // 将弧度转换为度
    *pitch = *pitch * (180 / M_PI);
    *roll = *roll * (180 / M_PI);
}