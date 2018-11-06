#pragma once

#include "Vector.h"

struct IntPoint
{
public:
	int X;
	int Y;

public:
	IntPoint() : X(0), Y(0) {}
	IntPoint(int InX, int InY) : X(InX), Y(InY) {}
	IntPoint(Vector2 InVector2) : X(InVector2.X), Y(InVector2.Y) {}
	IntPoint(Vector3 InVector3) : X(InVector3.X), Y(InVector3.Y) {}

	Vector2 ToVector2() { return Vector2((float)X, (float)Y); }
	Vector3 ToVector3() { return Vector3((float)X, (float)Y,1); }
};