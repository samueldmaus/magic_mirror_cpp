#ifndef MIRROR_H
#define MIRROR_H

#include <wx/wx.h>

class MirrorFrame : public wxFrame
{
public:
    MirrorFrame(const wxString& title);
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

#endif