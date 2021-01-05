#include "TimeDate.h"

#define PI 3.141592653589793238462643383279502884197

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
    analog_clock_timer.Bind(wxEVT_TIMER, &TimePanel::AnalogClockUpdate, this);
    digital_clock_timer.Start(1000);
    analog_clock_timer.Start(1000);
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
    wxPoint c = wxPoint(panel_size.x/2, panel_size.y/2);
    //time_dc.DrawRectangle(panel_size.x/4, 15, panel_size.x/2, panel_size.y/8);
    time_dc.DrawCircle(c.x, c.y, r);

    for(double i = 1.0; i <= 60.0; i++) {
        double outer_x = sin(i / 60 * 2 * PI) * 150 * 0.95 + 250;
        double outer_y = -cos(i / 60 * 2 * PI) * 150 * 0.95 + 250;
        wxPoint point_outer = wxPoint(outer_x, outer_y);
        if(std::fmod(i, 5.0) == 0) {
            double inner_x = sin(i / 60 * 2 * PI) * 150 * 0.83 + 250;
            double inner_y = -cos(i / 60 * 2 * PI) * 150 * 0.83 + 250;
            wxPoint point_inner = wxPoint(inner_x, inner_y);
            time_dc.SetPen(wxPen(*wxRED_PEN));
            time_dc.DrawLine(point_inner, point_outer);
        } else {
            double inner_x = sin(i / 60 * 2 * PI) * 150 * 0.88 + 250;
            double inner_y = -cos(i / 60 * 2 * PI) * 150 * 0.88 + 250;
            wxPoint point_inner = wxPoint(inner_x, inner_y);
            time_dc.SetPen(wxPen(*wxBLACK_PEN));
            time_dc.DrawLine(point_inner, point_outer);
        }
    }
}

void TimePanel::AnalogClockUpdate(wxTimerEvent&) {
    Refresh();
}