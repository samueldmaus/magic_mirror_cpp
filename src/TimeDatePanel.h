#ifndef TIME_DATE_PANEL_H
#define TIME_DATE_PANEL_H

#include <wx/wx.h>
#include <cmath>

class TimePanel : public wxPanel
{
public:
    TimePanel(wxFrame* parent, wxWindowID id, wxPoint point, wxSize size);
private:
    wxBoxSizer* panel_sizer;
    wxBoxSizer* time_sizer;
    wxBoxSizer* date_sizer;
    wxStaticText* digital_clock_display;
    wxStaticText* day_date;
    wxTimer digital_clock_timer;
    wxTimer analog_clock_timer;
    void OnUpdateClock(wxTimerEvent&);
    void UpdateClock();
    std::pair<wxDateTime, std::string> AMorPM(wxDateTime &time);
    void PaintAnalogClock(wxPaintEvent &evt);
    void AnalogClockUpdate(wxTimerEvent&);
    DECLARE_EVENT_TABLE();
};

#endif