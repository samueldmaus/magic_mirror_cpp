#include "TimeDate.h"

MirrorFrame::MirrorFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxPoint(-1, -1))
{

    wxDateTime time_now = wxDateTime::Now();
    int h = time_now.GetHour();
    int m = time_now.GetMinute();
    int s = time_now.GetSecond();
    time.Printf("%i:%i:%i", h, m, s);

}