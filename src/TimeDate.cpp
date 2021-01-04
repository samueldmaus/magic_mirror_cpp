#include "TimeDate.h"

TimePanel::TimePanel(wxFrame* parent, wxWindowID id, wxPoint point, wxSize size)
       : wxPanel(parent, id, point, size)
{
    digital_clock_display = new wxStaticText(this, wxID_ANY, "");
    wxFont font = digital_clock_display->GetFont();
    font.MakeBold().MakeLarger();
    UpdateClock();
    PaintAnalogClock(this);
    digital_clock_timer.Bind(wxEVT_TIMER, &TimePanel::OnUpdateClock, this);
    digital_clock_timer.Start(1000);
}

void TimePanel::OnUpdateClock(wxTimerEvent&) {
    UpdateClock();
}

void TimePanel::UpdateClock() {
    // update the digital clock
    digital_clock_display->SetLabel(wxDateTime::Now().FormatTime());
}

void TimePanel::PaintAnalogClock(wxPanel *panel) {
    wxClientDC time_dc(panel);
    time_dc.DrawCircle(10, 10, 10);
}