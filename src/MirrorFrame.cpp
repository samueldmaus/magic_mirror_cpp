#include "MirrorFrame.h"

MirrorFrame::MirrorFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxPoint(-1, -1)) 
{
    wxInitAllImageHandlers();
    vbox = new wxBoxSizer(wxHORIZONTAL);
    time_date_panel = new TimePanel(this, wxID_ANY, wxDefaultPosition, wxSize(500 ,500));
    time_date_panel->SetBackgroundColour(wxColor(220, 245, 255));
    vbox->Add(time_date_panel, 0);
    this->SetSizerAndFit(vbox);
    this->Layout();
}