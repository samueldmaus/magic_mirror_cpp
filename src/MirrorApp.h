#ifndef MIRROR_APP_H
#define MIRROR_APP_H

#include <wx/wx.h>

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
private:
    wxLocale locale;
};

#endif