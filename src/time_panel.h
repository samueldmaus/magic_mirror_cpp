#ifndef TIME_PANEL_H
#define TIME_PANEL_H

#include <wx/wx.h>

class MyPanel : public wxPanel
{
public:
    MyPanel(wxFrame* frame, int id);
    wxStaticText* text;
};

#endif