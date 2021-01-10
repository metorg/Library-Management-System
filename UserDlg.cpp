// UserDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Book_Management.h"
#include "UserDlg.h"
#include "afxdialogex.h"

#include "UserRentalDlg.h"
#include "UserReturnDlg.h"

// UserDlg 대화 상자

IMPLEMENT_DYNAMIC(UserDlg, CDialogEx)

UserDlg::UserDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_USER, pParent)
{

}

UserDlg::~UserDlg()
{
}

void UserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_USER, m_Tab);
}


BEGIN_MESSAGE_MAP(UserDlg, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_USER, &UserDlg::OnTcnSelchangeTabUser)
END_MESSAGE_MAP()


// UserDlg 메시지 처리기


BOOL UserDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_Tab.InsertItem(0, _T("책 대여"));
	m_Tab.InsertItem(1, _T("책 반납"));

	m_Tab.SetCurSel(0);

	CRect rect;
	m_Tab.GetWindowRect(&rect);

	pUserRentalDlg = new UserRentalDlg;
	pUserRentalDlg->Create(IDD_USER_RENTAL, &m_Tab);
	pUserRentalDlg->MoveWindow(0, 25, rect.Width(), rect.Height());
	pUserRentalDlg->ShowWindow(SW_SHOW);

	pUserReturnDlg = new UserReturnDlg;
	pUserReturnDlg->Create(IDD_USER_RETURN, &m_Tab);
	pUserReturnDlg->MoveWindow(0, 25, rect.Width(), rect.Height());
	pUserReturnDlg->ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void UserDlg::OnTcnSelchangeTabUser(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int sel = m_Tab.GetCurSel();

	switch (sel)
	{
		case 0:
			pUserRentalDlg->ShowWindow(SW_SHOW);
			pUserReturnDlg->ShowWindow(SW_HIDE);
			break;
		case 1:
			pUserRentalDlg->ShowWindow(SW_HIDE);
			pUserReturnDlg->ShowWindow(SW_SHOW);
			break;
	}

	*pResult = 0;
}
