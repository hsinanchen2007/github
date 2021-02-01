
// calendar2Dlg.cpp : 實作檔
//

#include "stdafx.h"
#include "calendar2.h"
#include "calendar2Dlg.h"
#include "ChineseCalendar.h"
#include "support.h"
#include "calendar_func.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用於應用程式“關於”功能表項目的 CAboutDlg 對話方塊

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 對話方塊資料
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// Ccalendar2Dlg 對話方塊




Ccalendar2Dlg::Ccalendar2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(Ccalendar2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    m_CurrentMonth = 0;
}

void Ccalendar2Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_STC_CALENDAR, m_CalendarCtrl);
}

BEGIN_MESSAGE_MAP(Ccalendar2Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
    ON_BN_CLICKED(IDC_BTN_SET_YEAR, &Ccalendar2Dlg::OnBnClickedBtnSetYear)
    ON_BN_CLICKED(IDC_BTN_LAST_MONTH, &Ccalendar2Dlg::OnBnClickedBtnLastMonth)
    ON_BN_CLICKED(IDC_BTN_NEXT_MONTH, &Ccalendar2Dlg::OnBnClickedBtnNextMonth)
    ON_BN_CLICKED(IDC_BTN_INFORMATION, &Ccalendar2Dlg::OnBnClickedBtnInformation)
    ON_BN_CLICKED(IDC_BTN_TEST, &Ccalendar2Dlg::OnBnClickedBtnTest)
    ON_BN_CLICKED(IDC_BTN_SOLARTERM, &Ccalendar2Dlg::OnBnClickedBtnSolarterm)
    ON_BN_CLICKED(IDC_BTN_NEWMOON, &Ccalendar2Dlg::OnBnClickedBtnNewmoon)
END_MESSAGE_MAP()


// Ccalendar2Dlg 訊息處理常式

BOOL Ccalendar2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 將“關於...”功能表項目新增到系統功能表中。

	// IDM_ABOUTBOX 必須在系統命令範圍內。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 設定此對話方塊的圖示。當應用程式主視窗不是對話方塊時，框架將自動
	// 執行此操作
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此新增額外的初始化程式碼
    SetDlgItemText(IDC_EDIT_YEAR, _T("2015"));
    m_CalendarCtrl.SetGeriYear(2015);

	return TRUE;  // 除非將焦點設定到控制項，否則返回 TRUE
}

void Ccalendar2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向對話方塊新增最小化按鈕，則需要下面的程式碼
// 來繪製該圖示。對於使用文件/視圖模型的 MFC 應用程式，
// 這將由框架自動完成。

void Ccalendar2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用於繪製的裝置上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使圖示在工作區矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 繪製圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//當使用者拖動最小化視窗時系統呼叫此函數取得游標
//顯示。
HCURSOR Ccalendar2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Ccalendar2Dlg::OnBnClickedBtnSetYear()
{
    int year = GetDlgItemInt(IDC_EDIT_YEAR);
    if(year < 1600)
    {
        AfxMessageBox(_T("不支援1600年以前的歷史農曆計算！"));
        return;
    }
    
    m_CalendarCtrl.SetGeriYear(year);
}

void Ccalendar2Dlg::OnBnClickedBtnLastMonth()
{
    m_CalendarCtrl.LastMonth();
}

void Ccalendar2Dlg::OnBnClickedBtnNextMonth()
{
    m_CalendarCtrl.NextMonth();
}

void Ccalendar2Dlg::OnBnClickedBtnInformation()
{
    // TODO: Add your control notification handler code here
}

void Ccalendar2Dlg::OnBnClickedBtnSolarterm()
{
    // TODO: Add your control notification handler code here
}

void Ccalendar2Dlg::OnBnClickedBtnNewmoon()
{
    // TODO: Add your control notification handler code here
}

/*從某一年的某個節氣開始，連續計算25個節氣，返回各節氣的儒略日，本地時間*/
void GetAllSolarTermsJD(int year, double *SolarTerms, int start)
{
    int i = 0;
    int st = start;
    while(i < 25)
    {
        double jd = CalculateSolarTerms(year, st * 15);
        SolarTerms[i++] = JDTDtoLocalTime(jd);
        if(st == WINTER_SOLSTICE)
        {
            year++;
        }
        st = (st + 1) % SOLAR_TERMS_COUNT;
    }
}

void PrintJDTimes(double *jds, int count)
{
    char timeStr[128];

    TRACE("\n");
    for(int i = 0; i < count; i++)
    {
        JDtoString(jds[i], timeStr, 128);
        TRACE("%f, %s\n", jds[i], timeStr);
    }
    TRACE("\n");
}

void Ccalendar2Dlg::OnBnClickedBtnTest()
{
    int this_year = 2011;

    double solarTerms[25];
    GetAllSolarTermsJD(this_year - 1, solarTerms, WINTER_SOLSTICE);
    PrintJDTimes(solarTerms, 25);

}
