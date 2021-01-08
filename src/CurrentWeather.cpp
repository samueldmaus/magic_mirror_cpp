#include "CurrentWeather.h"

utility::string_t CurrentWeather::GetEnvAPI(std::string const &key) {
    utility::string_t val = getenv(key.c_str());
    return val;
}

int CurrentWeather::GetTemperature() {
    utility::string_t url = "http://api.openweathermap.org/data/2.5/weather?zip=";
	utility::string_t zip = "55057";
	utility::string_t key = CurrentWeather::GetEnvAPI("OPEN_WEATHER_API");
    url += zip + key;
    web::http::client::http_client weather_client(url);
    pplx::task<web::http::http_response> response = weather_client.request(web::http::methods::GET);
    web::http::http_response data = response.get();
    pplx::task<web::json::value> weather_json = data.extract_json();
    weather_data = weather_json.get();

}