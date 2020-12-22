#include "mirror.h"

// create app
bool MyApp::OnInit() {
    MirrorFrame *cpp_magic_mirror = new MirrorFrame(wxT("C++ Magic Mirror"));
    cpp_magic_mirror->Maximize();
    cpp_magic_mirror->Show(true);
    SetTopWindow(cpp_magic_mirror);
    return true;
}

MirrorFrame::MirrorFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxPoint(-1, -1))
{

}

IMPLEMENT_APP(MyApp)