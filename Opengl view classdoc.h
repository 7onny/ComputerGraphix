// OpenGL View ClassDoc.h : interface of the COpenGLViewClassDoc class
//
/////////////////////////////////////////////////////////////////////////////
#ifndef COPEN
#define COPEN

class COpenGLViewClassDoc : public CDocument
{
protected: // create from serialization only
	COpenGLViewClassDoc();
	DECLARE_DYNCREATE(COpenGLViewClassDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenGLViewClassDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COpenGLViewClassDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COpenGLViewClassDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	virtual void SetTitle(LPCTSTR lpszTitle);
	double rotx;
	double roty;
	double eyex;
	double eyey;
	double eyez;
	double dirx;
	double diry;
	double dirz;
	bool check;
	double m_bx;
	double m_by;
	double m_bz;
	double m_dx;
	double m_dy;
	double m_dz;
	double m_phi;
};
#endif
/////////////////////////////////////////////////////////////////////////////
