#include "vector2_utils.h"

float Vector2Angle(Vector2f v1, Vector2f v2)
{
    float result = atan2f(v2.y - v1.y, v2.x - v1.x) * (180.0f / PI);
    if (result < 0) result += 360.0f;
    return result;
}

float Vector2Distance(Vector2f v1, Vector2f v2)
{
    return sqrtf((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
}

float Vector2Length(Vector2f v)
{
    return sqrtf((v.x * v.x) + (v.y * v.y));
}

Vector2f Vector2Scale(Vector2f v, float scale)
{
    return Vector2f( v.x * scale, v.y * scale );
}

Vector2f Vector2Normalize(Vector2f v)
{
    float length = Vector2Length(v);
    if (length <= 0)
        return v;

    return Vector2Scale(v, 1 / length);
}

Vector2f Vector2Add(Vector2f v1, Vector2f v2)
{
    return Vector2f( v1.x + v2.x, v1.y + v2.y );
}

Vector2f Vector2Subtract(Vector2f v1, Vector2f v2)
{
    return Vector2f(v1.x - v2.x, v1.y - v2.y);
}
