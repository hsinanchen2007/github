
// player.cpp : 定義應用程式的類別行為。
//

#include "stdafx.h"
#include "player.h"
#include "playerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CplayerApp

BEGIN_MESSAGE_MAP(CplayerApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CplayerApp 建構

CplayerApp::CplayerApp()
{
	// TODO: 在此處新增建構程式碼，
	// 將所有重要的初始化放置在 InitInstance 中
}


// 唯一的一個 CplayerApp 物件

CplayerApp theApp;


// CplayerApp 初始化

BOOL CplayerApp::InitInstance()
{
	// 如果一個運行在 Windows XP 上的應用程式清單指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本來啟用視覺化方式，
	// 則需要 InitCommonControlsEx()。否則，將無法新建視窗。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 將它設定為包括所有要在應用程式中使用的
	// 公共控制項類別。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	AfxEnableControlContainer();

	// 標準初始化
	// 如果未使用這些功能並希望減小
	// 最終可執行檔的大小，則應移除下列
	// 不需要的特定初始化常式
	// 更改用於儲存設定的註冊表項
	// TODO: 應適當修改該字串，
	// 例如修改為公司或組織名
	SetRegistryKey(_T("應用程式精靈生成的本機應用程式"));

	CplayerDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置處理何時用
		//  “確定”來關閉對話方塊的程式碼
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置處理何時用
		//  “取消”來關閉對話方塊的程式碼
	}

	// 由於對話方塊已關閉，所以將返回 FALSE 以便退出應用程式，
	//  而不是啟動應用程式的訊息池。
	return FALSE;
}
