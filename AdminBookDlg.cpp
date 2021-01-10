// AdminBookDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Book_Management.h"
#include "AdminBookDlg.h"
#include "afxdialogex.h"


// AdminBookDlg 대화 상자

IMPLEMENT_DYNAMIC(AdminBookDlg, CDialogEx)

AdminBookDlg::AdminBookDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADMIN_BOOK, pParent)
{

}

AdminBookDlg::~AdminBookDlg()
{
}

void AdminBookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AdminBookDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_BOOK_ADD, &AdminBookDlg::OnButtonBookAdd)
END_MESSAGE_MAP()


// AdminBookDlg 메시지 처리기


void AdminBookDlg::OnButtonBookAdd()
{
	// 방법 1
	AddEditDlg addEditDlg;
	addEditDlg.DoModal();
}
