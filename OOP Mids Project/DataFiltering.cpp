//
//  DataFiltering.cpp
//  OOP mids project 1
//
//  Created by MACBOOK PRO on 26/12/2024.
//

// --------------------------------------------------------------Start DataFiltering.cpp Code-------------------------------------------------------

// Including the necessary files and data types
#include "DataFiltering.h"
#include <algorithm>
#include <vector>

// Filters candlesticks by date range
std::vector<Candlestick> filterByDateRange(const std::vector<Candlestick>& candlesticks, const std::string& startYear, const std::string& endYear) {
    std::vector<Candlestick> filtered;
    for (const auto& candle : candlesticks) {
        if (candle.date >= startYear && candle.date <= endYear) {
            filtered.push_back(candle);
        }
    }
    return filtered;
}

// Filters candlesticks by temperature range
std::vector<Candlestick> filterByTemperatureRange(const std::vector<Candlestick>& candlesticks, double minTemp, double maxTemp) {
    std::vector<Candlestick> filtered;
    for (const auto& candle : candlesticks) {
        // Check if any of the values (high, low) fall within the temperature range
        if ((candle.high >= minTemp && candle.high <= maxTemp) ||
            (candle.low >= minTemp && candle.low <= maxTemp) ||
            (candle.open >= minTemp && candle.open <= maxTemp) ||
            (candle.close >= minTemp && candle.close <= maxTemp)) {
            filtered.push_back(candle);
        }
    }
    return filtered;
}

// ------------------------------------------------------------End DataFiltering.cpp Code-----------------------------------------------------------
