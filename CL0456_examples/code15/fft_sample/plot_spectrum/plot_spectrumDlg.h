
// plot_spectrumDlg.h : ���Y��
//

#pragma once


// Cplot_spectrumDlg ��ܤ��
class Cplot_spectrumDlg : public CDialog
{
// �غc
public:
	Cplot_spectrumDlg(CWnd* pParent = NULL);	// �зǫغc���

// ��ܤ�����
	enum { IDD = IDD_PLOT_SPECTRUM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩


// ��@
protected:
	HICON m_hIcon;

	// �ͦ����T���M�g���
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedBtnTest2();
};
