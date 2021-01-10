// AdminUserDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Book_Management.h"
#include "AdminUserDlg.h"
#include "afxdialogex.h"


// AdminUserDlg 대화 상자

IMPLEMENT_DYNAMIC(AdminUserDlg, CDialogEx)

AdminUserDlg::AdminUserDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADMIN_USER, pParent)
{

}

AdminUserDlg::~AdminUserDlg()
{
}

void AdminUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AdminUserDlg, CDialogEx)
END_MESSAGE_MAP()


// AdminUserDlg 메시지 처리기
