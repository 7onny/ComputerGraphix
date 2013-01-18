#pragma once

#include"resource.h"
// NewRotationDialog dialog

class NewRotationDialog : public CDialog
{
	DECLARE_DYNAMIC(NewRotationDialog)

public:
	NewRotationDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~NewRotationDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG_ROTATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_bx;
	double m_by;
	double m_bz;
	double m_dx;
	double m_dy;
	double m_dz;
	double m_phi;
};
