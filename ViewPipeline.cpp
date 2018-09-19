#include "StdAfx.h"
#include "ViewPipeline.h"

CViewPipeline::CViewPipeline(void)
{
	m_ventana=CRect(-10000,10000,10000,-10000);
	m_pdv=CRect(0,0,640,480);
	CalcularEscalamiento();
}

CViewPipeline::~CViewPipeline(void)
{
}

void CViewPipeline::SetWindow(CRect nueva_ventana)
{
	m_ventana=nueva_ventana;
	CalcularEscalamiento();
}

void CViewPipeline::SetViewport(CRect nuevo_pdv)
{
	m_pdv=nuevo_pdv;
	CalcularEscalamiento();
}

CPoint CViewPipeline::World2Device(CPoint p)
{
	CPoint pt;
	pt.x=(long)((float)(p.x-m_ventana.left)*sx+0.5)+m_pdv.left;
	pt.y=(long)((float)(p.y-m_ventana.bottom)*sy+0.5)+m_pdv.bottom;
	return pt;
}

void CViewPipeline::CalcularEscalamiento(void)
{
	sx=(float)(m_pdv.right-m_pdv.left)/(float)(m_ventana.right-m_ventana.left);
	sy=(float)(m_pdv.top-m_pdv.bottom)/(float)(m_ventana.top-m_ventana.bottom);
}


CPoint CViewPipeline::Device2World(CPoint p)
{
	CPoint pt;
	pt.x=(long)(((float)(p.x-m_pdv.left)/sx)+0.5)+m_ventana.left;
	pt.y=(long)(((float)(p.y-m_pdv.bottom)/sy)+0.5)+m_ventana.bottom;
	return pt;
}
