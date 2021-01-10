#pragma once


// AdminUserDlg 대화 상자

class AdminUserDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AdminUserDlg)

public:
	AdminUserDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~AdminUserDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADMIN_USER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
