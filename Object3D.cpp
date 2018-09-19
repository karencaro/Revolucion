#include "stdafx.h"
#include "Object3D.h"
#include<gl/gl.h> //open gl
#include<gl/glaux.h> //funciones auxiliares
#include<gl/glu.h>   //funciones de utilerias


Object3D::Object3D()
{
	color.resize(3);
	color[0]=1.0;
	color[1]=1.0;
	color[2]=1.0;
}


Object3D::~Object3D()
{
}


Object3D Object3D::operator*(Transformation3D t)
{
	Object3D r=(*this);
	Point3D pt;
	//cada vertice se multiplica por la transformacion
	for (int i = 0; i < vert.size(); i++){
		r.vert[i] = vert[i] * t;
	}
	return r;
}


// Agrega un vertice a la matriz de vertices. Devuelve la posicion (indice) del nuevo vertice
int Object3D::AddVertex(Point3D v)
{
	//podemos hacer una usqueda en el vector de vertices para
	//ver si ya existe y no duplicar informacion. Devolveriamos
	//el indice del vertice que encontramos
	vert.push_back(v);
	return vert.size()-1;
}


// Agrega una entrada a la matriz de vetrices, recibe los indices de los vertices correspondientes 
int Object3D::DefineFace(int v1, int v2, int v3, int v4)
{
	vector<int> row(4);
	row[0] = v1;
	row[1] = v2;
	row[2] = v3;
	row[3] = v4;
	caras.push_back(row);
	//agregamos el color actual al vector de colores
	colores.push_back(color);
	return caras.size()-1;
}


int Object3D::DefineFace(int v1, int v2, int v3)
{
	vector<int> row(3);
	row[0] = v1;
	row[1] = v2;
	row[2] = v3;
	caras.push_back(row);
	colores.push_back(color);
	return caras.size() - 1;
}


void Object3D::Display(CDC * pDC,CViewPipeline pl)
{
	float d=500; //para el punto de fuga en proyeccion perspectiva
	//recorremos todas la caras para desplegarlas
	CPoint pp; //punto proyectado

	for (int nf = 0; nf < caras.size(); nf++){
		Point3D v = vert[caras[nf][0]];
		//hacemos proyeccion perspectiva
		pp.x = (long)((v.x / (v.z + d))*d);
		pp.y = (long)((v.y / (v.z + d))*d);


		CPoint vi = pl.World2Device(pp);
		pDC->MoveTo(vi);
		for (int nv = 1; nv < caras[nf].size(); nv++){
			v = vert[caras[nf][nv]];
			pp.x = (long)((v.x / (v.z + d))*d);
			pp.y = (long)((v.y / (v.z + d))*d);
			vi = pl.World2Device(pp);
			pDC->LineTo(vi);
		}
		v = vert[caras[nf][0]];
		pp.x = (long)((v.x / (v.z + d))*d);
		pp.y = (long)((v.y / (v.z + d))*d);
		vi = pl.World2Device(pp);
		pDC->LineTo(vi);
	}

}/*
void Object3D::Display(CDC * pDC, CViewPipeline pl)
{
	float d = 500; //para el punto de fuga en proyeccion perspectiva
	//recorremos todas la caras para desplegarlas
	CPoint pp; //punto proyectado

	for (int nf = 0; nf < caras.size(); nf++){
		Point3D v = vert[caras[nf][0]];
		pp = CPoint(v.x, v.y);


		CPoint vi = pl.World2Device(pp);
		pDC->MoveTo(vi);
		for (int nv = 1; nv < caras[nf].size(); nv++){
			v = vert[caras[nf][nv]];
			pp = CPoint(v.x, v.y);
			vi = pl.World2Device(pp);
			pDC->LineTo(vi);
		}
		v = vert[caras[nf][0]];
		pp = CPoint(v.x, v.y);
		vi = pl.World2Device(pp);
		pDC->LineTo(vi);
	}

}*/


void Object3D::DisplayGL(void)
{
	Point3D v;
	for (int nf = 0; nf < caras.size(); nf++){
		//configuramos el color
		glColor3f(colores[nf][0],colores[nf][1],colores[nf][2]);
		glBegin(GL_POLYGON);
		for (int nv = 0; nv < caras[nf].size(); nv++){
            v = vert[caras[nf][nv]];           
			glVertex3f(v.x,v.y,v.z);
		}
		glEnd();
	}
}

void Object3D::SetColor(float r, float g, float b)
{
	color[0]=r;
	color[1]=g;
	color[2]=b;
}
