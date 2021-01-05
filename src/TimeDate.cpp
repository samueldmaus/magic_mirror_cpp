#include "TimeDate.h"
#include <cmath>
#include <iostream>

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
    //time_dc.DrawCircle(panel_size.x/2, panel_size.y/2, r);
    float outer_point = r - 5;

    time_dc.DrawLine(wxPoint(c.x, c.y + (r - 15)), wxPoint(c.x, c.y + (r - 5)));
    time_dc.DrawLine(wxPoint(c.x + (r - 15), c.y), wxPoint(c.x + (r - 5), c.y));
    time_dc.DrawLine(wxPoint(c.x - (r - 15), c.y), wxPoint(c.x - (r - 5), c.y));
    time_dc.DrawPoint(wxPoint(sin(PI)*150+250, -cos(PI)*150+250));
    for(double i = 1; i <= 60; i++) {
        double point_x = sin(i / 60 * 2 * PI) * 150 + 250;
        double point_y = -cos(i / 60 * 2 * PI) * 150 + 250;
        wxPoint dot = wxPoint(point_x, point_y);
        time_dc.DrawPoint(dot);
        std::cout << "i = " << i << "(" << point_x << ", " << point_y<< ")" << std::endl;
    }
}

void TimePanel::AnalogClockUpdate(wxTimerEvent&) {
    Refresh();
}