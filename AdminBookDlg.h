#pragma once

#include "AddEditDlg.h"

// AdminBookDlg 대화 상자

class AdminBookDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AdminBookDlg)

public:
	AdminBookDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~AdminBookDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADMIN_BOOK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnButtonBookAdd();
};
