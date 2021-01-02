#ifndef TIME_DATE_H
#define TIME_DATE_H

#include <wx/wx.h>


class MirrorFrame : public wxFrame
{
public:
    MirrorFrame(const wxString& title);
private:
    wxStaticText* d_clock_display;
    wxTimer clock_timer;
    void OnUpdateClock(wxTimerEvent&);
    void UpdateClock();
};

#endif