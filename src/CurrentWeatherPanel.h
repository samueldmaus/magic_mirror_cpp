#ifndef CURRENT_WEATHER_PANEL_H
#define CURRENT_WEATHER_PANEL_H

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include <wx/wx.h>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>

class WeatherPanel : public wxPanel
{
public:
    WeatherPanel(wxFrame* parent, wxWindowID id, wxPoint point, wxSize size);
	void GetEnvAPI(std::string const &key);
	void GetTemperature();
private:
	wxString temperature;
	utility::string_t url;
	utility::string_t zip_code;
	utility::string_t api_key;
	pplx::task<web::http::http_response> weather_response;
	web::json::value weather_data;
};

#endif