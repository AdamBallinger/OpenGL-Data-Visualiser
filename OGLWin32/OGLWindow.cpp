#include "OGLWindow.h"
#include "FontRenderer.h"

#include <Windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>

#include <iostream>

OGLWindow::OGLWindow()
{
	// Default chart
	currentChart = SCATTERPLOT3D;
	// Sets default scale (zoom)
	global_scale = DEFAULT_SCALE;
	offsetX = 1.0;
	offsetY = 1.0;
	shouldOffset = FALSE;
}

OGLWindow::~OGLWindow()
{
	// Delete the charts from memory.
	delete barChart;
	delete pieChart;
	delete lineChart;
	delete scatterPlot2D;
	delete scatterPlot3D;
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

	barChart = new BarChart("Total Number of Males and Females");
	//barChart->ReadData();

	pieChart = new PieChart("Marital-Status");
	//pieChart->ReadData();

	lineChart = new LineChart("Global Active Power Usage");
	lineChart->ReadData();

	scatterPlot2D = new ScatterPlot2D("Ice Cream Sales and Temperature");
	//scatterPlot2D->ReadData();

	scatterPlot3D = new ScatterPlot3D("Ice Cream Sales, Temperature and Age");
	scatterPlot3D->ReadData();

	return TRUE;
}

void OGLWindow::SetVisible ( BOOL visible )
{
	ShowWindow ( m_hwnd, visible? SW_SHOW : SW_HIDE );
	InitOGLState();
}

void OGLWindow::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	// Scale the rendered geometry
	glScaled(global_scale, global_scale, global_scale);

	// Offset the geometry by x and y offset values from point 0, 0
	glTranslated(offsetX, -offsetY, 0.0);

	// Control which chart is rendered from the tool bar
	switch (currentChart)
	{
	case BARCHART:
		barChart->Draw();
		break;

	case PIECHART:
		pieChart->Draw(0, 0, 300.0f);
		break;

	case LINECHART:
		lineChart->Draw();
		break;

	case SCATTERPLOT2D:
		scatterPlot2D->Draw();
		break;

	case SCATTERPLOT3D:
		//gluLookAt(m_width / 2, m_height / 2, 1, m_width / 2, m_height / 2, 0, 0, 1, 0);
		scatterPlot3D->Draw();
		break;

	default:
		barChart->Draw();
		break;
	}
	
	glFlush();

	SwapBuffers(m_hdc);
	return;
}

void OGLWindow::Resize( int width, int height )
{
	m_width = width;
	m_height = height;

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( -0.5*width, 0.5*width, -0.5*height, 0.5*height, 1000.0f, -1000.0f);
	
	glMatrixMode( GL_MODELVIEW );
	glViewport(0, 0, width, height);

	return;
}

void OGLWindow::InitOGLState()
{
	glClearColor( 0.1f, 0.1f, 0.1f, 1.0f );
	glShadeModel(GL_FLAT);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	// Load the font file the FontRenderer uses to save performance. Enables GL_TEXTURE_2D & GL_BLEND as glfont requires them to be enabled when font is being created.
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	FontRenderer::Init();
	glDisable(GL_TEXTURE_2D);
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

BOOL OGLWindow::MouseMove ( int x, int y )
{
	if (shouldOffset)
	{
		// X panning
		if (lastX > x)
		{
			SetOffsetX(-lastX + x);
		}
		else if (lastX < x)
		{
			SetOffsetX(x - lastX);
		}

		// Y panning
		if (lastY > y)
		{
			SetOffsetY(-lastY + y);
		}
		else if (lastY < y)
		{
			SetOffsetY(y - lastY);
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

	default:
		break;
	}
	return TRUE;
}

BOOL OGLWindow::MouseWheelMove(int mouseWheelDelta)
{
	if (mouseWheelDelta > 0)
	{		
		global_scale += 0.05;
	}
	else if (mouseWheelDelta < 0 && global_scale > 0.35)
	{
		global_scale -= 0.05;
	}
	return TRUE;
}

void OGLWindow::SetVSync(bool sync)
{
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
	global_scale = DEFAULT_SCALE;
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

void OGLWindow::SetChart(CHART chart)
{
	// Reset the view to default zoom and pan when changing charts
	ResetView();
	currentChart = chart;
}