
// MFCApplication5.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "MFCApplication5.h"
#include "MainFrm.h"
#include "CAddRectangleDlg.h"
#include "CAddCircleDlg.h"
#include "CAddTriangleDlg.h"
#include "CCanvasDlg.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "CTriangle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPaintApp

BEGIN_MESSAGE_MAP(CPaintApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CPaintApp::OnAppAbout)
	ON_COMMAND(ID_ADD_RECTANGLE, &CPaintApp::OnAddRectangle)
	ON_COMMAND(ID_FILE_EDITCANVAS, &CPaintApp::OnFileEditcanvas)
	ON_COMMAND(ID_ADD_CIRCLE, &CPaintApp::OnAddCircle)
	ON_COMMAND(ID_ADD_TRIANGLE, &CPaintApp::OnAddTriangle)
	ON_COMMAND(ID_EDIT_DELETE, &CPaintApp::OnEditDelete)
END_MESSAGE_MAP()


// CPaintApp construction

CPaintApp::CPaintApp() noexcept
{

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("MFCApplication5.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	m_canvas = new Canvas(90, 60);
}

// The one and only CPaintApp object

CPaintApp theApp;


// CPaintApp initialization

BOOL CPaintApp::InitInstance()
{
	CWinApp::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// AfxInitRichEdit2() is required to use RichEdit control
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));


	// To create the main window, this code creates a new frame window
	// object and then sets it as the application's main window object
	//CFrameWnd *pFrame = new CMainFrame;
	m_pFrame = new CMainFrame;
	if (!m_pFrame)
		return FALSE;
	m_pMainWnd = m_pFrame;
	// create and load the frame with its resources
	m_pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, nullptr,
		nullptr);





	// The one and only window has been initialized, so show and update it
	m_pFrame->ShowWindow(SW_SHOW);
	m_pFrame->UpdateWindow();
	return TRUE;
}

CPaintApp::~CPaintApp()
{
	//delete m_pFrame;
}


int CPaintApp::ExitInstance()
{
	//TODO: handle additional resources you may have added
	return CWinApp::ExitInstance();
}

// CPaintApp message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:

};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	//ON_COMMAND(ID_ADD_RECTANGLE, &CAboutDlg::OnAddRectangle)
END_MESSAGE_MAP()

// App command to run the dialog
void CPaintApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CPaintApp message handlers



void CPaintApp::OnAddRectangle()
{
	CAddRectangleDlg rectDlg;
	int result = rectDlg.DoModal();
	if (result == IDOK)
	{
		CRectangle* rect = new CRectangle(rectDlg.posX(), rectDlg.posY(), rectDlg.length(), rectDlg.width(), rectDlg.color());
		if (!m_canvas->addObject(rect))
		{
			delete rect;
			AfxMessageBox(L"This shape should be inside canvas and do not intersect with other shapes");
			return;
		}
		m_pFrame->RedrawWindow();
	}
}


void CPaintApp::OnFileEditcanvas()
{
	CCanvasDlg Dlg;
	Dlg.sizeX(m_canvas->num_columns());
	Dlg.sizeY(m_canvas->num_rows());
	Dlg.cell_size(m_canvas->cell_size());
	Dlg.init_color(m_canvas->init_color());
	int result = Dlg.DoModal();
	if (result == IDOK)
	{
		m_canvas->redraw_canvas(Dlg.sizeX(), Dlg.sizeY(), Dlg.init_color());
		m_canvas->cell_size(Dlg.cell_size());
		m_pFrame->RedrawWindow();
	}
}


void CPaintApp::OnAddCircle()
{
	CAddCircleDlg cirDlg;
	int result = cirDlg.DoModal();
	if (result == IDOK)
	{
		CCircle* rect = new CCircle(cirDlg.posX(), cirDlg.posY(), cirDlg.radius(), cirDlg.color());
		if (!m_canvas->addObject(rect))
		{
			delete rect;
			AfxMessageBox(L"This shape should be inside canvas and do not intersect with other shapes");
			return;
		}
		m_pFrame->RedrawWindow();
	}
}


void CPaintApp::OnAddTriangle()
{
	CAddTriangleDlg triDlg;
	int result = triDlg.DoModal();
	if (result == IDOK)
	{
		CTriangle* obj = new CTriangle(triDlg.x1(), triDlg.y1(), triDlg.x2(), triDlg.y2(), triDlg.x3(), triDlg.y3(), triDlg.color());
		if (!m_canvas->addObject(obj))
		{
			delete obj;
			AfxMessageBox(L"This shape should be inside canvas and do not intersect with other shapes");
			return;
		}
		m_pFrame->RedrawWindow();
	}
}


void CPaintApp::OnEditDelete()
{
	Shape* obj = m_canvas->get_current_select_object();
	if (!obj)
		return;
	m_canvas->removeObject(obj);
	m_pFrame->RedrawWindow();
}
