
// splineDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "spline.h"
#include "splineDlg.h"
#include "ThomasEquation.h"
#include "Spline3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

double FuncY(double dbX)
{
	return 3.0 / (1.0 + dbX * dbX);
}

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


// CsplineDlg 對話方塊




CsplineDlg::CsplineDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CsplineDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    m_pDispWnd = NULL;
}

void CsplineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CsplineDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
    ON_BN_CLICKED(IDC_BTN_SPLINE, &CsplineDlg::OnBnClickedBtnSpline)
    ON_WM_DESTROY()
END_MESSAGE_MAP()


// CsplineDlg 訊息處理常式

BOOL CsplineDlg::OnInitDialog()
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

	m_pDispWnd = new CDisplayWnd;

	return TRUE;  // 除非將焦點設定到控制項，否則返回 TRUE
}

void CsplineDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  來繪製該圖示。對於使用文件/視圖模型的 MFC 應用程式，
//  這將由框架自動完成。

void CsplineDlg::OnPaint()
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
HCURSOR CsplineDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CsplineDlg::OnBnClickedBtnSpline()
{
    double sourceX[17] = {0.0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0, 5.5, 6.0, 6.5, 7.0, 7.5, 8.0};
    double sourceY[17];

    for(int i = 0; i < 17; i++)
    {
        sourceY[i] = FuncY(sourceX[i]);
    }

    if(m_pDispWnd != NULL)
    {
        SplineFitting fitting;
        //fitting.CalcSpline(sourceX, sourceY, 9, 1, 0.0, -0.004608);
        fitting.CalcSpline(sourceX, sourceY, 17, 1, 0.0, -0.01136);

        double xi[1024],yi[1024],si[1024];
        int ind = 0;
        for(double i = sourceX[0]; i < sourceX[16]; i += 0.01)
        {
            xi[ind] = i;
            yi[ind] = FuncY(i);
            si[ind] = fitting.GetValue(i);
            ind++;
        }

        //m_pDispWnd->SetInterpolationPoint(sourceX, sourceY, 9);
        m_pDispWnd->SetSourceCurve(xi, yi, ind);
        m_pDispWnd->SetSourceSplineCurve(xi, si, ind);
        m_pDispWnd->SetPointLogicRange(-1.0, 9.0, -1.0, 5.0);
        m_pDispWnd->ShowDisplayWindow(this);
    }
}

void CsplineDlg::OnDestroy()
{

    CDialog::OnDestroy();
}
