// AddEditDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Book_Management.h"
#include "AddEditDlg.h"
#include "afxdialogex.h"


// AddEditDlg 대화 상자

IMPLEMENT_DYNAMIC(AddEditDlg, CDialogEx)

AddEditDlg::AddEditDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD_EDIT, pParent)
{

}

AddEditDlg::~AddEditDlg()
{
}

void AddEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddEditDlg, CDialogEx)
END_MESSAGE_MAP()


// AddEditDlg 메시지 처리기
