// UserRentalDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Book_Management.h"
#include "UserRentalDlg.h"
#include "afxdialogex.h"


// UserRentalDlg 대화 상자

IMPLEMENT_DYNAMIC(UserRentalDlg, CDialogEx)

UserRentalDlg::UserRentalDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_USER_RENTAL, pParent)
{

}

UserRentalDlg::~UserRentalDlg()
{
}

void UserRentalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UserRentalDlg, CDialogEx)
END_MESSAGE_MAP()


// UserRentalDlg 메시지 처리기
