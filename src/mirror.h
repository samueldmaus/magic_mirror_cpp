#ifndef MIRROR_H
#define MIRROR_H

#include <wx/wx.h>

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
private:
    wxLocale locale;
};

#endif