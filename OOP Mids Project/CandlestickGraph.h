//
//  CandlestickGraph.h
//  OOP mids project 1
//
//  Created by MACBOOK PRO on 24/12/2024.
//

// -----------------------------------------------------------------Start CandlestickGraph.h Code----------------------------------------------------

// Importing the necessary files and Data types
#pragma once
#include "CandlestickData.h"
#include <string>
#include <vector>

// ANSI escape codes for colored output
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string RESET = "\033[0m";

// Class for handling Candlestick graphs
class CandlestickGraph {
private:
    std::vector<Candlestick> candles;
    int height;
    double maxTemp, minTemp;

    // Finds the maximum and minimum temperatures for scaling the graph
    void findMaxMinTemp();

public:
    // Constructor
    explicit CandlestickGraph(int h);

    // Adds new candlesticks to the graph
    void addCandlesticks(const std::vector<Candlestick>& newCandles);

    // Draws the candlestick graph
    void draw();

    // Prints OHLC (Open, High, Low, Close) data for each candlestick
    void printOHLCData();

    // Filters and draws graph for specific time periods
    void drawFilteredByYearRange(const std::string& startYear, const std::string& endYear);

    // Menu for selecting predefined date ranges (1980–2000 or 2001–2019)
    void drawGraphByPredefinedRange();

    // Draws a text-based candlestick plot
    void drawCandlestickTextPlot();
};

// -----------------------------------------------------------------End CandlestickGraph.h Code------------------------------------------------------
