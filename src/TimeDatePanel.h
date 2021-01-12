#ifndef TIME_DATE_PANEL_H
#define TIME_DATE_PANEL_H

#include <wx/wx.h>
#include <cmath>

class TimePanel : public wxPanel
{
public:
    TimePanel(wxFrame* parent, wxWindowID id, wxPoint point, wxSize size);
private:
    wxBoxSizer* time_sizer;
    wxStaticText* digital_clock_display;
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