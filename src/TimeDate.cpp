#include "TimeDate.h"

TimePanel::TimePanel(wxFrame* parent)
       : wxPanel(parent)
{
    d_clock_display = new wxStaticText(this, wxID_ANY, "");
    wxFont font = d_clock_display->GetFont();
    font.MakeBold().MakeLarger();
    UpdateClock();
    clock_timer.Bind(wxEVT_TIMER, &TimePanel::OnUpdateClock, this);
    clock_timer.Start(1000);
}

void TimePanel::OnUpdateClock(wxTimerEvent&) {
    UpdateClock();
}

void TimePanel::UpdateClock() {
    // update the digital clock
    d_clock_display->SetLabel(wxDateTime::Now().FormatTime());

    // update the analog clock
    
}