#pragma once


// ViewPositionDialog dialog

#include"resource.h"
#include "afxwin.h"

class ViewPositionDialog : public CDialog
{
	DECLARE_DYNAMIC(ViewPositionDialog)

public:
	ViewPositionDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~ViewPositionDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG_VIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_dirx;
	double m_diry;
	double m_dirz;
	double m_eyex;
	double m_eyey;
	double m_eyez;
//	CButton check;
	BOOL check;
};
