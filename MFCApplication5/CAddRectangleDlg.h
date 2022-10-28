#pragma once


// CAddRectangleDlg dialog

class CAddRectangleDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddRectangleDlg)

public:
	CAddRectangleDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAddRectangleDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RECTANGLE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CEdit RectLength;
	afx_msg void OnEnChangeRectLength();
	CEdit RectWidth;
	CEdit RectX;
	CEdit RectY;
	int posX() const { return m_posX; }
	int posY() const { return m_posY; }
	int length() const { return m_length; }
	int width() const { return m_width; }
	int color() const { return m_color; }
	void posX(int posX) { m_posX = posX; }
	void posY(int posY) { m_posY = posY; }
	void length(int length) { m_length = length; }
	void width(int width) { m_width = width; }
	void color(int color) { m_color = color; }
	CString m_strDlgCaption;
private:
	int m_posX;
	int m_posY;
	int m_length;
	int m_width;
	int m_color;
public:
	afx_msg void OnBnClickedSelectColor();
	CMFCButton RectColor;
	virtual BOOL OnInitDialog();
};
