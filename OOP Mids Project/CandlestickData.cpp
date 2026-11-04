//
//  CandlestickData.cpp
//  OOP mids project 1
//
//  Created by MACBOOK PRO on 24/12/2024.
//

// -----------------------------------------------------------------Start CandlestickData.cpp Code---------------------------------------------------

#include "CandlestickData.h"
#include <limits>

// Constructor definition for the Candlestick class
Candlestick::Candlestick(std::string d, double o, double h, double l, double c)
    : date(d), open(o), high(h), low(l), close(c) {}

// Function to compute candlestick data
std::vector<Candlestick> computeCandlestickData(const std::vector<std::pair<std::string, double>>& temperatureData) {
    std::vector<Candlestick> candlesticks;
    double lastYearAverage = 0;

//    Initialising variables for tracking the current year, total temperature, count of temperature records, the highest temperature, and the lowest temperature.
    std::string currentYear = "";
    double totalTemp = 0;
    int count = 0;
    double high = std::numeric_limits<double>::min();
    double low = std::numeric_limits<double>::max();

//    Loop through the temperature data to process each record
    for (const auto& data : temperatureData) {
        std::string year = data.first.substr(0, 4);
        if (year != currentYear) {
//            If the particular year is not present, the candlestick will be made for the previous year
            if (!currentYear.empty()) {
                double averageTemp = totalTemp / count;
                candlesticks.push_back(Candlestick(currentYear, averageTemp, high, low, averageTemp));
            }
//            Update the tracking variables for the new year
            currentYear = year;
            totalTemp = 0;
            count = 0;
            high = std::numeric_limits<double>::min();
            low = std::numeric_limits<double>::max();
        }
//        Accumulate temperature data for current year
        totalTemp += data.second;
        count++;
        if (data.second > high) high = data.second;
        if (data.second < low) low = data.second;
    }
//     After the loop, process the last year if there are remaining records
    if (count > 0) {
        double averageTemp = totalTemp / count;
        candlesticks.push_back(Candlestick(currentYear, lastYearAverage, high, low, averageTemp));
    }

    return candlesticks;
}

// -------------------------------------------------------------End CandlestickData.cpp Code---------------------------------------------------------
