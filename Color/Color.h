#ifndef __COLOR_H_
#define __COLOR_H_
typedef struct
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
}color_rgb_t;
typedef struct
{
	unsigned char H;
	unsigned char S;
	unsigned char V;
}color_hsv_t;

void rgb2hsv(const color_rgb_t* rgb, color_hsv_t* hsv);
void hsv2rgb(const color_hsv_t* hsv, color_rgb_t* rgb);
#endif