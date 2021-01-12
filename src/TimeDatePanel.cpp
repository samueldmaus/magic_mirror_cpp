#include "TimeDatePanel.h"

#define PI 3.141592653589793238462643383279502884197

BEGIN_EVENT_TABLE(TimePanel, wxPanel)
    EVT_PAINT(TimePanel::PaintAnalogClock)
END_EVENT_TABLE()

TimePanel::TimePanel(wxFrame* parent, wxWindowID id, wxPoint point, wxSize size)
       : wxPanel(parent, id, point, size)
{
    time_sizer = new wxBoxSizer(wxHORIZONTAL);
    digital_clock_display = new wxStaticText(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL | wxST_NO_AUTORESIZE);
    time_sizer->Add(digital_clock_display, 1, wxEXPAND);
    UpdateClock();
    digital_clock_timer.Bind(wxEVT_TIMER, &TimePanel::OnUpdateClock, this);
    analog_clock_timer.Bind(wxEVT_TIMER, &TimePanel::AnalogClockUpdate, this);
    digital_clock_timer.Start(1000);
    analog_clock_timer.Start(1000);
    this->SetSizer(time_sizer);
}

void TimePanel::OnUpdateClock(wxTimerEvent&) {
    UpdateClock();
}

void TimePanel::UpdateClock() {
    // update the digital clock
    wxDateTime time = wxDateTime::Now();
    std::pair<wxDateTime, std::string> time_pair = AMorPM(time);
    digital_clock_display->SetLabel(time_pair.first.FormatTime() + " " + time_pair.second);
}

std::pair<wxDateTime, std::string> TimePanel::AMorPM(wxDateTime &time){
    std::string meridiem;
    int hr = time.GetHour();
    int min = time.GetMinute();
    int sec = time.GetSecond();
    if(hr == 0) {
        time.SetHour(12);
        meridiem = "AM";
    } else if (hr >= 12) {
        if(hr == 12) {
            meridiem = "PM";
        } else {
            time.SetHour(hr - 12);
            meridiem = "PM";
        }
    } else {
        meridiem = "AM";
    }
    return make_pair(time, meridiem);
}

void TimePanel::PaintAnalogClock(wxPaintEvent &evt) {
    wxPaintDC time_dc(this);
    wxSize panel_size = GetClientSize();
    wxCoord r = 150;
    wxPoint c = wxPoint(panel_size.x/2, panel_size.y/2);
    //time_dc.DrawRectangle(panel_size.x/4, 15, panel_size.x/2, panel_size.y/8);
    time_dc.DrawCircle(c.x, c.y, r); // draw clock outline
    // draw tick marks and hour #'s on clock
    for(double i = 1.0; i <= 60.0; i++) {
        double outer_x = sin(i / 60 * 2 * PI) * 150 * 0.95 + 250;
        double outer_y = -cos(i / 60 * 2 * PI) * 150 * 0.95 + 250;
        wxPoint point_outer = wxPoint(outer_x, outer_y);
        if(std::fmod(i, 5.0) == 0) {
            double inner_x = sin(i / 60 * 2 * PI) * 150 * 0.83 + 250;
            double inner_y = -cos(i / 60 * 2 * PI) * 150 * 0.83 + 250;
            wxPoint point_inner = wxPoint(inner_x, inner_y);
            time_dc.DrawLine(point_inner, point_outer);
            double text_x = sin(i / 60 * 2 * PI) * 150 * 0.75 + 245;
            double text_y = -cos(i / 60 * 2 * PI) * 150 * 0.75 + 245;
            wxString hour_text = wxString::Format(wxT("%i"), int(i/5));
            time_dc.DrawText(hour_text, text_x, text_y);
        } else {
            double inner_x = sin(i / 60 * 2 * PI) * 150 * 0.88 + 250;
            double inner_y = -cos(i / 60 * 2 * PI) * 150 * 0.88 + 250;
            wxPoint point_inner = wxPoint(inner_x, inner_y);
            time_dc.DrawLine(point_inner, point_outer);
        }
    }
    // draw hr, min, sec hands on clock
    wxDateTime time = wxDateTime::Now();
    double hr = time.GetHour();
    double min = time.GetMinute();
    double sec = time.GetSecond();
    time_dc.SetPen(wxPen(*wxRED_PEN));
    time_dc.DrawLine(c, wxPoint(sin(sec / 60 * 2 * PI) * 150 * 0.66 + 250, -cos(sec / 60 * 2 * PI) * 150 * 0.66 + 250));
    time_dc.SetPen(wxPen(*wxBLACK, 2));
    time_dc.DrawLine(c, wxPoint(sin(min / 60  * 2 * PI) * 150 * 0.60 + 250, -cos(min / 60 * 2 * PI) * 150 * 0.60 + 250));
    time_dc.SetPen(wxPen(*wxBLACK, 4));
    time_dc.DrawLine(c, wxPoint(sin((hr + min / 60) / 12 * 2 * PI) * 150 * 0.48 + 250, -cos((hr + min / 60) / 12 * 2 * PI) * 150 * 0.48 + 250));
}

void TimePanel::AnalogClockUpdate(wxTimerEvent&) {
    Refresh();
}