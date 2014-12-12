#pragma once

#include <Windows.h>
#include "BarChart.h"
#include "BarChart3D.h"
#include "LineChart.h"
#include "PieChart.h"
#include "ScatterPlot2D.h"
#include "ScatterPlot3D.h"

class OGLWindow
{
	private:
		HWND		m_hwnd;				//handle to a window
		HDC			m_hdc;				//handle to a device context
		HGLRC		m_hglrc;			//handle to a gl rendering context

		int			m_width;
		int			m_height;

		// global scale value for all geometry
		double global_scale;

		// Store last x and y positions of mouse for panning.
		int lastX;
		int lastY;

		// offset for panning.
		bool shouldOffset;
		double offsetX;
		double offsetY;

		// offset speed for arrow keys
		double X_SPEED = 20.0;
		double Y_SPEED = 20.0;

		// Flag to check if the current view is in 2D or 3D.
		bool is2DView;

		// Default offset
		const double DEFAULT_X = 1.0;
		const double DEFAULT_Y = 1.0;

		// Default Scale
		const double DEFAULT_SCALE = 0.6;

		// keyboard bindings for key handling
		// Key number 1
		static const byte KEY_1 = 0x31;

		//This is not an ideal place to hold geometry data
		BarChart * barChart;
		BarChart3D * barChart3D;
		LineChart * lineChart;
		PieChart * pieChart;
		ScatterPlot2D * scatterPlot2D;
		ScatterPlot3D * scatterPlot3D;

    protected:

		HGLRC CreateOGLContext (HDC hdc);
		BOOL DestroyOGLContext();
		BOOL InitWindow(HINSTANCE hInstance, int width, int height);
		void InitOGLState();

	public:

		// Current chart that should be rendered to the screen.
		enum CHART { BARCHART, BARCHART3D, PIECHART, LINECHART, SCATTERPLOT2D, SCATTERPLOT3D };

		CHART currentChart;

					OGLWindow();
					OGLWindow(HINSTANCE hInstance, int width, int height);
					~OGLWindow();

		void		Render();
		void		Resize( int width, int height );
		void		SetVisible( BOOL visible );
		void		DestroyOGLWindow();

		void		SetVSync(bool);
		void		ResetView();

		void		SetChart(CHART);

		void		Create3DView();
		void        Create2DView();

		void		SetOffsetX(double);
		void		SetOffsetY(double);

		BOOL		MouseLBDown ( int x, int y );
		BOOL		MouseLBUp ( int x, int y );
		BOOL		MouseRBDown(int x, int y);
		BOOL		MouseRBUp(int x, int y);
		BOOL		MouseMove ( int x, int y );
		BOOL		MouseWheelMove(int);
		// Handles keyboard input
		BOOL		HandleKey(WPARAM);
};