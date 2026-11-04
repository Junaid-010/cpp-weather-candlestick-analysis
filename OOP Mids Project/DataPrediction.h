//
//  DataPrediction.h
//  OOP mids project 1
//
//  Created by MACBOOK PRO on 26/12/2024.
//


// --------------------------------------------------------------Start DataPrediction.h Code-------------------------------------------------------

// Including the necessary files and data types
#pragma once
#include "CandlestickData.h"
#include <vector>

// Predicts future candlestick data
std::vector<Candlestick> predictCandlestickData(const std::vector<Candlestick>& existingData, int yearsToPredict);


// --------------------------------------------------------------End DataPrediction.h Code----------------------------------------------------------
