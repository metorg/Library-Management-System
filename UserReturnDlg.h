#pragma once


// UserReturnDlg 대화 상자

class UserReturnDlg : public CDialogEx
{
	DECLARE_DYNAMIC(UserReturnDlg)

public:
	UserReturnDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~UserReturnDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USER_RETURN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
