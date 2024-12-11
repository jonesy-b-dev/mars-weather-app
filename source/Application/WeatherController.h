#pragma once
#include <httplib.h>
#include <string>

class WeatherController
{
public:
	WeatherController();
	httplib::Result	GetWeatherFromCoords(double lon, double lat);
private:
    // API endpoint and query parameters
	std::string m_base_url = "api.openweathermap.org";
	std::string m_endpoint = "/data/2.5/weather";
	std::string m_api_key = "NoApiKeySet";
	httplib::Client m_client = httplib::Client(m_base_url);
};

