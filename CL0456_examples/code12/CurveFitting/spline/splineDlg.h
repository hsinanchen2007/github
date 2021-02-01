
// splineDlg.h : 標頭檔
//

#pragma once

#include "DisplayWnd.h"


// CsplineDlg 對話方塊
class CsplineDlg : public CDialog
{
// 建構
public:
	CsplineDlg(CWnd* pParent = NULL);	// 標準建構函數

// 對話方塊資料
	enum { IDD = IDD_SPLINE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


// 實作
protected:
	HICON m_hIcon;
    CDisplayWnd *m_pDispWnd;

	// 生成的訊息映射函數
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedBtnSpline();
    afx_msg void OnDestroy();
};
