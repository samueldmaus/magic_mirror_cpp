#include "CurrentWeatherPanel.h"

WeatherPanel::WeatherPanel(wxFrame* parent, wxWindowID id, wxPoint point, wxSize size)
       : wxPanel(parent, id, point, size)
{
    WeatherPanel::GetEnvAPI("OPEN_WEATHER_API");
    WeatherPanel::GetTemperature();
    wxStaticText *local_temp = new wxStaticText(this, wxID_ANY, WeatherPanel::temperature);
}

void WeatherPanel::GetEnvAPI(std::string const &key) {
    char *val = getenv(key.c_str());
    std::string str_val(val);
    WeatherPanel::api_key = str_val;
}

void WeatherPanel::GetTemperature() {
    WeatherPanel::url = "http://api.openweathermap.org/data/2.5/weather?zip=";
	WeatherPanel::zip_code = "55057&appid=";
    WeatherPanel::url += WeatherPanel::zip_code + WeatherPanel::api_key;
    web::http::client::http_client weather_client(WeatherPanel::url);
    pplx::task<web::http::http_response> response = weather_client.request(web::http::methods::GET);
    web::http::http_response data = response.get();
    pplx::task<web::json::value> weather_json = data.extract_json();
    weather_data = weather_json.get();
    int temp = weather_data.at(U("main")).at(U("temp")).as_integer();
    int fahrenheit_temp = ((9.00 / 5.00) * (temp - 273.00)) + 32.00;
    WeatherPanel::temperature = wxString::Format(wxT("Current Temperature: %i\xB0 F"),fahrenheit_temp);
}