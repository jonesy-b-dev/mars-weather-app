#include "WeatherController.h"
#include <iostream>
#include <string>

std::string WeatherController::m_api_key  = "NoApiKeySet"; 

httplib::Result WeatherController::GetWeatherFromCoords(double lon, double lat)
{
	// Construct the query
    std::string query = m_endpoint + "?lat=" +  std::to_string(lat) + "&lon=" + std::to_string(lon) + "&appid=" + WeatherController::m_api_key;

	// Make the request to the weather API
	httplib::Result response = m_client.Get(query.c_str());

    // Check if the request was successful
    if (response && response->status == 200) 
    {
        // Print the response body (weather data in JSON format)
        std::cout << "Response: " << response->body << std::endl;
    } 
    else 
    {
        std::cerr << "Error: Could not fetch data. HTTP Status: " << response->status << std::endl;
    }

	return response;
}
