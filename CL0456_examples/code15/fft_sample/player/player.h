
// player.h : PROJECT_NAME ���ε{�����D���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�b�]�t���ɤ��e�]�t��stdafx.h���H�ͦ� PCH ��"
#endif

#include "resource.h"		// �D�Ÿ�


// CplayerApp:
// ���������O����@�A�аѾ\ player.cpp
//

class CplayerApp : public CWinAppEx
{
public:
	CplayerApp();

// �мg
	public:
	virtual BOOL InitInstance();

// ��@

	DECLARE_MESSAGE_MAP()
};

extern CplayerApp theApp;