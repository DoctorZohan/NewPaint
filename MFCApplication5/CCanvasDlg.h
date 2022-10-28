#pragma once


// CCanvasDlg dialog

class CCanvasDlg : public CDialog
{
	DECLARE_DYNAMIC(CCanvasDlg)

public:
	CCanvasDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CCanvasDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDIT_CANVAS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedInitColor();
	afx_msg void OnBnClickedOk();
	CEdit CanvasX;
	CEdit CanvasY;
	CEdit CellSize;
	CMFCButton InitColor;
	int sizeX() const { return m_sizeX; }
	int sizeY() const { return m_sizeY; }
	int cell_size() const { return m_cell_size; }
	int init_color() const { return m_init_color; }
	void sizeX(int sizeX) { m_sizeX = sizeX; }
	void sizeY(int sizeY) { m_sizeY = sizeY; }
	void cell_size(int cell_size) { m_cell_size = cell_size; }
	void init_color(int init_color) { m_init_color = init_color; }
private:
	int m_sizeX;
	int m_sizeY;
	int m_cell_size;
	int m_init_color;
public:
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	virtual INT_PTR DoModal();
	virtual BOOL OnInitDialog();
};
