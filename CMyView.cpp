#include "CMyView.h"
#include"ViewPositionDialog.h"
#include"NewRotationDialog.h"
#include <cmath>
IMPLEMENT_DYNCREATE(CMyView, COpenGLView)

BEGIN_MESSAGE_MAP(CMyView, COpenGLView)
	//{{AFX_MSG_MAP(COpenGLView)
	
	//}}AFX_MSG_MAP
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_NEWVIEW_VIEWPOSITION, &CMyView::OnNewviewViewposition)
	ON_COMMAND(ID_NEWVIEW_PERFORMCUSTOMROTATION, &CMyView::OnNewviewPerformcustomrotation)
END_MESSAGE_MAP()

BOOL CMyView::SetupViewingTransform( void ){
	COpenGLViewClassDoc *pDoc=GetDocument();
	::glMatrixMode(GL_MODELVIEW);
	::glLoadIdentity();
	if(pDoc->check){	//Check output with glLookAt
		::gluLookAt(pDoc->eyex,pDoc->eyey,pDoc->eyez,pDoc->dirx,pDoc->diry,pDoc->dirz,0,1,0);
	}
	else{
		//U
		double w=sqrt((pDoc->dirx*pDoc->dirx)+(pDoc->diry*pDoc->diry)+(pDoc->dirz*pDoc->dirz));
		::glRotatef(atan2(-(pDoc->diry*pDoc->dirz),(w*pDoc->dirx))*(360/(2*3.141592)),0,0,1);
		//H
		double v=sqrt((pDoc->dirx*pDoc->dirx)+(pDoc->diry*pDoc->diry));
		::glRotatef(atan2(v,-(pDoc->dirz))*(360/(2*3.141592)),0,1,0);
		//G
		::glRotatef(atan2(-pDoc->diry,pDoc->dirx)*(360/(2*3.141592)),0,0,1);
		//F
		::glTranslated(-pDoc->eyex,-pDoc->eyey,-pDoc->eyez);
	
	}
	return true;
}


BOOL CMyView::RenderScene()
{
	SetupViewingTransform();
	COpenGLViewClassDoc *pDoc=GetDocument();
	//Rotation
	if(pDoc->m_phi!=0){
		//F^-1
		::glTranslated(pDoc->m_bx,pDoc->m_by,pDoc->m_bz);
		//G^-1
		::glRotated(-atan2(pDoc->m_dy,pDoc->m_dx)*(360/2*3.141592),0,0,1);
		//H^-1
		double v=sqrt((pDoc->m_dx*pDoc->m_dx)+(pDoc->m_dy*pDoc->m_dy));
		::glRotated(-atan2(v,-(pDoc->m_dz))*(360/(2*3.141592)),0,1,0);
		//W
		::glRotated(pDoc->m_phi,0,0,1);
		//H
		v=sqrt((pDoc->m_dx*pDoc->m_dx)+(pDoc->m_dy*pDoc->m_dy));
		::glRotated(atan2(v,-(pDoc->m_dz))*(360/(2*3.141592)),0,1,0);
		//G
		::glRotated(atan2(pDoc->m_dy,pDoc->m_dx)*(360/2*3.141592),0,0,1);
		//F
		::glTranslated(-pDoc->m_bx,-pDoc->m_by,-pDoc->m_bz);
	}

	//added lines
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture[0]);

	GLfloat LightAmbient[] =  { 0.1f, 0.1f, 0.1f, 0.1f};
	GLfloat LightDiffuse[] =  { 0.7f, 0.7f, 0.7f, 0.7f};
	GLfloat LightSpecular[] = { 0.0f, 0.0f, 0.0f, 0.1f};
	GLfloat LightPosition[] = { 5.0f, 5.0f, 5.0f, 0.0f}; 

	GLfloat RedSurface[]   = { 1.0f, 0.0f, 0.0f, 1.0f};
	GLfloat GreenSurface[] = { 0.0f, 1.0f, 0.0f, 1.0f};
	GLfloat BlueSurface[]  = { 0.0f, 0.0f, 1.0f, 1.0f};
	GLfloat WhiteSurface[] = { 1.0f, 1.0f, 1.0f, 1.0f};

	::glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	::glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
	::glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
	::glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);
	::glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
	::glEnable(GL_LIGHT0);

	::glPushMatrix();	
		::glTranslated(0.0, 0.0, -5.0);
		//COpenGLViewClassDoc* pDoc = GetDocument();
		::glRotated(pDoc->rotx,1.0,0.0,0.0);
		::glRotated(pDoc->roty,0.0,1.0,0.0);

		::glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, WhiteSurface);

		::glBegin(GL_POLYGON);		
			// Front Face
			::glNormal3f( 0.0f, 0.0f, 1.0f);     // Normal Pointing Towards Viewer
			::glTexCoord2f(0.0f, 0.0f); ::glVertex3f(-1.0f, -1.0f,  1.0f);  // Point 1 (Front)
			// Bottom Left Of The Texture and Face
			::glTexCoord2f(1.0f, 0.0f); ::glVertex3f( 1.0f, -1.0f,  1.0f);  // Point 2 (Front)
			// Bottom Right Of The Texture and Face
			::glTexCoord2f(1.0f, 1.0f); ::glVertex3f( 1.0f,  1.0f,  1.0f);  // Point 3 (Front)
									// Top Right Of The Texture and Face
			::glTexCoord2f(0.0f, 1.0f); ::glVertex3f(-1.0f,  1.0f,  1.0f);  // Point 4 (Front)
			// Top Left Of The Texture and Face
			::glEnd();   

			glBindTexture(GL_TEXTURE_2D,texture[1]);
		::glBegin(GL_POLYGON);	
			// Back Face
			::glNormal3f( 0.0f, 0.0f,-1.0f);        // Normal Pointing Away From Viewer
			::glTexCoord2f(1.0f, 0.0f); ::glVertex3f(-1.0f, -1.0f, -1.0f);  // Point 1 (Back)
			// Bottom Right Of The Texture and Face
			::glTexCoord2f(1.0f, 1.0f); ::glVertex3f(-1.0f,  1.0f, -1.0f);  // Point 2 (Back)
			// Top Right Of The Texture and Face
			::glTexCoord2f(0.0f, 1.0f); ::glVertex3f( 1.0f,  1.0f, -1.0f);  // Point 3 (Back)
			// Top Left Of The Texture and Face
			::glTexCoord2f(0.0f, 0.0f); ::glVertex3f( 1.0f, -1.0f, -1.0f);  // Point 4 (Back)
			// Bottom Left Of The Texture and Face
			::glEnd();   

			glBindTexture(GL_TEXTURE_2D,texture[2]);
		::glBegin(GL_POLYGON);	
			// Top Face
			::glNormal3f( 0.0f, 1.0f, 0.0f);                  // Normal Pointing Up
			::glTexCoord2f(0.0f, 1.0f); ::glVertex3f(-1.0f,  1.0f, -1.0f);  // Point 1 (Top)
			// Top Left Of The Texture and Face
			::glTexCoord2f(0.0f, 0.0f); ::glVertex3f(-1.0f,  1.0f,  1.0f);  // Point 2 (Top)
			// Bottom Left Of The Texture and Face
			::glTexCoord2f(1.0f, 0.0f); ::glVertex3f( 1.0f,  1.0f,  1.0f);  // Point 3 (Top)
			// Bottom Right Of The Texture and Face
			::glTexCoord2f(1.0f, 1.0f); ::glVertex3f( 1.0f,  1.0f, -1.0f);  // Point 4 (Top)
			// Top Right Of The Texture and Face
			::glEnd();   

		::glBegin(GL_POLYGON);	
			// Bottom Face
			::glNormal3f( 0.0f,-1.0f, 0.0f);                  // Normal Pointing Down
			::glTexCoord2f(1.0f, 1.0f); ::glVertex3f(-1.0f, -1.0f, -1.0f);  // Point 1 (Bottom)
			// Top Right Of The Texture and Face
			::glTexCoord2f(0.0f, 1.0f); ::glVertex3f( 1.0f, -1.0f, -1.0f);  // Point 2 (Bottom)
			// Top Left Of The Texture and Face
			::glTexCoord2f(0.0f, 0.0f); ::glVertex3f( 1.0f, -1.0f,  1.0f);  // Point 3 (Bottom)
			// Bottom Left Of The Texture and Face
			::glTexCoord2f(1.0f, 0.0f); ::glVertex3f(-1.0f, -1.0f,  1.0f);  // Point 4 (Bottom)
			// Bottom Right Of The Texture and Face
			::glEnd();   

		::glBegin(GL_POLYGON);	
			// Right face
			::glNormal3f( 1.0f, 0.0f, 0.0f);                  // Normal Pointing Right
			::glTexCoord2f(1.0f, 0.0f); ::glVertex3f( 1.0f, -1.0f, -1.0f);  // Point 1 (Right)
			// Bottom Right Of The Texture and Face
			::glTexCoord2f(1.0f, 1.0f); ::glVertex3f( 1.0f,  1.0f, -1.0f);  // Point 2 (Right)
			// Top Right Of The Texture and Face
			::glTexCoord2f(0.0f, 1.0f); ::glVertex3f( 1.0f,  1.0f,  1.0f);  // Point 3 (Right)
			// Top Left Of The Texture and Face
			::glTexCoord2f(0.0f, 0.0f); ::glVertex3f( 1.0f, -1.0f,  1.0f);  // Point 4 (Right)
			// Bottom Left Of The Texture and Face
			::glEnd();   

		::glBegin(GL_POLYGON);	
			// Left Face
			::glNormal3f(-1.0f, 0.0f, 0.0f);                  // Normal Pointing Left
			::glTexCoord2f(0.0f, 0.0f); ::glVertex3f(-1.0f, -1.0f, -1.0f);  // Point 1 (Left)
			// Bottom Left Of The Texture and Face
			::glTexCoord2f(1.0f, 0.0f); ::glVertex3f(-1.0f, -1.0f,  1.0f);  // Point 2 (Left)
			// Bottom Right Of The Texture and Face
			::glTexCoord2f(1.0f, 1.0f); ::glVertex3f(-1.0f,  1.0f,  1.0f);  // Point 3 (Left)
			// Top Right Of The Texture and Face
			::glTexCoord2f(0.0f, 1.0f); ::glVertex3f(-1.0f,  1.0f, -1.0f);  // Point 4 (Left)
			// Top Left Of The Texture and Face
			::glEnd();                      



	::glPopMatrix();
	return TRUE;
}



BOOL CMyView::PreRenderScene( void )
{
	::glDrawBuffer( GL_BACK );
	::glEnable( GL_LIGHTING );
	return TRUE;
}

void CMyView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// store the current CPoint where the mouse was clicked
	CurrentPoint = point;

	// set the flag to be true
	IsLButtonDown = true;

	COpenGLView::OnLButtonDown(nFlags, point);
}


void CMyView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// set the flag to be false
	IsLButtonDown = false;

	COpenGLView::OnLButtonUp(nFlags, point);
}


void CMyView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	double new_rotation;

	if (IsLButtonDown)
	{
		COpenGLViewClassDoc* pDoc = GetDocument();

		new_rotation = point.x - CurrentPoint.x;

		pDoc->roty += new_rotation/2;

		new_rotation = point.y - CurrentPoint.y;

		pDoc->rotx += new_rotation/2;

		CurrentPoint = point;

		InvalidateRect(FALSE);
	} else {

		COpenGLView::OnMouseMove(nFlags, point);
	}
}

int CMyView::LoadGLTextures(){
	/* load an image file directly as a new OpenGL texture */
	texture[0] = SOIL_load_OGL_texture
	(
	"image.bmp",
	SOIL_LOAD_AUTO,
	SOIL_CREATE_NEW_ID,
	SOIL_FLAG_INVERT_Y
	);
	if(texture[0] == 0)
	return false;
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	texture[1] = SOIL_load_OGL_texture
	(
	"2.bmp",
	SOIL_LOAD_AUTO,
	SOIL_CREATE_NEW_ID,
	SOIL_FLAG_INVERT_Y
	);
	if(texture[1] == 0)
	return false;
	glBindTexture(GL_TEXTURE_2D, texture[1]);

	texture[2] = SOIL_load_OGL_texture
	(
	"3.bmp",
	SOIL_LOAD_AUTO,
	SOIL_CREATE_NEW_ID,
	SOIL_FLAG_INVERT_Y
	);
	if(texture[2] == 0)
	return false;
	glBindTexture(GL_TEXTURE_2D, texture[2]);

	texture[3] = SOIL_load_OGL_texture
	(
	"4.bmp",
	SOIL_LOAD_AUTO,
	SOIL_CREATE_NEW_ID,
	SOIL_FLAG_INVERT_Y
	);
	if(texture[3] == 0)
	return false;
	glBindTexture(GL_TEXTURE_2D, texture[3]);

	// Typical Texture Generation Using Data From The Bitmap
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	return true;
}


int CMyView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COpenGLView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	// Load texture from file.
	IsLButtonDown=false;
	if (!LoadGLTextures()) return -1;

	return 0;
}


void CMyView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	COpenGLViewClassDoc *pDoc=GetDocument();
	//Set defaults on double click
	pDoc->eyex = 0;
	pDoc->eyey = 0;
	pDoc->eyez = 5;
	pDoc->dirx = 0;
	pDoc->diry = 0;
	pDoc->dirz = -1;
	pDoc->check= false;
	pDoc->m_bx=0;
	pDoc->m_by=0;
	pDoc->m_bz=0;
	pDoc->m_dx=0;
	pDoc->m_dy=0;
	pDoc->m_dz=0;
	pDoc->m_phi=0;

	COpenGLView::OnLButtonDblClk(nFlags, point);
	InvalidateRect(FALSE);
}


void CMyView::OnNewviewViewposition()
{
	// TODO: Add your command handler code here
	ViewPositionDialog dlgVPD;
	if(dlgVPD.DoModal()!=0){
		COpenGLViewClassDoc *pDoc=GetDocument();
		pDoc->eyex=dlgVPD.m_eyex;
		pDoc->eyey=dlgVPD.m_eyey;
		pDoc->eyez=dlgVPD.m_eyez;
		pDoc->dirx=dlgVPD.m_dirx;
		pDoc->diry=dlgVPD.m_diry;
		pDoc->dirz=dlgVPD.m_dirz;
		pDoc->check=dlgVPD.check;
	}
	//We have the values from the dialog box at this point
	InvalidateRect(FALSE);
}


void CMyView::OnNewviewPerformcustomrotation()
{
	// TODO: Add your command handler code here
	NewRotationDialog dlg;
	if(dlg.DoModal()!=0){
		COpenGLViewClassDoc *pDoc=GetDocument();
		pDoc->m_bx=dlg.m_dx;
		pDoc->m_by=dlg.m_dy;
		pDoc->m_bz=dlg.m_dz;
		pDoc->m_dx=dlg.m_dx;
		pDoc->m_dy=dlg.m_dy;
		pDoc->m_dz=dlg.m_dz;
		pDoc->m_phi=dlg.m_phi;
	}
	InvalidateRect(FALSE);
}
