// ChildView.h : interface of the CChildView class
//


#pragma once
#include<gl/gl.h>
#include<gl/glaux.h>
#include<gl/glu.h>
#include "Object3D.h"

// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:
    CPalette    m_cPalette;
	CPalette    *m_pOldPalette;
	CRect       m_oldRect;
	float       m_fRadius;  //cantidad a trasladar los objetos para que esten visibles
	GLfloat     fNearPlane, fFarPlane; //plano cercano y lejano de recorte
	CClientDC   *m_pDC;
	GLfloat m_camAngleY,m_camAngleX;
	Object3D obj;
// Operations
	void InitGL();
	void CreateRGBPalette(void);
	BOOL bSetupPixelFormat(void);
	unsigned char ComponentFromIndex(int i, UINT nbits, UINT shift);
	void RenderScene(void);
protected:
    CPoint p_anterior;
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRevolucionCapturarpoligono();
};

