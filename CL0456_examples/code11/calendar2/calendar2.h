
// calendar2.h : PROJECT_NAME ���ε{�����D���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�b�]�t���ɤ��e�]�t��stdafx.h���H�ͦ� PCH ��"
#endif

#include "resource.h"		// �D�Ÿ�


// Ccalendar2App:
// ���������O����@�A�аѾ\ calendar2.cpp
//

class Ccalendar2App : public CWinAppEx
{
public:
	Ccalendar2App();

// �мg
	public:
	virtual BOOL InitInstance();

// ��@

	DECLARE_MESSAGE_MAP()
};

extern Ccalendar2App theApp;