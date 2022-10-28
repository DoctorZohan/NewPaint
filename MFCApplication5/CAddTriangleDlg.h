#pragma once


// CAddTriangleDlg dialog

class CAddTriangleDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddTriangleDlg)

public:
	CAddTriangleDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAddTriangleDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRIANGLE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit posX1;
	CEdit posX2;
	CEdit posX3;
	CEdit posY1;
	CEdit posY2;
	CEdit posY3;
	int x1() const { return m_x1; }
	int y1() const { return m_y1; }
	int x2() const { return m_x2; }
	int y2() const { return m_y2; }
	int x3() const { return m_x3; }
	int y3() const { return m_y3; }
	int color() const { return m_color; }
	void x1(int x1) { m_x1 = x1; }
	void y1(int y1) { m_y1 = y1; }
	void x2(int x2) { m_x2 = x2; }
	void y2(int y2) { m_y2 = y2; }
	void x3(int x3) { m_x3 = x3; }
	void y3(int y3) { m_y3 = y3; }
	void color(int color) { m_color = color; }
	CString m_strDlgCaption;
private:
	int m_x1;
	int m_x2;
	int m_x3;
	int m_y1;
	int m_y2;
	int m_y3;
	int m_color;
public:
	afx_msg void OnBnClickedTriColor();
	afx_msg void OnBnClickedOk();
	CMFCButton TriColor;
	virtual BOOL OnInitDialog();
};
