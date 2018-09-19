#include "StdAfx.h"
#include "Point3D.h"
#include <cmath>

//Implementacion de la clase para manejo de puntos en 3D
//Autor: Sergio Infanfe
//Facultad de Ingenieria, Arquitectura y Disenio, UABC
//Graficacion

//construye un punto en el origen
Point3D::Point3D(void)
{
	x=0.0f;y=0.0f;z=0.0f;
}
//construye un punto con los componentes especificados
//Parametros:
//			x.-componente x
//			y.-componente y
//			z.-componente y

Point3D::Point3D(float x,float y,float z)
{
	this->x=x;this->y=y;this->z=z;
}
Point3D::~Point3D(void)
{
}

//Multiplica este punto por una matriz de transformacion y devuelve el resultado como un punto nuevo
//Parametros:
//			mult.-Transformacion con la matriz a multiplicar por este punto

Point3D Point3D::operator*(Transformation3D mult){
	Point3D res;
	res.x=x*mult.matrix[0][0]+y*mult.matrix[0][1]+z*mult.matrix[0][2]+mult.matrix[0][3];
	res.y=x*mult.matrix[1][0]+y*mult.matrix[1][1]+z*mult.matrix[1][2]+mult.matrix[1][3];
	res.z=x*mult.matrix[2][0]+y*mult.matrix[2][1]+z*mult.matrix[2][2]+mult.matrix[2][3];
	return res;
}

//Calcula el producto vectorial entre este vector (punto) y el especificado como parametro.
//Devuelve el resultado como un nuevo vector
//Parametros:
//			mult.- Vector a multiplicar por este vector
Point3D Point3D::operator*(Point3D mult){
	Point3D res;
	res.x=y*mult.z-z*mult.y;
	res.y=z*mult.x-x*mult.z;
	res.z=x*mult.y-y*mult.x;
	return res;
}
//Calcula la suma de este punto o vector con un segundo punto.
//Devuelve el resultado como un nuevo punto
//Parametros:
//			p2.- punto a sumar a este punto
Point3D Point3D::operator+(Point3D p2){
	Point3D res;
	res.x=x+p2.x;
	res.y=y+p2.y;
	res.z=z+p2.z;
	return res;
}
//Calcula la suma de este punto o vector con un segundo punto.
//El resultado es acumulado en este punto
//Parametros:
//			p2.- punto a sumar a este punto
void Point3D::operator+=(Point3D p2){
	
	x+=p2.x;
	y+=p2.y;
	z+=p2.z;
	
}
//Calcula la diferencia de este punto o vector con un segundo punto.
//El resultado es acumulado en este punto
//Parametros:
//			p2.- punto a restar a este punto

void Point3D::operator-=(Point3D p2){
	
	x-=p2.x;
	y-=p2.y;
	z-=p2.z;
	
}
//Calcula la diferencia de este punto o vector con un segundo punto.
//Devuelve el resultado como un nuevo punto
//Parametros:
//			p2.- punto a restar a este punto

Point3D Point3D::operator-(Point3D p2){
	Point3D res;
	res.x=x-p2.x;
	res.y=y-p2.y;
	res.z=z-p2.z;
	return res;
}

//Calcula un vector normal entre dos vectores.
//El primer vector va del punto v1 a v2,y el segundo de v3 a v2
//El resultado es devuelto como un nuevo punto
//Parametros
//			v1,v2,v3.- los puntos para especificar los vectores. 
//			           El primer vector va del punto v1 a v2,y el segundo de v3 a v2
Point3D Point3D::Normal(Point3D v1,Point3D v2,Point3D v3){
	Point3D res,aux,V1,V2;
	float magn;
	V1=v1-v2;
	V2=v3-v2;
	aux=V1*V2;
	magn=sqrt(aux.x*aux.x+aux.y*aux.y+aux.z*aux.z);
	res.x=aux.x/magn;
	res.y=aux.y/magn;
	res.z=aux.z/magn;
	return res;
}

//Compara este punto o vector con un segundo punto
//Devuelve verdadero si ambos son iguales
//Parametros:
//			compareto.- Punto a comparar con este punto
bool Point3D::operator==(Point3D compareto)
{
	if(x==compareto.x&&y==compareto.y&&z==compareto.z)
		return true;
	return false;
}

