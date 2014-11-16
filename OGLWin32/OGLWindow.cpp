#include "OGLWindow.h"
#include "Resource.h"
#include <gl/GL.h>
#include <GL/freeglut.h>
#include <vector>

#include <iostream>

OGLWindow::OGLWindow()
{
	// Sets default scale to 0
	global_scale = 1.0;
	offsetX = 1.0;
	offsetY = 1.0;
	shouldOffset = FALSE;
}

OGLWindow::~OGLWindow()
{
	//DestroyOGLContext();
	
	//Clean up the renderable
	delete barChart;
	delete pieChart;
	delete lineChart;
}

OGLWindow::OGLWindow(HINSTANCE hInstance, int width, int height) : OGLWindow::OGLWindow()
{
	InitWindow(hInstance, width, height);
}

HGLRC OGLWindow::CreateOGLContext(HDC hdc)
{
	unsigned int pixelformat;
	HGLRC hglrc;

	static PIXELFORMATDESCRIPTOR pfd = 
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Support Window
		PFD_SUPPORT_OPENGL |						// Format Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request RGBA Format
		32,											// Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits mask
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// Z-Buffer depth
		0,											// Stencil Buffer
		0,											// Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(pixelformat=ChoosePixelFormat(hdc,&pfd)))
	{
		return 0;
	}

	if(!SetPixelFormat(hdc,pixelformat,&pfd))
	{
		return 0;
	}

	if (!(hglrc=wglCreateContext(hdc)))
	{
		return 0;
	}

	if(!wglMakeCurrent(hdc,hglrc))
	{
		return 0;
	}

	return hglrc;
}

void OGLWindow::DestroyOGLWindow()
{
	DestroyOGLContext();

	DestroyWindow( m_hwnd );

	m_hwnd = NULL;
	m_hdc = NULL;
}

BOOL OGLWindow::DestroyOGLContext()
{
	if ( m_hglrc )
	{
		wglMakeCurrent( NULL, NULL );
		wglDeleteContext( m_hglrc );
		m_hglrc = NULL;
	}
	
	if ( !ReleaseDC ( m_hwnd, m_hdc ) )
		return FALSE;

	return TRUE;
}

BOOL OGLWindow::InitWindow(HINSTANCE hInstance, int width, int height)
{
	m_hwnd = CreateWindowEx( WS_EX_APPWINDOW | WS_EX_WINDOWEDGE,
		L"OGLWindow", L"OpenGL Data Visualizer", WS_OVERLAPPEDWINDOW|WS_CLIPSIBLINGS|WS_CLIPCHILDREN,
		0, 0, width, height, NULL, NULL, hInstance, NULL);

	if ( ! m_hwnd )
		return FALSE;

	m_hdc = GetDC( m_hwnd );

	if ( !(m_hglrc = CreateOGLContext( m_hdc )) )
		return FALSE;

	SetVSync(true);
	
	m_width = width;
	m_height = height;

	barChart = new BarChart();
	barChart->ReadData();

	pieChart = new PieChart();

	//lineChart = new LineChart();
	//lineChart->ReadData();
	return TRUE;
}

void OGLWindow::SetVisible ( BOOL visible )
{
	ShowWindow ( m_hwnd, visible? SW_SHOW : SW_HIDE );
}

void OGLWindow::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	glTranslated(offsetX, -offsetY, 1.0);

	//barChart->Draw();
	pieChart->Draw(0, 0, 300.0f, global_scale);
	
	//lineChart->Draw();

	glFlush();

	SwapBuffers(m_hdc);
	return;
}

void OGLWindow::Resize( int width, int height )
{
	glViewport( 0, 0, width, height );

	m_width = width;
	m_height = height;
	
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( -0.5*width, 0.5*width, -0.5*height, 0.5*height, -1.0, 1.0);
	
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	return;
}

void OGLWindow::InitOGLState()
{
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
}

BOOL OGLWindow::MouseLBDown ( int x, int y )
{
	shouldOffset = TRUE;
	return TRUE;
}

BOOL OGLWindow::MouseLBUp ( int x, int y )
{
	shouldOffset = FALSE;
	return TRUE;
}

BOOL OGLWindow::MouseRBDown(int x, int y)
{
	return TRUE;
}

BOOL OGLWindow::MouseRBUp(int x, int y)
{
	return TRUE;
}

int lastX;
int lastY;
BOOL OGLWindow::MouseMove ( int x, int y )
{
	/*Listener *plistener = static_cast<Listener*>(m_rect);

	plistener->MouseMove( x - m_width / 2 , y - m_height / 2);
	*/

	const int deadSpaceY = 3;
	const int deadSpaceX = 3;

	if (shouldOffset)
	{
		// X panning
		if (lastX - deadSpaceX > x)
		{
			SetOffsetX(-X_SPEED);
		}
		else if (lastX + deadSpaceX < x)
		{
			SetOffsetX(X_SPEED);
		}

		// Y panning
		if (lastY - deadSpaceY > y)
		{
			SetOffsetY(-Y_SPEED);
		}
		else if (lastY + deadSpaceY < y)
		{
			SetOffsetY(Y_SPEED);
		}
	}

	lastX = x;
	lastY = y;
	return TRUE;
}

BOOL OGLWindow::HandleKey(WPARAM wparam)
{
	switch (wparam)
	{
	case VK_SPACE:
		ResetView();
		break;

	case VK_LEFT:
		SetOffsetX(-X_SPEED);
		break;

	case VK_RIGHT:
		SetOffsetX(X_SPEED);
		break;

	case VK_UP:
		SetOffsetY(-Y_SPEED);
		break;

	case VK_DOWN:
		SetOffsetY(Y_SPEED);
		break;

	case VK_OEM_4:
		if (X_SPEED > 5)
		{
			X_SPEED -= 5;
		}
		if (Y_SPEED > 5)
		{
			Y_SPEED -= 5;
		}
		break;

	case VK_OEM_6:
		if (X_SPEED < 50)
		{
			X_SPEED += 5;
		}
		if (Y_SPEED < 50)
		{
			Y_SPEED += 5;
		}
		break;

	default:
		break;
	}
	return TRUE;
}

void OGLWindow::SetVSync(bool sync)
{
	// Function pointer for the wgl extention function we need to enable/disable
	// vsync
	typedef BOOL(APIENTRY *PFNWGLSWAPINTERVALPROC)(int);
	PFNWGLSWAPINTERVALPROC wglSwapIntervalEXT = 0;

	const char *extensions = (char*)glGetString(GL_EXTENSIONS);

	if (strstr(extensions, "WGL_EXT_swap_control") == 0)
	{
		return;
	}
	else
	{
		wglSwapIntervalEXT = (PFNWGLSWAPINTERVALPROC)wglGetProcAddress("wglSwapIntervalEXT");

		if (wglSwapIntervalEXT)
			wglSwapIntervalEXT(sync);
	}
}

// Resets the scale and translation of the geometry drawn to the screen.
void OGLWindow::ResetView()
{
	global_scale = 1.0;
	offsetX = DEFAULT_X;
	offsetY = DEFAULT_Y;
}

void OGLWindow::SetOffsetX(double offX)
{
	offsetX += offX;
}

void OGLWindow::SetOffsetY(double offY)
{
	offsetY += offY;
}