#include "Mirror.h"
#include "TimeDate.h"

// create app
bool MyApp::OnInit() {
    MirrorFrame *cpp_magic_mirror = new MirrorFrame(wxT("C++ Magic Mirror"));
    cpp_magic_mirror->Maximize();
    cpp_magic_mirror->Show(true);
    SetTopWindow(cpp_magic_mirror);
    return true;
}

IMPLEMENT_APP(MyApp)