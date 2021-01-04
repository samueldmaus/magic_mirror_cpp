#ifndef TIME_DATE_H
#define TIME_DATE_H

#include <wx/wx.h>


class TimePanel : public wxPanel
{
public:
    TimePanel(wxFrame* parent);
private:
    wxStaticText* d_clock_display;
    wxTimer clock_timer;
    void OnUpdateClock(wxTimerEvent&);
    void UpdateClock();
};

#endif