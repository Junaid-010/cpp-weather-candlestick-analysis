//
//  CandlestickData.h
//  OOP mids project 1
//
//  Created by MACBOOK PRO on 24/12/2024.
//

// ---------------------------------------------------------Start CandlestickData.h Code-------------------------------------------------------------

// Including the necessary data types and class
#ifndef CANDLESTICKDATA_H
#define CANDLESTICKDATA_H

#include <vector>
#include <string>

// Candlestick class data represents data for specific period
class Candlestick {
public:
    std::string date;
    double open;
    double high;
    double low;
    double close;
    double temperature() const;


    Candlestick(std::string d, double o, double h, double l, double c);
};

// Function to compute candlestick data from temperature data
std::vector<Candlestick> computeCandlestickData(const std::vector<std::pair<std::string, double>>& temperatureData);

#endif

// -----------------------------------------------------End CandlestickData.h Code------------------------------------------------------------------
