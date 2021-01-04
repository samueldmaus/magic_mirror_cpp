#include "MirrorFrame.h"

MirrorFrame::MirrorFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxPoint(-1, -1)) 
{
    wxInitAllImageHandlers();
    wxBoxSizer *vbox = new wxBoxSizer(wxHORIZONTAL);
    time_date_panel = new TimePanel(this);
    time_date_panel->SetBackgroundColour(wxColor(100, 100, 200));
    vbox->Add(time_date_panel, 0);
    this->SetSizer(vbox);
    this->Layout();
}