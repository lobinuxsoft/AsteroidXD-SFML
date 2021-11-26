#pragma once
#include "my_utils/maths_utils.h"

#include "SFML/Graphics.hpp"

using namespace sf;

/// <summary>
/// Angulo que se genera con 2 vetores
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns></returns>
float Vector2Angle(Vector2f v1, Vector2f v2);

/// <summary>
/// Calcula la distancia entre 2 vectores
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns></returns>
float Vector2Distance(Vector2f v1, Vector2f v2);

/// <summary>
/// El largo del vector o la magnitud
/// </summary>
/// <param name="v"></param>
/// <returns></returns>
float Vector2Length(Vector2f v);

/// <summary>
/// Escalar el vector
/// </summary>
/// <param name="v"></param>
/// <param name="scale"></param>
/// <returns></returns>
Vector2f Vector2Scale(Vector2f v, float scale);

/// <summary>
/// Normalizar el vector
/// </summary>
/// <param name="v"></param>
/// <returns></returns>
Vector2f Vector2Normalize(Vector2f v);

/// <summary>
/// Suma entre 2 vectores
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns></returns>
Vector2f Vector2Add(Vector2f v1, Vector2f v2);

/// <summary>
/// Resta entre 2 vectores
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns></returns>
Vector2f Vector2Subtract(Vector2f v1, Vector2f v2);