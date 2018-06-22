// mapdevice2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "mapdevice2.h"
#include "mapdevice2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMapdevice2Dlg dialog

CMapdevice2Dlg::CMapdevice2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMapdevice2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMapdevice2Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMapdevice2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMapdevice2Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMapdevice2Dlg, CDialog)
	//{{AFX_MSG_MAP(CMapdevice2Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_EN_CHANGE(IDC_USERNAME, OnChangeEdit11111)
	ON_BN_CLICKED(IDC_BUTTON1, OnMapDevice)
	ON_BN_CLICKED(IDOK, OnSendCommand)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMapdevice2Dlg message handlers


void CMapdevice2Dlg::SetIpFromClipBoard()
{

    //一、打开剪切板
    if (OpenClipboard()) {

        //二、获得指向剪切板的全局指针变量
        HANDLE hClipMemory=::GetClipboardData(CF_TEXT);

        //三、锁定剪切板
        LPBYTE lpClipMemory = (LPBYTE)GlobalLock(hClipMemory);

        //四、获取剪切板内容
        CString m_sMessage = CString(lpClipMemory);

        
        GetDlgItem(IDC_IPADDRESS1)->SetWindowText(m_sMessage); 

        //五、解锁剪切板
        GlobalUnlock(hClipMemory);
    }
    //六、关闭剪切板

    ::CloseClipboard();


}

BOOL CMapdevice2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	SetIpFromClipBoard();
	GetDlgItem(IDC_USERNAME)->SetWindowText(_T("qeexo")); 
	GetDlgItem(IDC_PASSWD)->SetWindowText(_T("123123mn")); 
	GetDlgItem(IDC_FOLDER1)->SetWindowText(_T("\\mnt")); 
	GetDlgItem(IDC_DRIVER1)->SetWindowText(_T("x:")); 
	GetDlgItem(IDC_FOLDER2)->SetWindowText(_T("\\share")); 
	GetDlgItem(IDC_DRIVER2)->SetWindowText(_T("y:")); 

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMapdevice2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMapdevice2Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMapdevice2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMapdevice2Dlg::OnRunCommand(char * command, CEdit* pEdit_cmd,  CEdit* pEdit_ret ) 
{

    pEdit_cmd->ReplaceSel(_T("\r\n"));  
    pEdit_cmd->ReplaceSel(command);  

    CString result = ExecuteCmd(command);

    pEdit_ret->ReplaceSel(_T("\r\ncommand:\r\n"));  
    pEdit_ret->ReplaceSel(command);  

    pEdit_ret->ReplaceSel(_T("\r\nresult:\r\n"));  
    pEdit_ret->ReplaceSel(result);    

}


void CMapdevice2Dlg::OnMapDevice() 
{
	// TODO: Add your control notification handler code here
	#define STR_SIZE 80
	TCHAR hostname[STR_SIZE];
	TCHAR username[STR_SIZE];
	TCHAR password[STR_SIZE];
	TCHAR folder1[STR_SIZE];
	TCHAR driver1[STR_SIZE];
	TCHAR folder2[STR_SIZE];
	TCHAR driver2[STR_SIZE];
    TCHAR command[1024];	

	int n_touches = 6;
	 char buf[3] = { 0 };
    sscanf(buf, "%i", &n_touches);
    
	GetDlgItem(IDC_IPADDRESS1)->GetWindowText(hostname, STR_SIZE);
    if(0 == strcmp(hostname, "0.0.0.0")) {
        SetIpFromClipBoard();
        GetDlgItem(IDC_IPADDRESS1)->GetWindowText(hostname, STR_SIZE);
    }
	GetDlgItem(IDC_USERNAME)->GetWindowText(username, STR_SIZE);
    GetDlgItem(IDC_PASSWD)->GetWindowText(password, STR_SIZE);
    GetDlgItem(IDC_FOLDER1)->GetWindowText(folder1, STR_SIZE);
    GetDlgItem(IDC_DRIVER1)->GetWindowText(driver1, STR_SIZE);
    GetDlgItem(IDC_FOLDER2)->GetWindowText(folder2, STR_SIZE);
    GetDlgItem(IDC_DRIVER2)->GetWindowText(driver2, STR_SIZE);


    CEdit* pEdit_cmd = ( CEdit*)GetDlgItem(IDC_COMMAND);  
    ASSERT(pEdit_cmd && pEdit_cmd->GetSafeHwnd()); 
    pEdit_cmd->SetSel(-1);  

    CEdit* pEdit_ret = ( CEdit*)GetDlgItem(IDC_RESULT);  
    ASSERT(pEdit_ret && pEdit_ret->GetSafeHwnd());  
    pEdit_ret->SetSel(-1); 

	sprintf(command, "net use %s /del /y ",driver1 );
    pEdit_cmd->ReplaceSel(command);  
    
    CString result = ExecuteCmd(command);

    pEdit_ret->ReplaceSel(_T("\r\ncommand:\r\n"));  
    pEdit_ret->ReplaceSel(command);  

    pEdit_ret->ReplaceSel(_T("\r\nresult:\r\n"));  
    pEdit_ret->ReplaceSel(result);    


    sprintf(command, "net use %s /del /y ",driver2 );
    OnRunCommand(command, pEdit_cmd, pEdit_ret);

    sprintf(command, "Netsh interface set interface \"Local Area Connection\" disable" );
    OnRunCommand(command, pEdit_cmd, pEdit_ret);

    sprintf(command, "Netsh interface set interface \"Local Area Connection\" enable" );
    OnRunCommand(command, pEdit_cmd, pEdit_ret);

    sprintf(command, "net use %s \\\\%s%s %s /user:%s", driver1, hostname, folder1, password,username );
    OnRunCommand(command, pEdit_cmd, pEdit_ret);    

	sprintf(command, "net use %s \\\\%s%s %s /user:%s", driver2, hostname, folder2, password,username );
    OnRunCommand(command, pEdit_cmd, pEdit_ret); 

    return;
}

CString CMapdevice2Dlg::ExecuteCmd(CString str)  
{  
    SECURITY_ATTRIBUTES sa;  
    HANDLE hRead,hWrite;  
	CString output; 
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);  
    sa.lpSecurityDescriptor = NULL;  
    sa.bInheritHandle = TRUE;  
    if (!CreatePipe(&hRead,&hWrite,&sa,0))  
    {  
        MessageBox("Error on CreatePipe()!");  
        return output;  
    }  
    STARTUPINFO si={sizeof(si)};  
    PROCESS_INFORMATION pi;  
    si.hStdError = hWrite;  
    si.hStdOutput = hWrite;  
    si.wShowWindow = SW_HIDE;  
    si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;  
    //LPTSTR cmdline = (LPTSTR)(LPCTSTR)str;  
    TCHAR* cmdline=StringToChar(str); 
    if (!CreateProcess(NULL,cmdline,NULL,NULL,TRUE,NULL,NULL,NULL,&si,&pi))  
    {  
        MessageBox("Error on CreateProcess()!");  
        return output;  
    }  
    CloseHandle(hWrite);  
  
    char buffer[4096];  
    memset(buffer,0,4096);  
     
    DWORD byteRead;  
    while(true)  
    {  
        if (ReadFile(hRead,buffer,4095,&byteRead,NULL) == NULL)  
        {  
            break;  
        }  
        output += buffer;  
    }  
    return output;  
}  

TCHAR* CMapdevice2Dlg::StringToChar(CString& str)  
{  
    int len=str.GetLength();  
    TCHAR* tr=str.GetBuffer(len);  
    str.ReleaseBuffer();  
    return tr;   
}  

void CMapdevice2Dlg::OnSendCommand() 
{
    TCHAR command[1024];	

    GetDlgItem(IDC_COMMAND)->GetWindowText(command, STR_SIZE);
    
    CEdit* pEdit_ret = ( CEdit*)GetDlgItem(IDC_RESULT);  
    ASSERT(pEdit_ret && pEdit_ret->GetSafeHwnd());  
    pEdit_ret->SetSel(-1);  

    CString result = ExecuteCmd(command);

    pEdit_ret->ReplaceSel(_T("\r\n"));  
    pEdit_ret->ReplaceSel(result);  
   
    
}
