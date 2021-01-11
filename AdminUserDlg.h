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

	BOOL m_bAscending;
	struct SORTPARAM
	{
		int iSortColumn;
		bool bSortDirect;
		CListCtrl *pList;
	};
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	void PrintDB();
	virtual BOOL OnInitDialog();
	afx_msg void OnHdnItemClickList(NMHDR *nMNHDR, LRESULT *pResult);
	static int CALLBACK CompareItem(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);
	CListCtrl m_list;
	void ConnectDB();
};
