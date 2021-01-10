#pragma once


// UserRentalDlg 대화 상자

class UserRentalDlg : public CDialogEx
{
	DECLARE_DYNAMIC(UserRentalDlg)

public:
	UserRentalDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~UserRentalDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USER_RENTAL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
