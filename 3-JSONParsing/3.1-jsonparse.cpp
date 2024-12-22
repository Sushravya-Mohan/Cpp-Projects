#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

// For convenience
using json = nlohmann::json;
using namespace std;

// Callback function for cURL to store the response
size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* userData) {
    size_t totalSize = size * nmemb;
    userData->append((char*)contents, totalSize);
    return totalSize;
}

int main() {
    // URL of the API
    string url = "https://api.open-meteo.com/v1/forecast?latitude=40.7128&longitude=-74.0060&current_weather=true";

    // Initialize cURL
    CURL* curl;
    CURLcode res;
    string response;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Perform the request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            cerr << "cURL error: " << curl_easy_strerror(res) << endl;
        }

        // Cleanup
        curl_easy_cleanup(curl);
    }

    // Parse JSON response
    try {
        auto jsonResponse = json::parse(response);
        
        // Extract and print weather data
        if (jsonResponse.contains("current_weather")) {
            auto weather = jsonResponse["current_weather"];
            cout << "Temperature: " << weather["temperature"] << " °C" << endl;
            cout << "Wind Speed: " << weather["windspeed"] << " km/h" << endl;
            cout << "Weather Code: " << weather["weathercode"] << endl;
        } else {
            cout << "No weather data available!" << endl;
        }
    } catch (json::parse_error& e) {
        cerr << "JSON Parsing Error: " << e.what() << endl;
    }

    return 0;
}
