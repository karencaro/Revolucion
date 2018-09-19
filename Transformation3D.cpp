#include "stdafx.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include "Transformation3D.h"


Transformation3D::Transformation3D()
{
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++)
			matrix[i][j] = 0;
	}
	for (int i = 0; i < 4; i++)
		matrix[i][i] = 1;

}


Transformation3D::~Transformation3D()
{
}


Transformation3D Transformation3D::operator*(Transformation3D t2)
{
	Transformation3D r;//resultado
	int i, j, k;
	for (i = 0; i < 4; i++)
		r.matrix[i][i] = 0;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			for (k = 0; k < 4; k++)
				r.matrix[i][k] += matrix[i][j] * t2.matrix[j][k];
	return r;
}


Transformation3D Transformation3D::GetScaling(float s)
{
	Transformation3D t;
	t.matrix[0][0] = t.matrix[1][1] = t.matrix[2][2] =  s;
	return t;
}


Transformation3D Transformation3D::GetTranslation(float tx, float ty, float tz)
{  
	Transformation3D t;
	t.matrix[4][0] = tx;
	t.matrix[4][1] = ty;
	t.matrix[4][2] = tz;
	return t;
}


Transformation3D Transformation3D::GetRotationX(float deg)
{
	Transformation3D t;
	double sx = sin(deg*M_PI / 180);
	double cx = cos(deg*M_PI / 180);
	t.matrix[1][1] = cx;
	t.matrix[1][2] = sx;
	t.matrix[2][1] = -sx;
	t.matrix[2][2] = cx;
	return t;
}
Transformation3D Transformation3D::GetRotationY(float deg)
{
	Transformation3D t;
	double sx = sin(deg*M_PI / 180);
	double cx = cos(deg*M_PI / 180);
	t.matrix[0][0] = cx;
	t.matrix[2][0] = -sx;
	t.matrix[0][2] = sx;
	t.matrix[2][2] = cx;
	return t;
}
Transformation3D Transformation3D::GetRotationZ(float deg)
{
	Transformation3D t;
	double sx = sin(deg*M_PI / 180);
	double cx = cos(deg*M_PI / 180);
	t.matrix[0][0] = cx;
	t.matrix[0][1] = sx;
	t.matrix[1][0] = -sx;
	t.matrix[1][1] = cx;
	return t;
}
