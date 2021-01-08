#ifndef MIRROR_FRAME_H
#define MIRROR_FRAME_H

#include <wx/wx.h>
#include "TimeDatePanel.h"
#include "CurrentWeatherPanel.h"

class MirrorFrame : public wxFrame
{
public:
    MirrorFrame(const wxString& title);
private:
    TimePanel *time_date_panel;
    WeatherPanel *current_weather_panel;
    wxBoxSizer *vbox;
};

#endif