#include "WeatherController.h"
#include <iostream>
#include <string>

WeatherController::WeatherController()
{
	std::cout << "Enter your API key: ";
	std::cin >> m_api_key;
}

httplib::Result WeatherController::GetWeatherFromCoords(double lon, double lat)
{
	// Construct the query
    std::string query = m_endpoint + "?lat=" +  std::to_string(lat) + "&lon=" + std::to_string(lon) + "&appid=" + m_api_key;

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
