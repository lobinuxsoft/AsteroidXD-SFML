#include "maths_utils.h"

float Clamp(float value, float min, float max)
{
	const float res = value < min ? min : value;
	return res > max ? max : res;
}

int Clamp(int value, int min, int max)
{
	const int res = value < min ? min : value;
	return res > max ? max : res;
}
