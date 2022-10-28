// CAddRectangleDlg.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication5.h"
#include "CAddRectangleDlg.h"
#include "afxdialogex.h"
#include "CRectangle.h"

// CAddRectangleDlg dialog

IMPLEMENT_DYNAMIC(CAddRectangleDlg, CDialogEx)

CAddRectangleDlg::CAddRectangleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RECTANGLE, pParent)
{
	m_strDlgCaption = _T("Add Rectangle");
	m_color = 0xFF0000;//blue
}

CAddRectangleDlg::~CAddRectangleDlg()
{
}

void CAddRectangleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RECT_LENGTH, RectLength);
	DDX_Control(pDX, IDC_RECT_WIDTH, RectWidth);
	DDX_Control(pDX, IDC_RECT_X, RectX);
	DDX_Control(pDX, IDC_RECT_Y, RectY);
	DDX_Control(pDX, IDC_SELECT_COLOR, RectColor);
}


BEGIN_MESSAGE_MAP(CAddRectangleDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddRectangleDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_RECT_LENGTH, &CAddRectangleDlg::OnEnChangeRectLength)
	ON_BN_CLICKED(IDC_SELECT_COLOR, &CAddRectangleDlg::OnBnClickedSelectColor)
END_MESSAGE_MAP()


// CAddRectangleDlg message handlers



void CAddRectangleDlg::OnBnClickedOk()
{
	m_posX = get_int_from_cedit(RectX);
	m_posY = get_int_from_cedit(RectY);
	m_length = get_int_from_cedit(RectLength);
	m_width = get_int_from_cedit(RectWidth);
	CDialogEx::OnOK();
}


void CAddRectangleDlg::OnEnChangeRectLength()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CAddRectangleDlg::OnBnClickedSelectColor()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		m_color = dlg.GetColor();
	}
	RectColor.SetFaceColor(m_color, 1);
}


BOOL CAddRectangleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	RectColor.SetFaceColor(m_color, 1);
	RectX.SetWindowText(get_CString(m_posX));
	RectY.SetWindowText(get_CString(m_posY));
	RectLength.SetWindowText(get_CString(m_length));
	RectWidth.SetWindowText(get_CString(m_width));
	SetWindowText(m_strDlgCaption);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
