
// plot_spectrum.h : PROJECT_NAME ���ε{�����D���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�b�ޤJ���ɤ��e�]�t��stdafx.h���H�ͦ� PCH ��"
#endif

#include "resource.h"		// �D�Ÿ�


// Cplot_spectrumApp:
// ���������O����@�A�аѾ\ plot_spectrum.cpp
//

class Cplot_spectrumApp : public CWinAppEx
{
public:
	Cplot_spectrumApp();

// �мg
	public:
	virtual BOOL InitInstance();

// ��@

	DECLARE_MESSAGE_MAP()
};

extern Cplot_spectrumApp theApp;