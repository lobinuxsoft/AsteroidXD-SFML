#pragma once
#include <cmath>

#ifndef PI
#define PI 3.14159265358979323846f
#endif

#define DEG2RAD (PI/180.0f)
#define RAD2DEG (180.0f/PI)

float Clamp(float value, float min, float max);
int Clamp(int value, int min, int max);