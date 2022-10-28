// CAddTriangleDlg.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication5.h"
#include "CAddTriangleDlg.h"
#include "afxdialogex.h"


// CAddTriangleDlg dialog

IMPLEMENT_DYNAMIC(CAddTriangleDlg, CDialogEx)

CAddTriangleDlg::CAddTriangleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TRIANGLE, pParent)
{
	m_strDlgCaption = _T("Add Triangle");
	m_color = 0x00FF00;//green
}

CAddTriangleDlg::~CAddTriangleDlg()
{
}

void CAddTriangleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TRI_X1, posX1);
	DDX_Control(pDX, IDC_TRI_X2, posX2);
	DDX_Control(pDX, IDC_TRI_X3, posX3);
	DDX_Control(pDX, IDC_TRI_Y1, posY1);
	DDX_Control(pDX, IDC_TRI_Y2, posY2);
	DDX_Control(pDX, IDC_TRI_Y3, posY3);
	DDX_Control(pDX, IDC_TRI_COLOR, TriColor);
}


BEGIN_MESSAGE_MAP(CAddTriangleDlg, CDialogEx)
	ON_BN_CLICKED(IDC_TRI_COLOR, &CAddTriangleDlg::OnBnClickedTriColor)
	ON_BN_CLICKED(IDOK, &CAddTriangleDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddTriangleDlg message handlers


void CAddTriangleDlg::OnBnClickedTriColor()
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		m_color = dlg.GetColor();
	}
	TriColor.SetFaceColor(m_color, 1);
}


void CAddTriangleDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	m_x1 = get_int_from_cedit(posX1);
	m_y1 = get_int_from_cedit(posY1);
	m_x2 = get_int_from_cedit(posX2);
	m_y2 = get_int_from_cedit(posY2);
	m_x3 = get_int_from_cedit(posX3);
	m_y3 = get_int_from_cedit(posY3);
	CDialogEx::OnOK();

}


BOOL CAddTriangleDlg::OnInitDialog()
{
	
	CDialogEx::OnInitDialog();
	TriColor.SetFaceColor(m_color, 1);
	posX1.SetWindowText(get_CString(m_x1));
	posY1.SetWindowText(get_CString(m_y1));
	posX2.SetWindowText(get_CString(m_x2));
	posY2.SetWindowText(get_CString(m_y2));
	posX3.SetWindowText(get_CString(m_x3));
	posY3.SetWindowText(get_CString(m_y3));
	SetWindowText(m_strDlgCaption);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
