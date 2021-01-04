#ifndef TIME_DATE_H
#define TIME_DATE_H

#include <wx/wx.h>


class TimePanel : public wxPanel
{
public:
    TimePanel(wxFrame* parent, wxWindowID id, wxPoint point, wxSize size);
private:
    wxStaticText* digital_clock_display;
    wxTimer digital_clock_timer;
    void OnUpdateClock(wxTimerEvent&);
    void UpdateClock();
    void PaintAnalogClock(wxPanel *panel);
};

#endif