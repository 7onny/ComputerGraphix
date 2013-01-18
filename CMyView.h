#include "Copenglview.h"
#include "soil.h"

class CMyView : public COpenGLView {

private:
	DECLARE_DYNCREATE(CMyView);
protected:
	virtual BOOL RenderScene( void );
	virtual BOOL PreRenderScene( void );

	//added lines
	int LoadGLTextures();
	GLuint texture[4];

	DECLARE_MESSAGE_MAP()
public:
	CPoint CurrentPoint;
	bool IsLButtonDown;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnNewviewViewposition();

	virtual BOOL SetupViewingTransform( void );
	afx_msg void OnNewviewPerformcustomrotation();
};