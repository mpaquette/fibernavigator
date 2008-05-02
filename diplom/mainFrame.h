#ifndef MAINFRAME_H_
#define MAINFRAME_H_

#include "navigationCanvas.h"
#include "mainCanvas.h"
#include "theDataset.h"

// Define a new frame
class MainFrame: public wxMDIParentFrame
{
	
private:
	TheDataset *m_dataset;

	
public:

    MainFrame(wxWindow *parent, const wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, const long style);

    void OnSize(wxSizeEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnNewWindow(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);
    void OnLoad(wxCommandEvent& event);
    void OnToggleWindow(wxCommandEvent& event);
    void OnSashDrag(wxSashEvent& event);
    void OnMouseEvent(wxMouseEvent& event);
    void OnGLEvent(wxCommandEvent &event);

public:
    int m_xclick;
    int m_yclick;
    int m_zclick;

	
private:
    wxSashLayoutWindow* m_leftWindow;
    wxSashLayoutWindow* m_mainWindow;
    wxSashLayoutWindow* m_navWindow;
    wxSashLayoutWindow* m_rightWindow;

    wxSashLayoutWindow* m_topNavWindow;
    wxSashLayoutWindow* m_middleNavWindow;
    wxSashLayoutWindow* m_bottomNavWindow;

    NavigationCanvas* m_gl0;
    NavigationCanvas* m_gl1;
    NavigationCanvas* m_gl2;
    MainCanvas* m_mainGL;
    
    wxTextCtrl* m_textWindow;
    wxPanel* m_panel1;
    wxStaticBitmap* m_statBitmap1;

DECLARE_EVENT_TABLE()
};

#define VIEWER_QUIT        wxID_EXIT
#define VIEWER_ABOUT       wxID_ABOUT
#define VIEWER_LOAD		4

#define ID_WINDOW_LEFT    	100
#define ID_WINDOW_RIGHT  	101
#define ID_WINDOW_NAV_MAIN 102

#define ID_WINDOW_NAV_X 	105
#define ID_WINDOW_NAV_Y  	106
#define ID_WINDOW_NAV_Z   	107
#define ID_WINDOW_NAV3  	108

#define ID_GL_NAV_X 	110
#define ID_GL_NAV_Y  	111
#define ID_GL_NAV_Z   	112
#define ID_GL_MAIN		113

#define NAV_SIZE 255

#endif /*MAINFRAME_H_*/
