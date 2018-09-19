#pragma once
#include "viewpipeline.h"
#include <vector>
#include "afxwin.h"
using std::vector;

// CPolyCaptureDlg dialog

class CPolyCaptureDlg : public CDialog
{
	DECLARE_DYNAMIC(CPolyCaptureDlg)

public:
	CPolyCaptureDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CPolyCaptureDlg();

// Dialog Data
	enum { IDD = IDD_POLYCAPTURE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();

	CViewPipeline m_pipeline;
	vector<CPoint> points_dev;
	vector<CRect> handles;

	int selected;
	
	vector<CPoint> GetPoints(void);
};
