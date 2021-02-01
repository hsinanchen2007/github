
// plot_spectrum.h : PROJECT_NAME 應用程式的主標頭檔
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在引入此檔之前包含“stdafx.h”以生成 PCH 檔"
#endif

#include "resource.h"		// 主符號


// Cplot_spectrumApp:
// 有關此類別的實作，請參閱 plot_spectrum.cpp
//

class Cplot_spectrumApp : public CWinAppEx
{
public:
	Cplot_spectrumApp();

// 覆寫
	public:
	virtual BOOL InitInstance();

// 實作

	DECLARE_MESSAGE_MAP()
};

extern Cplot_spectrumApp theApp;