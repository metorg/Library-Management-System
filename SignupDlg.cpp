// SignupDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Book_Management.h"
#include "SignupDlg.h"
#include "afxdialogex.h"

MYSQL_ROW Sql_Row;
MYSQL_RES *Sql_Result;
MYSQL Connect;


// SignupDlg 대화 상자

IMPLEMENT_DYNAMIC(SignupDlg, CDialogEx)

SignupDlg::SignupDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SIGNUP, pParent)
	, m_strID(_T(""))
	, m_strPW(_T(""))
	, m_strCPW(_T(""))
	, m_strName(_T(""))
	, m_strTel(_T(""))
{

}

SignupDlg::~SignupDlg()
{
}

void SignupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SIGNUP_ID, m_strID);
	DDX_Text(pDX, IDC_EDIT_SIGNUP_PW, m_strPW);
	DDX_Text(pDX, IDC_EDIT_SIGNUP_CPW, m_strCPW);
	DDX_Text(pDX, IDC_EDIT_SIGNUP_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_SIGNUP_PHONE, m_strTel);
}


BEGIN_MESSAGE_MAP(SignupDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SIGNUP_OK, &SignupDlg::OnButtonSignupOk)
END_MESSAGE_MAP()


// SignupDlg 메시지 처리기


void SignupDlg::OnButtonSignupOk()
{
	UpdateData(TRUE);

	// 빈칸이 있을 경우
	if ((CStringA)m_strID == "" || (CStringA)m_strPW == "" || (CStringA)m_strCPW == "" || (CStringA)m_strName == "" || (CStringA)m_strTel == "")
	{
		MessageBox(TEXT("모든 항목을 입력해주세요."), TEXT("회원가입 실패"), MB_OK);
		return;
	}
	// 비밀번호 확인
	else if ((CStringA)m_strPW != (CStringA)m_strCPW)
	{
		MessageBox(TEXT("비밀번호를 확인해주세요."), TEXT("회원가입 실패"), MB_OK);
		return;
	}

	mysql_init(&Connect);
	mysql_real_connect(&Connect, MY_IP, DB_USER, DB_PASS, DB_NAME, 3306, (char *)NULL, 0);
	mysql_query(&Connect, "set names euckr");

	CString query;
	query.Format(_T("SELECT * FROM user WHERE id='%s'"), m_strID);
	mysql_query(&Connect, (CStringA)query);

	Sql_Result = mysql_store_result(&Connect);

	while ((Sql_Row = mysql_fetch_row(Sql_Result)) != NULL)
	{
		if (((CString)Sql_Row[0]).Compare(m_strID) == 0)
		{
			MessageBox(TEXT("이미 존재하는 아이디입니다."), TEXT("회원가입 실패"), MB_OK);
			return;
		}
	}

	query.Format(_T("INSERT INTO user (id, pw, name, tel, book) VALUES ('%s', '%s', '%s', '%s', 0)"), m_strID, m_strPW, m_strName, m_strTel);
	mysql_query(&Connect, (CStringA)query);

	Sql_Result = mysql_store_result(&Connect);

	MessageBox(query, TEXT("회원가입 성공"), MB_OK);

	mysql_close(&Connect);
	OnOK();
}
