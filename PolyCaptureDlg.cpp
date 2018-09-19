// PolyCaptureDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Revolucion.h"
#include "PolyCaptureDlg.h"


// CPolyCaptureDlg dialog

IMPLEMENT_DYNAMIC(CPolyCaptureDlg, CDialog)

CPolyCaptureDlg::CPolyCaptureDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPolyCaptureDlg::IDD, pParent)
{
	m_pipeline.SetViewport(CRect(10,10,409,309));
	m_pipeline.SetWindow(CRect(-10000,10000,10000,-10000));
	selected=-1;
}

CPolyCaptureDlg::~CPolyCaptureDlg()
{
}

void CPolyCaptureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	
}


BEGIN_MESSAGE_MAP(CPolyCaptureDlg, CDialog)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CPolyCaptureDlg message handlers

void CPolyCaptureDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	//CDialog::OnLButtonDblClk(nFlags, point);
	points_dev.push_back(point);
	handles.push_back(CRect(point.x-3,point.y-3,point.x+3,point.y+3));
	RedrawWindow();
	
}

void CPolyCaptureDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	//CDialog::OnLButtonDown(nFlags, point);
	for(int i=0;i<handles.size();i++){
		if(handles[i].PtInRect(point)){
			selected=i;
			return;
		}
	}

}

void CPolyCaptureDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	//CDialog::OnLButtonUp(nFlags, point);
	selected=-1;
}

void CPolyCaptureDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	//CDialog::OnMouseMove(nFlags, point);
	if(selected>=0){
		handles[selected].MoveToXY(point.x-3,point.y-3);
		points_dev[selected]=handles[selected].CenterPoint();
		RedrawWindow(m_pipeline.GetViewport());
	}
}

void CPolyCaptureDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
    // Do not call CDialog::OnPaint() for painting messages
	//CPaintDC dc(&m_drawarea_ctl);
	//m_pipeline.
	dc.SelectStockObject(DC_PEN);
	dc.SetDCPenColor(RGB(128,128,128));
	
	dc.SelectStockObject(WHITE_BRUSH);
	dc.Rectangle(CRect(10,10,409,309));
	//dc.MoveTo(0,0);
	//dc.LineTo(100,100);
	dc.SetDCPenColor(RGB(200,200,200));
	dc.MoveTo(m_pipeline.World2Device(CPoint(0,-10000)));
	dc.LineTo(m_pipeline.World2Device(CPoint(0,10000)));
	dc.MoveTo(m_pipeline.World2Device(CPoint(-10000,0)));
	dc.LineTo(m_pipeline.World2Device(CPoint(10000,0)));
	//dibuja handles
	dc.SelectStockObject(DC_BRUSH);
	
	if(points_dev.size()<1)return;
	int i;
	dc.SetDCPenColor(RGB(128,128,128));
	dc.SetDCBrushColor(RGB(128,128,128));
	for(i=0;i<handles.size();i++){
		dc.Rectangle(handles[i]);
	}
	dc.SetDCPenColor(RGB(0,0,0));
	dc.MoveTo(points_dev[0]);
	for(i=1;i<points_dev.size();i++){
		dc.LineTo(points_dev[i]);
	}
}

vector<CPoint> CPolyCaptureDlg::GetPoints(void)
{
	vector<CPoint> points;
	for(int i=0;i<points_dev.size();i++)
		points.push_back(m_pipeline.Device2World(points_dev[i]));
	return points;
}
