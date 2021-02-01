
// splineDlg.h : ���Y��
//

#pragma once

#include "DisplayWnd.h"


// CsplineDlg ��ܤ��
class CsplineDlg : public CDialog
{
// �غc
public:
	CsplineDlg(CWnd* pParent = NULL);	// �зǫغc���

// ��ܤ�����
	enum { IDD = IDD_SPLINE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩


// ��@
protected:
	HICON m_hIcon;
    CDisplayWnd *m_pDispWnd;

	// �ͦ����T���M�g���
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedBtnSpline();
    afx_msg void OnDestroy();
};
