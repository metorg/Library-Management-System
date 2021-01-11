#pragma once


// SignupDlg 대화 상자

class SignupDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SignupDlg)

public:
	SignupDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~SignupDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SIGNUP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strID;
	CString m_strPW;
	CString m_strCPW;
	CString m_strName;
	CString m_strTel;
	afx_msg void OnButtonSignupOk();
};
