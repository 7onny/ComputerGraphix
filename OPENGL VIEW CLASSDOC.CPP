// OpenGL View ClassDoc.cpp : implementation of the COpenGLViewClassDoc class
//

#include "stdafx.h"
#include "OpenGL View Class.h"

#include "OpenGL View ClassDoc.h"

#define DEFAULT_EYEX 0
#define DEFAULT_EYEY 0
#define DEFAULT_EYEZ 5
#define DEFAULT_DIRX 0
#define DEFAULT_DIRY 0
#define DEFAULT_DIRZ -1

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenGLViewClassDoc

IMPLEMENT_DYNCREATE(COpenGLViewClassDoc, CDocument)

BEGIN_MESSAGE_MAP(COpenGLViewClassDoc, CDocument)
	//{{AFX_MSG_MAP(COpenGLViewClassDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenGLViewClassDoc construction/destruction

COpenGLViewClassDoc::COpenGLViewClassDoc()
{
	// TODO: add one-time construction code here

	rotx = 0.0;
	roty = 0.0;
	eyex = 0.0;
	eyey = 0.0;
	eyez = 0.0;
	dirx = 0.0;
	diry = 0.0;
	dirz = 0.0;
	check=false;
	m_bx = 0.0;
	m_by = 0.0;
	m_bz = 0.0;
	m_dx = 0.0;
	m_dy = 0.0;
	m_dz = 0.0;
	m_phi = 0.0;

}

COpenGLViewClassDoc::~COpenGLViewClassDoc()
{
}

BOOL COpenGLViewClassDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	eyex = DEFAULT_EYEX;
	eyey = DEFAULT_EYEY;
	eyez = DEFAULT_EYEZ;
	dirx = DEFAULT_DIRX;
	diry = DEFAULT_DIRY;
	dirz = DEFAULT_DIRZ;
	check= false;
	m_bx = 0.0;
	m_by = 0.0;
	m_bz = 0.0;
	m_dx = 0.0;
	m_dy = 0.0;
	m_dz = 0.0;
	m_phi = 0.0;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// COpenGLViewClassDoc serialization

void COpenGLViewClassDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// COpenGLViewClassDoc diagnostics

#ifdef _DEBUG
void COpenGLViewClassDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COpenGLViewClassDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

void COpenGLViewClassDoc::SetTitle(LPCTSTR lpszTitle) 
     {
       CDocument::SetTitle("Computer Graphics Assignment");
     }

/////////////////////////////////////////////////////////////////////////////
// COpenGLViewClassDoc commands
