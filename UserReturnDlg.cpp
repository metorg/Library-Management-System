// UserReturnDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Book_Management.h"
#include "UserReturnDlg.h"
#include "afxdialogex.h"


// UserReturnDlg 대화 상자

IMPLEMENT_DYNAMIC(UserReturnDlg, CDialogEx)

UserReturnDlg::UserReturnDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_USER_RETURN, pParent)
{

}

UserReturnDlg::~UserReturnDlg()
{
}

void UserReturnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UserReturnDlg, CDialogEx)
END_MESSAGE_MAP()


// UserReturnDlg 메시지 처리기
