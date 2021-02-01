
// player.h : PROJECT_NAME 應用程式的主標頭檔
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此檔之前包含“stdafx.h”以生成 PCH 檔"
#endif

#include "resource.h"		// 主符號


// CplayerApp:
// 有關此類別的實作，請參閱 player.cpp
//

class CplayerApp : public CWinAppEx
{
public:
	CplayerApp();

// 覆寫
	public:
	virtual BOOL InitInstance();

// 實作

	DECLARE_MESSAGE_MAP()
};

extern CplayerApp theApp;