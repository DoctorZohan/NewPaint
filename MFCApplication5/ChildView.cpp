
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication5.h"
#include "ChildView.h"
#include "CAddRectangleDlg.h"
#include "CAddCircleDlg.h"
#include "CAddTriangleDlg.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "CTriangle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

const double indent = 25.;
void CChildView::OnPaint() 
{	
	const double csize = theApp.m_canvas->cell_size();
	CPaintDC dc(this); // device context for painting
	for (int i = 0; i < theApp.m_canvas->num_columns(); i++)
		#pragma omp parallel for
		for (int j = 0; j < theApp.m_canvas->num_rows(); j++)
		{
			int color = theApp.m_canvas->getColor(i, j);
			//int blue = color & 255;
			//int green = (color >> 8) & 255;
			//int red = (color >> 16) & 255;
			CBrush brush(color);
			int border_color = theApp.m_canvas->getSelect(i, j) ? 0xFFFF : 0;
			CPen pen(PS_SOLID, 1, border_color);
			dc.SelectObject(brush);
			dc.SelectObject(pen);
			dc.Rectangle(indent + csize * i , indent + csize * j, indent + csize * (i + 1), indent + csize * (j + 1));
		}
}


void CChildView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	const double csize = theApp.m_canvas->cell_size();
	// TODO: Add your message handler code here and/or call default
	int x = (point.x - indent) / csize;
	int y = (point.y - indent) / csize;
	Shape* object = theApp.m_canvas->get_shape_with_current_point(x, y);
	if (!object)
		return;
	switch (object->get_shape_type())
	{
		case shape_type::rectangle:
		{
			CRectangle* rect = (CRectangle*)object;
			CAddRectangleDlg Dlg;
			Dlg.m_strDlgCaption = _T("Change Rectangle");
			Dlg.posX(rect->posX());
			Dlg.posY(rect->posY());
			Dlg.length(rect->length());
			Dlg.width(rect->width());
			int result = Dlg.DoModal();
			if (result == IDOK)
			{
				theApp.m_canvas->select_object(rect, true);
				theApp.m_canvas->removeObject(rect);
				CRectangle* rect2 = new CRectangle(Dlg.posX(), Dlg.posY(), Dlg.length(), Dlg.width(), Dlg.color());
				if (!theApp.m_canvas->addObject(rect2))
				{
					AfxMessageBox(L"This shape should be inside canvas and do not intersect with other shapes");
					RedrawWindow();
					delete rect2;
					return;
				}
				RedrawWindow();
			}
			break;
		}
		case shape_type::circle :
		{
			CCircle* circle = (CCircle*)object;
			CAddCircleDlg cirDlg;
			cirDlg.m_strDlgCaption = _T("Change Circle");
			cirDlg.posX(circle->posX());
			cirDlg.posY(circle->posY());
			cirDlg.radious(circle->radious());
			int result = cirDlg.DoModal();
			if (result == IDOK)
			{
				theApp.m_canvas->select_object(circle, true);
				theApp.m_canvas->removeObject(circle);
				CCircle* rect2 = new CCircle(cirDlg.posX(), cirDlg.posY(), cirDlg.radious(), cirDlg.color());
				if (!theApp.m_canvas->addObject(rect2))
				{
					AfxMessageBox(L"This shape should be inside canvas and do not intersect with other shapes");
					RedrawWindow();
					delete rect2;
					return;
				}
				RedrawWindow();
			}
			break;
		}
		case shape_type::triangle :
		{
			CTriangle* tri = (CTriangle*)object;
			CAddTriangleDlg Dlg;
			Dlg.m_strDlgCaption = _T("Change Triangle");
			Dlg.x1(tri->x1());
			Dlg.y1(tri->y1());
			Dlg.x2(tri->x2());
			Dlg.y2(tri->y2());
			Dlg.x3(tri->x3());
			Dlg.y3(tri->y3());
			Dlg.color(tri->color());
			int result = Dlg.DoModal();
			if (result == IDOK)
			{
				theApp.m_canvas->select_object(tri, true);
				theApp.m_canvas->removeObject(tri);
				CTriangle* obj2 = new CTriangle(Dlg.x1(), Dlg.y1(), Dlg.x2(), Dlg.y2(), Dlg.x3(), Dlg.y3(), Dlg.color());
				if (!theApp.m_canvas->addObject(obj2))
				{
					AfxMessageBox(L"This shape should be inside canvas and do not intersect with other shapes");
					RedrawWindow();
					delete obj2;
					return;
				}
				RedrawWindow();
			}
			break;
		}
		default: break;

	}
	CWnd::OnLButtonDblClk(nFlags, point);
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	Shape* old_object = theApp.m_canvas->get_current_select_object();
	if (old_object)
		theApp.m_canvas->select_object(old_object, false);
	const double csize = theApp.m_canvas->cell_size();
	int x = (point.x - indent) / csize;
	int y = (point.y - indent) / csize;
	Shape* object = theApp.m_canvas->get_shape_with_current_point(x, y);
	if (!object)
	{
		if (old_object)
			RedrawWindow();
		return;
	}
	theApp.m_canvas->select_object(object, true);
	RedrawWindow();
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CWnd::OnLButtonUp(nFlags, point);
}
