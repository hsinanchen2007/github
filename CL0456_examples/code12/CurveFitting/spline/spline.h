
// spline.h : PROJECT_NAME 應用程式的主標頭檔
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在引入此檔之前引入“stdafx.h”以生成 PCH 檔"
#endif

#include "resource.h"		// 主符號


// CsplineApp:
// 有關此類別的實作，請參閱 spline.cpp
//

class CsplineApp : public CWinAppEx
{
public:
	CsplineApp();

// 覆寫
	public:
	virtual BOOL InitInstance();

// 實作

	DECLARE_MESSAGE_MAP()
};

extern CsplineApp theApp;