#include "TimeDate.h"

MirrorFrame::MirrorFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxPoint(-1, -1))
{
    wxTimer *timer = new wxTimer(this, -1);
    timer->Start(200);
}