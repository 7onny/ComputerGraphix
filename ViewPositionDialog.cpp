// ViewPositionDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ViewPositionDialog.h"
#include "afxdialogex.h"


// ViewPositionDialog dialog

IMPLEMENT_DYNAMIC(ViewPositionDialog, CDialog)

ViewPositionDialog::ViewPositionDialog(CWnd* pParent /*=NULL*/)
	: CDialog(ViewPositionDialog::IDD, pParent)
	, m_dirx(0)
	, m_diry(0)
	, m_dirz(0)
	, m_eyex(0)
	, m_eyey(0)
	, m_eyez(0)
	, check(FALSE)
{

}

ViewPositionDialog::~ViewPositionDialog()
{
}

void ViewPositionDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DIRX, m_dirx);
	DDX_Text(pDX, IDC_DIRY, m_diry);
	DDX_Text(pDX, IDC_DIRZ, m_dirz);
	DDX_Text(pDX, IDC_EYEX, m_eyex);
	DDX_Text(pDX, IDC_EYEY, m_eyey);
	DDX_Text(pDX, IDC_EYEZ, m_eyez);
	//  DDX_Control(pDX, IDC_CHECK, check);
	DDX_Check(pDX, IDC_CHECK, check);
}


BEGIN_MESSAGE_MAP(ViewPositionDialog, CDialog)
END_MESSAGE_MAP()


// ViewPositionDialog message handlers
