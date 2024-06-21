#include <math.h>
#define M_PI 3.14159265358979323846

void WtGSensor_ComputePitchRoll(double x, double y, double z, double *pitch, double *roll)
{
    // ��һ��gsensor���ݣ�������ݲ��ǵ�λ������
    double norm = sqrt(x * x + y * y + z * z);
    if (norm > 0.0)
    {
        x /= norm;
        y /= norm;
        z /= norm;
    }

    // ���㸩���Ǻͷ����ǣ��Ի���Ϊ��λ��
    // ����z���Ǵ�ֱ������ֵ���ϣ���x�����豸��ȷ���y�����豸ǰ����
    *pitch = atan2(-y, sqrt(x * x + z * z)); // �豸����y����ת�ĽǶȡ�ע�⣺����ʹ��-y����Ϊͨ��z������ʱy����ǰ�Ǹ�ֵ
    *roll = atan2(x, z);                     // �豸����x����ת�ĽǶȡ�

    // ������ת��Ϊ��
    *pitch = *pitch * (180 / M_PI);
    *roll = *roll * (180 / M_PI);
}