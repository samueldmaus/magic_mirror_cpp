#include "TimeDate.h"

MirrorFrame::MirrorFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxPoint(-1, -1))
{
    d_clock_display = new wxStaticText(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL | wxST_NO_AUTORESIZE);
    wxFont font = d_clock_display->GetFont();
    font.MakeBold().MakeLarger();
    UpdateClock();
    clock_timer.Bind(wxEVT_TIMER, &MirrorFrame::OnUpdateClock, this);
    clock_timer.Start(1000);
}

void MirrorFrame::OnUpdateClock(wxTimerEvent&) {
    UpdateClock();
}

void MirrorFrame::UpdateClock() {
    d_clock_display->SetLabel(wxDateTime::Now().FormatTime());
}