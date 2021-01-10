﻿// AdminDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Book_Management.h"
#include "AdminDlg.h"
#include "afxdialogex.h"

#include "AdminBookDlg.h"
#include "AdminUserDlg.h"


// AdminDlg 대화 상자

IMPLEMENT_DYNAMIC(AdminDlg, CDialogEx)

AdminDlg::AdminDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADMIN, pParent)
{

}

AdminDlg::~AdminDlg()
{
}

void AdminDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_ADMIN, m_Tab);
}


BEGIN_MESSAGE_MAP(AdminDlg, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_ADMIN, &AdminDlg::OnTcnSelchangeTabAdmin)
END_MESSAGE_MAP()


// AdminDlg 메시지 처리기


BOOL AdminDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_Tab.InsertItem(0, _T("책 관리"));
	m_Tab.InsertItem(1, _T("회원 관리"));

	m_Tab.SetCurSel(0);

	CRect rect;
	m_Tab.GetWindowRect(&rect);

	pAdminBookDlg = new AdminBookDlg;
	pAdminBookDlg->Create(IDD_ADMIN_BOOK, &m_Tab);
	pAdminBookDlg->MoveWindow(0, 25, rect.Width(), rect.Height());
	pAdminBookDlg->ShowWindow(SW_SHOW);

	pAdminUserDlg = new AdminUserDlg;
	pAdminUserDlg->Create(IDD_ADMIN_USER, &m_Tab);
	pAdminUserDlg->MoveWindow(0, 25, rect.Width(), rect.Height());
	pAdminUserDlg->ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void AdminDlg::OnTcnSelchangeTabAdmin(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int sel = m_Tab.GetCurSel();

	switch (sel)
	{
		case 0:
			pAdminBookDlg->ShowWindow(SW_SHOW);
			pAdminUserDlg->ShowWindow(SW_HIDE);
			break;
		case 1:
			pAdminBookDlg->ShowWindow(SW_HIDE);
			pAdminUserDlg->ShowWindow(SW_SHOW);
			break;
	}

	*pResult = 0;
}
