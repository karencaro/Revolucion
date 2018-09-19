#pragma once
class Transformation3D
{
	
	
public:
	float matrix[4][4];
	Transformation3D();
	~Transformation3D();
	Transformation3D operator*(Transformation3D t2);
	static Transformation3D GetScaling(float s);
	static Transformation3D GetTranslation(float tx, float ty, float tz);
	static Transformation3D GetRotationX(float deg);
	static Transformation3D GetRotationY(float deg);
	static Transformation3D GetRotationZ(float deg);
};

