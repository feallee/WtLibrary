#include <stdio.h>
#include <math.h>


float max_color(float r, float g, float b) {
	float ret;
	if (r > g) {
		if (r > b)
			ret = r;
		else
			ret = b;
	}
	else {
		if (g > b)
			ret = g;
		else
			ret = b;
	}
	return ret;
}
float min_color(float r, float g, float b)
{
	float ret;
	if (r < g) {
		if (r < b)
			ret = r;
		else
			ret = b;
	}
	else {
		if (g < b)
			ret = g;
		else
			ret = b;
	}
	return ret;
}

void RGB2HSV(float* h, float* s, float* v, float r, float g, float b)
{
	float z;
	float r1, g1, b1;
	r = r / 256;
	g = g / 256;
	b = b / 256;
	*v = max_color(r, g, b);
	z = min_color(r, g, b);
	if (*v != 0.0)
		*s = (*v - z) / *v;
	else
		*s = 0.0;
	if ((*v - z) != 0) {
		r1 = (*v - r) / (*v - z);
		g1 = (*v - g) / (*v - z);
		b1 = (*v - b) / (*v - z);
	}
	else {
		r1 = 0;
		g1 = 0;
		b1 = 0;
	}
	if (*v == r)
		*h = 60 * (b1 - g1);
	else if (*v == g)
		*h = 60 * (2 + r1 - b1);
	else
		*h = 60 * (4 + g1 - r1);
	if (*h < 0.0)
		*h = *h + 360;
}



int main(void)
{
	float r=147, g=236, b=200, h, s, v;
	RGB2HSV(&h, &s, &v, r, g, b);

	printf("H=%f,S=%f,V=%f\n", h, s, v);
	return 0;
}