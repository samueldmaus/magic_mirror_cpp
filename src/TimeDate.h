#ifndef TIME_DATE_H
#define TIME_DATE_H

#include <wx/wx.h>
#include <wx/dcbuffer.h>

class MirrorFrame : public wxFrame
{
public:
    MirrorFrame(const wxString& title);
    wxString time;
};

#endif