//  CandlestickGraph.cpp
//  OOP mids project 1
//
//  Created by MACBOOK PRO on 24/12/2024.
//


// -------------------------------------------------------------Start CandlestickGraph.cpp Code------------------------------------------------------

// Including the necessary files
#include "CandlestickGraph.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>

// Constructor for CandlestickGraph
CandlestickGraph::CandlestickGraph(int h) : height(h) {}

// Finds the maximum and minimum temperatures for scaling the graph
void CandlestickGraph::findMaxMinTemp() {
    maxTemp = candles[0].high;
    minTemp = candles[0].low;

    for (const auto& candle : candles) {
        if (candle.high > maxTemp) maxTemp = candle.high;
        if (candle.low < minTemp) minTemp = candle.low;
    }
}

// Adds new candlesticks to the graph
void CandlestickGraph::addCandlesticks(const std::vector<Candlestick>& newCandles) {
    candles.insert(candles.end(), newCandles.begin(), newCandles.end());
}

// Draws the candlestick graph
void CandlestickGraph::draw() {
    findMaxMinTemp();

    // Loop through all candlesticks and draw the graph
    for (const auto& candle : candles) {
        std::cout << "Year: " << candle.date.substr(0, 4) << std::endl;
        std::cout << "High: " << candle.high << std::endl;
        std::cout << "Low:  " << candle.low << std::endl;
        std::cout << "Open: " << candle.open << " Close: " << candle.close << std::endl;

        double range = maxTemp - minTemp;
        int highPosition = static_cast<int>((candle.high - minTemp) / range * height);
        int lowPosition = static_cast<int>((candle.low - minTemp) / range * height);
        int openPosition = static_cast<int>((candle.open - minTemp) / range * height);
        int closePosition = static_cast<int>((candle.close - minTemp) / range * height);

        for (int row = height; row >= 0; --row) {
            if (row == highPosition) {
                std::cout << "  H";
            } else if (row == lowPosition) {
                std::cout << "  L";
            } else if ((row == openPosition || row == closePosition)) {
                char label = (row == openPosition) ? 'O' : 'C';
                char body = (candle.close > candle.open) ? '#' : '-';
                std::cout << "  " << label;

                if (openPosition != closePosition && row < openPosition && row > closePosition) {
                    std::cout << "  " << body;
                }
            } else if (row < highPosition && row > lowPosition) {
                std::cout << "  |";
            } else {
                std::cout << "   ";
            }
            std::cout << std::endl;
        }
        std::cout << "----------------------" << std::endl;
    }
}

// Prints OHLC (Open, High, Low, Close) data for each candlestick
void CandlestickGraph::printOHLCData() {
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(10) << "Year"
              << std::setw(10) << "Open"
              << std::setw(10) << "High"
              << std::setw(10) << "Low"
              << std::setw(10) << "Close" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;

    for (const auto& candle : candles) {
        std::cout << std::left << std::setw(10) << candle.date.substr(0, 4)
                  << std::setw(10) << std::fixed << std::setprecision(1) << candle.open
                  << std::setw(10) << candle.high
                  << std::setw(10) << candle.low
                  << std::setw(10) << candle.close << std::endl;
    }
    std::cout << "----------------------------------------------" << std::endl;
}

// Text-based candlestick plot (Horizontal visualization)
void CandlestickGraph::drawCandlestickTextPlot() {
    findMaxMinTemp();

    std::cout << "\nText-based Candlestick Plot:\n";
    std::cout << "--------------------------------------------------\n";

    double range = maxTemp - minTemp;

    // Create rows for each position in the graph (from top to bottom)
    for (int row = height; row >= 0; --row) {
        for (const auto& candle : candles) {
            int highPosition = static_cast<int>((candle.high - minTemp) / range * height);
            int lowPosition = static_cast<int>((candle.low - minTemp) / range * height);
            int openPosition = static_cast<int>((candle.open - minTemp) / range * height);
            int closePosition = static_cast<int>((candle.close - minTemp) / range * height);

            // Draw the High position
            if (row == highPosition) {
                std::cout << "    H   ";
            }
            // Draw the Low position
            else if (row == lowPosition) {
                std::cout << "    L   ";
            }
            // Draw the Open and Close positions
            else if (row == openPosition && row == closePosition) {
                // "S" for Same Open and Close
                std::cout << "    S   ";
            }
            else if (row == openPosition) {
                std::cout << "    O   ";
            }
            else if (row == closePosition) {
                std::cout << "    C   ";
            }
            // Draw the vertical candlestick body (line between High and Low)
            else if (row < highPosition && row > lowPosition) {
                // Vertical line between High and Low
                std::cout << "    |   ";
            }
            // Draw the body of the candlestick (open and close range)
            else if (row < openPosition && row > closePosition) {
                // Body representation
                char body = (candle.close > candle.open) ? '#' : '-';
                std::cout << "    " << body;
            }
            else {
                // Empty space
                std::cout << "        ";
            }
        }
        std::cout << std::endl;
    }

    // Display years below the plot in a horizontal line
    for (const auto& candle : candles) {
        std::cout << "  " << candle.date.substr(0, 4) << "  ";
    }
    std::cout << std::endl;
}

// Filters and draws graph for specific time periods
void CandlestickGraph::drawFilteredByYearRange(const std::string& startYear, const std::string& endYear) {
    std::vector<Candlestick> filteredCandles;
    for (const auto& candle : candles) {
        if (candle.date >= startYear && candle.date <= endYear) {
            filteredCandles.push_back(candle);
        }
    }
    if (filteredCandles.empty()) {
        std::cout << "\nNo data available for the selected range.\n";
    } else {
        CandlestickGraph filteredGraph(height);
        filteredGraph.addCandlesticks(filteredCandles);
        filteredGraph.drawCandlestickTextPlot();
    }
}

// Menu for selecting predefined date ranges (1980–2000 or 2001–2019)
void CandlestickGraph::drawGraphByPredefinedRange() {
    int choice;
    std::cout << "\nSelect a time range:\n";
    std::cout << "1. 1980-2000\n";
    std::cout << "2. 2001-2019\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (choice == 1) {
        drawFilteredByYearRange("1980", "2000");
    } else if (choice == 2) {
        drawFilteredByYearRange("2001", "2019");
    } else {
        std::cerr << "Invalid choice.\n";
    }
}


// -------------------------------------------------------------End CandlestickGraph.cpp Code-------------------------------------------------------
