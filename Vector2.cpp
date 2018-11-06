#include "stdafx.h"
#include "Vector2.h"

float Vector2::Dist(const Vector2 & V1, const Vector2 & V2)
{
	return sqrtf(DistSquared(V1, V2));
}

float Vector2::DistSquared(const Vector2 & V1, const Vector2 & V2)
{
	float XLength = V2.X - V1.X;
	float YLength = V2.Y - V1.Y;
	return (XLength * XLength) + (YLength * YLength);
}

Vector2 Vector2::operator*(const Matrix2 & Max) const
{
	Vector2 Result;
	Result.X = X * Max._11 + Y * Max._12;
	Result.Y = X * Max._21 + Y * Max._22;
	return Result;
}

//const Vector2 & V : �񱳴�� ��ġ�� �ȵ�
//bool Vector2::Equals(const Vector2 & V, float tolerance) const : get�� ��� ��������
bool Vector2::Equals(const Vector2 & V, float tolerance) const
{
	return (fabs(X - V.X) <= tolerance) && (fabs(Y - V.Y) <= tolerance);
}
