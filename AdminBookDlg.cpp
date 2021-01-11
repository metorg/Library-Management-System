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
	DDX_Control(pDX, IDC_LIST_BOOK, m_list);
}


BEGIN_MESSAGE_MAP(AdminBookDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_BOOK_ADD, &AdminBookDlg::OnButtonBookAdd)
	ON_BN_CLICKED(IDC_BUTTON_BOOK_EDIT, &AdminBookDlg::OnButtonBookEdit)
	ON_BN_CLICKED(IDC_BUTTON_BOOK_DELETE, &AdminBookDlg::OnButtonBookDelete)
	ON_NOTIFY(HDN_ITEMCLICKA, 0, AdminBookDlg::OnHdnItemClickList)
	ON_NOTIFY(HDN_ITEMCLICKW, 0, AdminBookDlg::OnHdnItemClickList)
END_MESSAGE_MAP()


// AdminBookDlg 메시지 처리기


BOOL AdminBookDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, _T("번호"), LVCFMT_LEFT, 100, -1);
	m_list.InsertColumn(1, _T("도서 제목"), LVCFMT_LEFT, 100, -1);
	m_list.InsertColumn(2, _T("저자"), LVCFMT_LEFT, 100, -1);
	m_list.InsertColumn(3, _T("출판사"), LVCFMT_LEFT, 100, -1);
	m_list.InsertColumn(4, _T("ISBN"), LVCFMT_LEFT, 100, -1);
	m_list.InsertColumn(5, _T("수량"), LVCFMT_LEFT, 100, -1);
	//칼럼 추가 인덱스, 칼람명, 정렬방향, 칼럼길이, 서브아이템 갯수

	ConnectDB();
	PrintDB();

	for (int i = 0; i < m_list.GetHeaderCtrl()->GetItemCount(); ++i)
		m_list.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);

	//LVCOLUMN Column;
	//Column.mask = LVCF_FMT;
	//Column.fmt = LVCFMT_CENTER;
	//m_list.SetColumn(0, &Column); // 중앙 정렬

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void AdminBookDlg::OnButtonBookAdd()
{
	editmode = FALSE;
	AddEditDlg addEditDlg(this);
	addEditDlg.DoModal();
}


void AdminBookDlg::OnButtonBookEdit()
{
	editmode = TRUE;
	AddEditDlg addEditDlg(this);
	addEditDlg.DoModal();
}


void AdminBookDlg::OnButtonBookDelete()
{
	DeleteDB();
	PrintDB();
}


void AdminBookDlg::ConnectDB()
{
	mysql_init(&Connect); // 초기화
	if (!mysql_real_connect(&Connect, "localhost", DB_USER, DB_PASS, DB_NAME, 3306, (char *)NULL, 0)) // 연결
	{
		MessageBox(TEXT("DB 접속에 실패했습니다.\n응용 프로그램을 시작할 수 없습니다."), TEXT("접속 에러"), MB_OK);
		TRACE("Connection error %d: %s\n", mysql_errno(&Connect), mysql_error(&Connect));
	}
	else
	{
		mysql_query(&Connect, "set names euckr"); // 한글 인식

		TRACE("DB 연결 성공");
	}
}


void AdminBookDlg::PrintDB()
{
	CString query;
	query.Format(_T("SELECT * FROM book"));
	int seq = 0;
	CString seq_string;
	seq_string.Format(_T("%d"), seq);

	if (mysql_query(&Connect, (CStringA)query))
	{
		TRACE("Connection error %d: %s\n", mysql_errno(&Connect), mysql_error(&Connect));
		return;
	}

	if ((Sql_Result = mysql_store_result(&Connect)) == NULL)
	{
		//쿼리저장
		TRACE("Connection error %d: %s\n", mysql_errno(&Connect), mysql_error(&Connect));
		return;
	}

	m_list.DeleteAllItems(); // 리스트 초기화

	while ((Sql_Row = mysql_fetch_row(Sql_Result)) != NULL)
	{
		CString id;
		CString title;
		CString writer;
		CString publisher;
		CString isbn;
		CString quantity;

		id += Sql_Row[0];
		title += Sql_Row[1];
		writer += Sql_Row[2];
		publisher += Sql_Row[3];
		isbn += Sql_Row[4];
		quantity += Sql_Row[5];

		m_list.InsertItem(seq, _T(""));
		m_list.SetItem(seq, 0, LVIF_TEXT, id, 0, 0, 0, NULL);
		m_list.SetItem(seq, 1, LVIF_TEXT, title, 0, 0, 0, NULL);
		m_list.SetItem(seq, 2, LVIF_TEXT, writer, 0, 0, 0, NULL);
		m_list.SetItem(seq, 3, LVIF_TEXT, publisher, 0, 0, 0, NULL);
		m_list.SetItem(seq, 4, LVIF_TEXT, isbn, 0, 0, 0, NULL);
		m_list.SetItem(seq, 5, LVIF_TEXT, quantity, 0, 0, 0, NULL);

		seq++;
		seq_string.Format(_T("%d"), seq);
	}
}


void AdminBookDlg::InsertDB(CString title, CString author, CString publisher, CString isbn, CString quantity)
{
	CString query;
	query.Format(_T("INSERT INTO book(title, author, publisher, isbn, quantity) \
					values('%s', '%s', '%s', '%s', '%s')"), title, author, publisher, isbn, quantity);
	
	if(mysql_query(&Connect, (CStringA)query))
	{
		MessageBox(_T("Insert Error"));
	}
}


void AdminBookDlg::EditDB(CString id, CString title, CString author, CString publisher, CString isbn, CString quantity)
{
	CString query;
	query.Format(_T("UPDATE book SET title='%s', author='%s', publisher='%s', isbn='%s', quantity=%s WHERE id=%s"), \
		title, author, publisher, isbn, quantity, id);

	if (mysql_query(&Connect, (CStringA)query))
	{
		MessageBox(_T("Edit Error"));
	}
}


void AdminBookDlg::DeleteDB()
{
	int nCount = m_list.GetItemCount();
	std::vector<CString> id;

	for (int i = 0; i < nCount; i++)
	{
		if (m_list.GetCheck(i))
		{
			id.push_back(m_list.GetItemText(i, 0));
		}
	}

	while (!id.empty())
	{
		CString query;
		query.Format(_T("DELETE FROM book WHERE id = %s"), id.back());

		if (mysql_query(&Connect, (CStringA)query))
		{
			MessageBox(_T("Delete Error"));
		}
		id.pop_back();
	}
}

void AdminBookDlg::OnHdnItemClickList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR); // 리스트컨트롤 칼럼 클릭할 때 데이터 정렬

	// 클릭한 칼럼의 인덱스
	//int nColumn = pNMLV->iSubItem;
	int nColumn = pNMLV->iItem;

	// 현재 리스트 컨트롤에 있는 데이터 총 자료 개수만큼 저장
	for (int i = 0; i < (m_list.GetItemCount()); i++)
	{
		m_list.SetItemData(i, i);
	}

	// 정렬 방식 지정(Ascend, Descend)
	m_bAscending = !m_bAscending;

	// 정렬 관련된 구조체 변수 생성 및 데이터 초기화
	SORTPARAM sortparams;
	sortparams.pList = &m_list;
	sortparams.iSortColumn = nColumn;
	sortparams.bSortDirect = m_bAscending;

	// 정렬 함수 호출
	m_list.SortItems(&CompareItem, (LPARAM)&sortparams);

	*pResult = 0;
}

int CALLBACK AdminBookDlg::CompareItem(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	CListCtrl *pList = ((SORTPARAM *)lParamSort)->pList;
	int iSortColumn = ((SORTPARAM *)lParamSort)->iSortColumn;
	bool bSortDirect = ((SORTPARAM *)lParamSort)->bSortDirect;

	LVFINDINFO info1, info2;
	info1.flags = LVFI_PARAM;
	info1.lParam = lParam1;
	info2.flags = LVFI_PARAM;
	info2.lParam = lParam2;
	int irow1 = pList->FindItem(&info1, -1);
	int irow2 = pList->FindItem(&info2, -1);

	CString strItem1 = pList->GetItemText(irow1, iSortColumn);
	CString strItem2 = pList->GetItemText(irow2, iSortColumn);

	return bSortDirect ? strItem1.Compare(strItem2) : -strItem1.Compare(strItem2);
}
