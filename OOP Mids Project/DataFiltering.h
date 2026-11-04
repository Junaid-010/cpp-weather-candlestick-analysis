//
//  DataFiltering.h
//  OOP mids project 1
//
//  Created by MACBOOK PRO on 26/12/2024.
//

// -------------------------------------------------------Start DataFiltering.h Code-----------------------------------------------------------------

// Including the necessary files and Data types
#pragma once
#include "CandlestickData.h"
#include <vector>
#include <string>

// Filters candlesticks by date range
std::vector<Candlestick> filterByDateRange(const std::vector<Candlestick>& candlesticks, const std::string& startYear, const std::string& endYear);

// Filters candlesticks by temperature range
std::vector<Candlestick> filterByTemperatureRange(const std::vector<Candlestick>& candlesticks, double minTemp, double maxTemp);

// -------------------------------------------------------End DataFiltering.h Code-------------------------------------------------------------------
