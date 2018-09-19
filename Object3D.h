#pragma once
#include"Point3D.h"
#include"ViewPipeline.h"
#include <vector>
using std::vector;

class Object3D
{
	//vector de vertices
	vector<Point3D>  vert;
	vector<vector<int>> caras;
	vector<vector<float>> colores;
	vector<float> color;//color de la cara que se agrega

public:
	Object3D();
	~Object3D();
	Object3D operator*(Transformation3D t);
	// Agrega un vertice a la matriz de vertices. Devuelve la posicion (indice) del nuevo vertice
	int AddVertex(Point3D v);
	// Agrega una entrada a la matriz de vetrices, recibe los indices de los vertices correspondientes 
	int DefineFace(int v1, int v2, int v3, int v4);
	int DefineFace(int v1, int v2, int v3);
	void Display(CDC * pDC,CViewPipeline pl);
	void DisplayGL(void);
	void SetColor(float r, float g, float b);
};

