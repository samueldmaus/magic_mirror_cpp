#ifndef MIRROR_FRAME_H
#define MIRROR_FRAME_H

#include <wx/wx.h>
#include "TimeDate.h"

class MirrorFrame : public wxFrame
{
public:
    MirrorFrame(const wxString& title);
private:
    TimePanel *time_date_panel;
};

#endif