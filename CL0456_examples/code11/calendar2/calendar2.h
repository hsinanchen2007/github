
// calendar2.h : PROJECT_NAME 應用程式的主標頭檔
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此檔之前包含“stdafx.h”以生成 PCH 檔"
#endif

#include "resource.h"		// 主符號


// Ccalendar2App:
// 有關此類別的實作，請參閱 calendar2.cpp
//

class Ccalendar2App : public CWinAppEx
{
public:
	Ccalendar2App();

// 覆寫
	public:
	virtual BOOL InitInstance();

// 實作

	DECLARE_MESSAGE_MAP()
};

extern Ccalendar2App theApp;