#pragma once
#include "Transformation3D.h"

//Clase para manejo de puntos en 3D
//el Punto 3D tambien puede ser considerado un vector en 3D
//Autor: Sergio Infanfe
//Facultad de Ingenieria, Arquitectura y Disenio, UABC
//Graficacion
class Point3D
{

public:
	float x,y,z;  //componentes del punto o vecto
	Point3D(void);
	Point3D(float x,float y, float z);
	~Point3D(void);
    //Desarrolla producto cruz entre el punto y la matriz de transformacion recibida como parametro
	Point3D operator*(Transformation3D mult);
	//Desarrolla el producto cruz(vectorial) entre este vector(punto) y el vector recibido como parametro
	//el resultado es devuelto como un nuevo vector
	Point3D operator*(Point3D mult); 
	//suma de vectores, el resultado es devuelto como un nuevo vector
	Point3D operator+(Point3D p2);
    //suma de vectores, el resultado es almacenado en este vector
	void operator+=(Point3D p2);
	//diferencia entre 2 puntos
	void operator-=(Point3D p2);
	Point3D operator-(Point3D p2);
	//normal de los vectores v1-v2,v3-v2
	static Point3D Normal(Point3D v1,Point3D v2,Point3D v3);
	//comparacion entre este punto y el punto recibido como parametro
	bool operator==(Point3D compareto);
	
};
