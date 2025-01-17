#pragma once
#include <httplib.h>
#include <string>

class WeatherController
{
public:
	httplib::Result	GetWeatherFromCoords(double lon, double lat);
	httplib::Result	GetWeatherFromCoords2(double lon, double lat);
	httplib::Result GetFiveDaysForeCast(double lon, double lat);
	static std::string m_api_key;
private:
	std::string m_endpoint = "/data/2.5/weather";
	httplib::Result MakeRequest(double lon, double lat, std::string endPoint);
    // API endpoint and query parameters
	std::string m_base_url = "api.openweathermap.org/data/";
	std::string m_APIversion = "2.5";
	httplib::Client m_client = httplib::Client(m_base_url);
};

