
// plot_spectrum.cpp : �w�q���ε{�������O�欰�C
//

#include "stdafx.h"
#include "plot_spectrum.h"
#include "plot_spectrumDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cplot_spectrumApp

BEGIN_MESSAGE_MAP(Cplot_spectrumApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Cplot_spectrumApp �غc

Cplot_spectrumApp::Cplot_spectrumApp()
{
	// TODO: �b���B�s�W�غc�{���X�A
	// �N�Ҧ����n����l�Ʃ�m�b InitInstance ��
}


// �ߤ@���@�� Cplot_spectrumApp ����

Cplot_spectrumApp theApp;


// Cplot_spectrumApp ��l��

BOOL Cplot_spectrumApp::InitInstance()
{
	// �p�G�@�Ӱ���b Windows XP �W�����ε{���M����w�n
	// �ϥ� ComCtl32.dll ���� 6 �Χ󰪪����ӱҥε�ı�Ƥ覡�A
	// �h�ݭn InitCommonControlsEx()�C�_�h�A�N�L�k�s�ص����C
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// �N���]�w���]�A�Ҧ��n�b���ε{�����ϥΪ�
	// ���@������O�C
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	AfxEnableControlContainer();

	// �зǪ�l��
	// �p�G���ϥγo�ǥ\��çƱ��p
	// �̲ץi�����ɪ��j�p�A�h�������U�C
	// ���ݭn���S�w��l�Ʊ`��
	// ���Ω��x�s�]�w�����U��
	// TODO: ���A��ק�Ӧr��A
	// �Ҧp�קאּ���q�β�´�W
	SetRegistryKey(_T("���ε{�����F�ͦ����������ε{��"));

	Cplot_spectrumDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �b����m�B�z��ɥ�
		//  ���T�w����������ܤ�����{���X
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �b����m�B�z��ɥ�
		//  ����������������ܤ�����{���X
	}

	// �ѩ��ܤ���w�����A�ҥH�N��^ FALSE �H�K�h�X���ε{���A
	//  �Ӥ��O�Ұ����ε{�����T�����C
	return FALSE;
}
