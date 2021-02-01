
// plot_spectrumDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "plot_spectrum.h"
#include "plot_spectrumDlg.h"
#include "fft.h"
#include "WaveFile.h"
#include "spectrum.h"

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


// Cplot_spectrumDlg 對話方塊




Cplot_spectrumDlg::Cplot_spectrumDlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cplot_spectrumDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cplot_spectrumDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cplot_spectrumDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
    ON_BN_CLICKED(IDC_BTN_TEST2, &Cplot_spectrumDlg::OnBnClickedBtnTest2)
END_MESSAGE_MAP()


// Cplot_spectrumDlg 訊息處理常式

BOOL Cplot_spectrumDlg::OnInitDialog()
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

	return TRUE;  // 除非將焦點設定到控制項，否則返回 TRUE
}

void Cplot_spectrumDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cplot_spectrumDlg::OnPaint()
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

// 當使用者拖動最小化視窗時系統呼叫此函數取得游標
// 顯示。
HCURSOR Cplot_spectrumDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CString GetWavFileName()
{
    CString fileName;
	OPENFILENAME ofn;
	memset(&ofn, 0, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = ::GetDesktopWindow();
    ofn.lpstrFile = fileName.GetBuffer(MAX_PATH);
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFilter = _T("WAVE File(*.wav)\0*.wav\0");
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (GetOpenFileName(&ofn) == TRUE)
	{
    }

    fileName.ReleaseBuffer();

    return fileName;
}

int flTbl[] = { 697, 770, 852, 941 };
int fhTbl[] = { 1209, 1336, 1447 };
TCHAR keyTbl[4][3] = 
{
    {_T('1'), _T('2'), _T('3') },
    {_T('4'), _T('5'), _T('6') },
    {_T('7'), _T('8'), _T('9') },
    {_T('*'), _T('0'), _T('#') }
};

int IndexFromFreq(int *tbl, int count, int freq)
{
    int distance = 10000000L;
    int index = -1;

    for(int i = 0; i < count; i++)
    {
        if(abs(freq - tbl[i]) < distance)
        {
            distance = abs(freq - tbl[i]);
            index = i;
        }
    }

    if(distance > 50)
        return -1;
    else
        return index;
}

void ExchangeIndex(int *index, float *power)
{
    if(power[index[1]] > power[index[0]])
    {
        int t = index[0];
        index[0] = index[1];
        index[1] = t;
    }
}

void SearchMax2FreqIndex(float *power, int count, int& first, int& second)
{
    int max2Idx[2] = { 0 };

    ExchangeIndex(max2Idx, power);
    for(int i = 2; i < count; i++)
    {
        if(power[i] > power[max2Idx[1]])
        {
            max2Idx[1] = i;
            ExchangeIndex(max2Idx, power);
        }
    }

    first = min(max2Idx[0], max2Idx[1]);
    second = max(max2Idx[0], max2Idx[1]);
}

void Cplot_spectrumDlg::OnBnClickedBtnTest2()
{
    FFT_HANDLE hfft = { 0 };
    CWaveFile wavFile;

    CString fileName = GetWavFileName();
    if(fileName.IsEmpty())
    {
        return;
    }

	WAVEFORMATEX wfx;
	wavFile.Open((LPCTSTR)fileName, &wfx, WAVEFILE_READ);
	wfx = *wavFile.GetFormat();

	DWORD dwRetBytes = 0;
	DWORD dwTotalSamples = wavFile.GetSize() / wfx.nBlockAlign;
    unsigned char *dataBuf = new unsigned char[dwTotalSamples * wfx.nBlockAlign];
	wavFile.Read(dataBuf, dwTotalSamples * wfx.nBlockAlign, &dwRetBytes);
	DWORD dwRetSamples = dwRetBytes /wfx.nBlockAlign;

    float spec[2048] = { 0.0 };

    short *sampleData = (short *)dataBuf;
    if(InitFft(&hfft, 2048, 1))
    {
        PowerSpectrumT(&hfft, sampleData, dwRetSamples, wfx.nChannels, spec);
        int first, second;
        SearchMax2FreqIndex(spec, 1024, first, second);
        int firstFreq = int(first * (wfx.nSamplesPerSec / 2048.0));
        int secondFreq = int(second * (wfx.nSamplesPerSec / 2048.0));
        int fi = IndexFromFreq(flTbl, 4, firstFreq);
        int si = IndexFromFreq(fhTbl, 3, secondFreq);
        if((fi == -1) || (si == -1))
        {
            AfxMessageBox(_T("不能識別的撥號聲！"));
        }
        else
        {
            CString key;
            key += keyTbl[fi][si];
            SetDlgItemInt(IDC_STC_FL, flTbl[fi]);
            SetDlgItemInt(IDC_STC_FH, fhTbl[si]);
            SetDlgItemText(IDC_STC_KEY, key);
        }

        ReleaseFft(&hfft);
    }

    delete[] dataBuf;
    wavFile.Close();
}
