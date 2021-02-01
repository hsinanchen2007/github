
// calendar2Dlg.h : 標頭檔
//

#pragma once

#include "WzCalendarCtrl.h"


// Ccalendar2Dlg 對話方塊
class Ccalendar2Dlg : public CDialog
{
// 建構
public:
	Ccalendar2Dlg(CWnd* pParent = NULL);	// 標準建構函數

// 對話方塊資料
	enum { IDD = IDD_CALENDAR2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援

protected:
// 實作
protected:
	HICON m_hIcon;
    int m_CurrentMonth;
    CWzCalendarCtrl m_CalendarCtrl;

	// 生成的訊息映射函數
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
