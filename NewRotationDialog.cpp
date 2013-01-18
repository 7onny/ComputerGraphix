// NewRotationDialog.cpp : implementation file
//

#include "stdafx.h"
#include "NewRotationDialog.h"
#include "afxdialogex.h"


// NewRotationDialog dialog

IMPLEMENT_DYNAMIC(NewRotationDialog, CDialog)

NewRotationDialog::NewRotationDialog(CWnd* pParent /*=NULL*/)
	: CDialog(NewRotationDialog::IDD, pParent)
	, m_bx(0)
	, m_by(0)
	, m_bz(0)
	, m_dx(0)
	, m_dy(0)
	, m_dz(0)
	, m_phi(0)
{

}

NewRotationDialog::~NewRotationDialog()
{
}

void NewRotationDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_BX, m_bx);
	DDX_Text(pDX, IDC_BY, m_by);
	DDX_Text(pDX, IDC_BZ, m_bz);
	DDX_Text(pDX, IDC_DX, m_dx);
	DDX_Text(pDX, IDC_DY, m_dy);
	DDX_Text(pDX, IDC_DZ, m_dz);
	DDX_Text(pDX, IDC_PHI, m_phi);
}


BEGIN_MESSAGE_MAP(NewRotationDialog, CDialog)
END_MESSAGE_MAP()


// NewRotationDialog message handlers
