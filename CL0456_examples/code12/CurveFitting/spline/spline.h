
// spline.h : PROJECT_NAME ���ε{�����D���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�b�ޤJ���ɤ��e�ޤJ��stdafx.h���H�ͦ� PCH ��"
#endif

#include "resource.h"		// �D�Ÿ�


// CsplineApp:
// ���������O����@�A�аѾ\ spline.cpp
//

class CsplineApp : public CWinAppEx
{
public:
	CsplineApp();

// �мg
	public:
	virtual BOOL InitInstance();

// ��@

	DECLARE_MESSAGE_MAP()
};

extern CsplineApp theApp;