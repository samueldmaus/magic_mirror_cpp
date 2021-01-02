#include <iostream>
#include "mirror.h"
#include "time_panel.h"


// create app
bool MyApp::OnInit() {
    MirrorFrame *cpp_magic_mirror = new MirrorFrame(wxT("C++ clock"));
    cpp_magic_mirror->Maximize();
    cpp_magic_mirror->Show(true);
    SetTopWindow(cpp_magic_mirror);
    return true;
}

MirrorFrame::MirrorFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxPoint(-1, -1))
{
    MyPanel *time_panel = new MyPanel(this, -1);
    wxTimer *timer = new wxTimer(this, -1);
    timer->Start();
}

MyPanel::MyPanel(wxFrame *frame, int id)
    : wxPanel(frame, id)
{

}

IMPLEMENT_APP(MyApp)