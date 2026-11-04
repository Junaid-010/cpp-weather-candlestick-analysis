//
//  DataPredition.cpp
//  OOP mids project 1
//
//  Created by MACBOOK PRO on 26/12/2024.
//

// ---------------------------------------------------------------Start DataPrediction.cpp Code-----------------------------------------------------

// Including the necessary files
#include "DataPrediction.h"
#include <numeric>
#include <stdexcept>

// Predicts future candlestick data
std::vector<Candlestick> predictCandlestickData(const std::vector<Candlestick>& existingData, int yearsToPredict) {
    if (existingData.empty()) {
        throw std::invalid_argument("Existing data cannot be empty for prediction.");
    }

    std::vector<Candlestick> predictions;

    // Calculating average yearly change for high, low, and close
    double avgHighChange = 0.0;
    double avgLowChange = 0.0;
    double avgCloseChange = 0.0;

    for (size_t i = 1; i < existingData.size(); ++i) {
        avgHighChange += (existingData[i].high - existingData[i - 1].high);
        avgLowChange += (existingData[i].low - existingData[i - 1].low);
        avgCloseChange += (existingData[i].close - existingData[i - 1].close);
    }

    avgHighChange /= (existingData.size() - 1);
    avgLowChange /= (existingData.size() - 1);
    avgCloseChange /= (existingData.size() - 1);

    // Use the last candlestick as the base for predictions
    Candlestick lastCandle = existingData.back();

    for (int i = 1; i <= yearsToPredict; ++i) {
        std::string predictedYear = std::to_string(std::stoi(lastCandle.date.substr(0, 4)) + i);

        double predictedHigh = lastCandle.high + avgHighChange;
        double predictedLow = lastCandle.low + avgLowChange;
        double predictedClose = lastCandle.close + avgCloseChange;
        // Open for the new year is last year's close
        double predictedOpen = lastCandle.close;

        predictions.emplace_back(predictedYear, predictedOpen, predictedHigh, predictedLow, predictedClose);

        // Update the lastCandle for the next prediction
        lastCandle = predictions.back();
    }

    return predictions;
}

// ---------------------------------------------------------------End DataPrediction.cpp Code--------------------------------------------------------
