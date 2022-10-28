// CCanvasDlg.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication5.h"
#include "CCanvasDlg.h"
#include "afxdialogex.h"


// CCanvasDlg dialog

IMPLEMENT_DYNAMIC(CCanvasDlg, CDialog)

CCanvasDlg::CCanvasDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_EDIT_CANVAS, pParent)
{
}

CCanvasDlg::~CCanvasDlg()
{
}

void CCanvasDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CANVAS_X, CanvasX);
	DDX_Control(pDX, IDC_CANVAS_Y, CanvasY);
	DDX_Control(pDX, IDC_CELL_SIZE, CellSize);
	DDX_Control(pDX, IDC_INIT_COLOR, InitColor);
}


BEGIN_MESSAGE_MAP(CCanvasDlg, CDialog)
	ON_BN_CLICKED(IDC_INIT_COLOR, &CCanvasDlg::OnBnClickedInitColor)
	ON_BN_CLICKED(IDOK, &CCanvasDlg::OnBnClickedOk)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// CCanvasDlg message handlers


void CCanvasDlg::OnBnClickedInitColor()
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		m_init_color = dlg.GetColor();
	}
	InitColor.SetFaceColor(m_init_color, 1);
}


void CCanvasDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	m_sizeX = get_int_from_cedit(CanvasX);
	m_sizeY = get_int_from_cedit(CanvasY);
	m_cell_size = get_int_from_cedit(CellSize);
	CDialog::OnOK();
}


void CCanvasDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{

	CDialog::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
}


INT_PTR CCanvasDlg::DoModal()
{
	// TODO: Add your specialized code here and/or call the base class
	return CDialog::DoModal();
}


BOOL CCanvasDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	CanvasX.SetWindowText(get_CString(m_sizeX));
	CanvasY.SetWindowText(get_CString(m_sizeY));
	CellSize.SetWindowText(get_CString(m_cell_size));
	InitColor.SetFaceColor(m_init_color, 1);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
