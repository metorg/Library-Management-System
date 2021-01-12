// AddEditDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Book_Management.h"
#include "AddEditDlg.h"
#include "afxdialogex.h"

CString id;


// AddEditDlg 대화 상자

IMPLEMENT_DYNAMIC(AddEditDlg, CDialogEx)

AddEditDlg::AddEditDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD_EDIT, pParent)
{
	this->pParent = pParent;
}

AddEditDlg::~AddEditDlg()
{
}

void AddEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddEditDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ADD_OK, &AddEditDlg::OnButtonAddEditOk)
END_MESSAGE_MAP()


// AddEditDlg 메시지 처리기

BOOL AddEditDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CString title;
	CString author;
	CString publisher;
	CString isbn;
	CString quantity;

	if (((AdminBookDlg *)pParent)->editmode == TRUE)
	{
		UINT uSelectedCount = ((AdminBookDlg *)pParent)->m_list.GetSelectedCount();
		POSITION pos = ((AdminBookDlg *)pParent)->m_list.GetFirstSelectedItemPosition();
		int nSelected = ((AdminBookDlg *)pParent)->m_list.GetNextSelectedItem(pos);

		if (uSelectedCount <= 0)
		{
			MessageBox(_T("선택된 책이 없습니다."));
			this->EndDialog(IDNO);
			return TRUE;
		}
		else if (uSelectedCount > 1)
		{
			MessageBox(_T("한 개만 선택해주세요."));
			this->EndDialog(IDNO);
			return TRUE;
		}

		id = ((AdminBookDlg *)pParent)->m_list.GetItemText(nSelected, 0);
		title = ((AdminBookDlg *)pParent)->m_list.GetItemText(nSelected, 1);
		author = ((AdminBookDlg *)pParent)->m_list.GetItemText(nSelected, 2);
		publisher = ((AdminBookDlg *)pParent)->m_list.GetItemText(nSelected, 3);
		isbn = ((AdminBookDlg *)pParent)->m_list.GetItemText(nSelected, 4);
		quantity = ((AdminBookDlg *)pParent)->m_list.GetItemText(nSelected, 5);

		SetDlgItemText(IDC_EDIT_TITLE, title);
		SetDlgItemText(IDC_EDIT_AUTHOR, author);
		SetDlgItemText(IDC_EDIT_PUBLISHER, publisher);
		SetDlgItemText(IDC_EDIT_ISBN, isbn);
		SetDlgItemText(IDC_EDIT_QUANTITY, quantity);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void AddEditDlg::OnButtonAddEditOk()
{
	CString title;
	CString author;
	CString publisher;
	CString isbn;
	CString quantity;

	GetDlgItemText(IDC_EDIT_TITLE, title);
	GetDlgItemText(IDC_EDIT_AUTHOR, author);
	GetDlgItemText(IDC_EDIT_PUBLISHER, publisher);
	GetDlgItemText(IDC_EDIT_ISBN, isbn);
	GetDlgItemText(IDC_EDIT_QUANTITY, quantity);

	if (((AdminBookDlg *)pParent)->editmode == TRUE)
		((AdminBookDlg *)pParent)->EditDB(id, title, author, publisher, isbn, quantity);
	else
		((AdminBookDlg *)pParent)->InsertDB(title, author, publisher, isbn, quantity);

	((AdminBookDlg *)pParent)->PrintDB();

	this->EndDialog(IDOK);
}
