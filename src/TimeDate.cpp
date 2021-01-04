#include "TimeDate.h"

BEGIN_EVENT_TABLE(TimePanel, wxPanel)
    EVT_PAINT(TimePanel::PaintAnalogClock)
END_EVENT_TABLE()

TimePanel::TimePanel(wxFrame* parent, wxWindowID id, wxPoint point, wxSize size)
       : wxPanel(parent, id, point, size)
{
    digital_clock_display = new wxStaticText(this, wxID_ANY, "");
    wxFont font = digital_clock_display->GetFont();
    font.MakeBold().MakeLarger();
    UpdateClock();
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

void TimePanel::PaintAnalogClock(wxPaintEvent &evt) {
    wxPaintDC time_dc(this);
    wxSize panel_size = GetClientSize();
    wxCoord r = 150;
    time_dc.DrawCircle(panel_size.x/2, panel_size.y/2, r);
}