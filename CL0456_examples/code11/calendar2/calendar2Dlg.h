
// calendar2Dlg.h : ���Y��
//

#pragma once

#include "WzCalendarCtrl.h"


// Ccalendar2Dlg ��ܤ��
class Ccalendar2Dlg : public CDialog
{
// �غc
public:
	Ccalendar2Dlg(CWnd* pParent = NULL);	// �зǫغc���

// ��ܤ�����
	enum { IDD = IDD_CALENDAR2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩

protected:
// ��@
protected:
	HICON m_hIcon;
    int m_CurrentMonth;
    CWzCalendarCtrl m_CalendarCtrl;

	// �ͦ����T���M�g���
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedBtnSetYear();
    afx_msg void OnBnClickedBtnLastMonth();
    afx_msg void OnBnClickedBtnNextMonth();
    afx_msg void OnBnClickedBtnInformation();
    afx_msg void OnBnClickedBtnTest();
    afx_msg void OnBnClickedBtnSolarterm();
    afx_msg void OnBnClickedBtnNewmoon();
};
