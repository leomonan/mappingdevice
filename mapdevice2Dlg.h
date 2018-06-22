// mapdevice2Dlg.h : header file
//

#if !defined(AFX_MAPDEVICE2DLG_H__0B2FECF8_979E_4902_84DA_D8D5E0852E98__INCLUDED_)
#define AFX_MAPDEVICE2DLG_H__0B2FECF8_979E_4902_84DA_D8D5E0852E98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMapdevice2Dlg dialog

class CMapdevice2Dlg : public CDialog
{
// Construction
public:
	CMapdevice2Dlg(CWnd* pParent = NULL);	// standard constructor
	void SetIpFromClipBoard();
	CString ExecuteCmd(CString str);
    TCHAR* StringToChar(CString& str);
// Dialog Data
	//{{AFX_DATA(CMapdevice2Dlg)
	enum { IDD = IDD_MAPDEVICE2_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMapdevice2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMapdevice2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//afx_msg void OnChangeEdit11111();
	afx_msg void OnMapDevice();
	afx_msg void OnSendCommand();
    afx_msg void OnRunCommand(char * command, CEdit* pEdit_cmd,  CEdit* pEdit_ret );
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPDEVICE2DLG_H__0B2FECF8_979E_4902_84DA_D8D5E0852E98__INCLUDED_)
