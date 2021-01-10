// SignupDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Book_Management.h"
#include "SignupDlg.h"
#include "afxdialogex.h"


// SignupDlg 대화 상자

IMPLEMENT_DYNAMIC(SignupDlg, CDialogEx)

SignupDlg::SignupDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SIGNUP, pParent)
{

}

SignupDlg::~SignupDlg()
{
}

void SignupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SignupDlg, CDialogEx)
END_MESSAGE_MAP()


// SignupDlg 메시지 처리기
