#include "WeatherController.h"
#include <iostream>

WeatherController::WeatherController()
{
	std::cout << "Enter your API key: ";
	std::cin >> m_api_key;
}

httplib::Result WeatherController::GetWeatherFromCoords(double lon, double lat)
{
	return httplib::Result();
}
