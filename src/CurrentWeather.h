#ifndef CURRENT_WEATHER_H
#define CURRENT_WEATHER_H

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
	static utility::string_t GetEnvAPI(std::string const &key);
	int GetTemperature();
private:
	int temperature;
	utility::string_t url;
	utility::string_t zip_code;
	utility::string_t api_key;
	pplx::task<web::http::http_response> weather_response;
	web::json::value weather_data;
};

#endif