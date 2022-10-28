#pragma once


// CAddCircleDlg dialog

class CAddCircleDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddCircleDlg)

public:
	CAddCircleDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAddCircleDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CIRCLE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMFCButton CirColor;
	CEdit CirRad;
	CEdit CirX;
	CEdit CirY;
	afx_msg void OnBnClickedOk();
	int posX() const { return m_posX; }
	int posY() const { return m_posY; }
	int radious() const { return m_radious; }
	int color() const { return m_color; }
	void posX(int posX) { m_posX = posX; }
	void posY(int posY) { m_posY = posY; }
	void radious(int radious) { m_radious = radious; }
	void color(int color) { m_color = color; }
	CString m_strDlgCaption;
private:
	int m_posX;
	int m_posY;
	int m_radious;
	int m_color;
public:
	afx_msg void OnBnClickedCirColor();
	virtual BOOL OnInitDialog();
};
