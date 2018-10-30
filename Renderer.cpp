
#include "stdafx.h"
#include "SoftRenderer.h"
#include "GDIHelper.h"
#include "Renderer.h"

#include "Vector.h"
#include "IntPoint.h"

bool IsInRange(int x, int y);
void PutPixel(int x, int y);

bool IsInRange(int x, int y)
{
	return (abs(x) < (g_nClientWidth / 2)) && (abs(y) < (g_nClientHeight / 2));
}

void PutPixel(const IntPoint &InPt)
{
	PutPixel(InPt.X, InPt.Y);
}

void PutPixel(int x, int y)
{
	if (!IsInRange(x, y)) return;

	ULONG* dest = (ULONG*)g_pBits;
	DWORD offset = g_nClientWidth * g_nClientHeight / 2 + g_nClientWidth / 2 + x + g_nClientWidth * -y;
	*(dest + offset) = g_CurrentColor;
}


void UpdateFrame(void)
{
	// Buffer Clear
	//SetColor(32, 128, 255);
	SetColor(0, 0, 0);
	Clear();

	// Draw
	//SetColor(255, 0, 0);
	SetColor(0, 255, 0);	//´«ÀÌ ³Ê¹« ¾ÆÇÁ´Ù..
	//PutPixel(0, 0);	//ÇÈ¼¿¿¡ Á¡Âï±á

	// Draw Circle with radius 100
	Vector2 center(0.0f, 0.0f);
	float radius = 100.0f;
	float nradius = (int)radius;

	static float degree = 0;
	degree += 0.1f;
	degree = fmodf(degree, 360.0f);

	Matrix2 rotMat;
	rotMat.SetRotation(degree);

	for (int i = -nradius; i < nradius; i++)
	{
		for (int j = -nradius; j < nradius; j++)
		{
			PutPixel(Vector2(i, j) * rotMat);
		}
	}


	/*for (int i = 0; i < 360; i++)
	{
		Matrix2 rotMat;
		rotMat.SetRotation((float)i);
		PutPixel(StartVec * rotMat);
	}*/

	//Matrix2 ScaleMat;
	//ScaleMat.SetScale(2.0f, 0.5f);

	//Matrix2 RotMat;
	//RotMat.SetRotation(30.0f);

	//Matrix2 SRMat = ScaleMat * RotMat;
	//Matrix2 RSMat = RotMat * ScaleMat;

	//-x~x
	/*for (int i = -nradius; i <= nradius; i++)
	{
		for (int j = -nradius; j <= nradius; j++)
		//for (int j = 0; j <= nradius; j++)
		{
			IntPoint pt(i, j);
			Vector2 ptVec = pt.ToVector2();
			if (Vector2::DistSquared(center, ptVec) <= radius * radius)
			{
			//	IntPoint saclePt(ptVec * ScaleMat);
			//	IntPoint RotationPt(ptVec * RotMat);
			//	IntPoint SRPt(ptVec * SRMat);
			//	IntPoint RSPt(ptVec * RSMat);
				PutPixel(pt);
			}
		}
	}*/

	// Buffer Swap 
	BufferSwap();	//¾ËÇÊ¿äx
}
