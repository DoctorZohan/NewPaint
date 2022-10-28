// CAddCircleDlg.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication5.h"
#include "CAddCircleDlg.h"
#include "afxdialogex.h"


// CAddCircleDlg dialog

IMPLEMENT_DYNAMIC(CAddCircleDlg, CDialogEx)

CAddCircleDlg::CAddCircleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CIRCLE, pParent)
{
	m_strDlgCaption = _T("Add Circle");
	m_color = 0x0000FF;//red
}

CAddCircleDlg::~CAddCircleDlg()
{
}

void CAddCircleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CIR_COLOR, CirColor);
	DDX_Control(pDX, IDC_CIR_RAD, CirRad);
	DDX_Control(pDX, IDC_CIR_X, CirX);
	DDX_Control(pDX, IDC_CIR_Y, CirY);
}


BEGIN_MESSAGE_MAP(CAddCircleDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddCircleDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CIR_COLOR, &CAddCircleDlg::OnBnClickedCirColor)
END_MESSAGE_MAP()


// CAddCircleDlg message handlers


void CAddCircleDlg::OnBnClickedOk()
{
	m_posX = get_int_from_cedit(CirX);
	m_posY = get_int_from_cedit(CirY);
	m_radius = get_int_from_cedit(CirRad);
	CDialogEx::OnOK();
}


void CAddCircleDlg::OnBnClickedCirColor()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		m_color = dlg.GetColor();
	}
	CirColor.SetFaceColor(m_color, 1);
}


BOOL CAddCircleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CirColor.SetFaceColor(m_color, 1);
	CirX.SetWindowText(get_CString(m_posX));
	CirY.SetWindowText(get_CString(m_posY));
	CirRad.SetWindowText(get_CString(m_radius));
	SetWindowText(m_strDlgCaption);
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
