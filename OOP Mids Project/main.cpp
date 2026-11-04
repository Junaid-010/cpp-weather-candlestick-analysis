// main.cpp
// OOP mids project 1
//
// Created by MACBOOK PRO on 20/12/2024.

#include <iostream>
#include <fstream> // For file existence check
#include "CSVReader.h"
#include "CandlestickData.h"
#include "CandlestickGraph.h"
#include "DataFiltering.h"
#include "DataPrediction.h"
#include <cctype>
#include <stdexcept>

// Function to check if a string is in uppercase
bool isUpperCase(const std::string& str) {
    for (char c : str) {
        if (!std::isupper(c)) {
            return false;
        }
    }
    return true;
}

// Function to check if the file exists
bool fileExists(const std::string& filepath) {
    std::ifstream file(filepath);
    return file.good();
}

int main() {
    // File path of the dataset
    std::string filepath = "weather_data.csv";
    std::string countryCode;

    // Check if the file exists before proceeding
    if (!fileExists(filepath)) {
        std::cerr << "Error: File '" << filepath << "' not found. Ensure the file is in the correct directory.\n";
        return 1;
    }

    // Loop to validate user input for the country code
    while (true) {
        std::cout << "Enter the country code (e.g., IT for Italy): ";
        std::cin >> countryCode;

        if (!isUpperCase(countryCode)) {
            std::cerr << "Error: Enter country code in uppercase letters.\n";
            continue;
        }

        break;
    }

    // Load the CSV data based on the provided country code
    auto temperatureData = loadCSV(filepath, countryCode);
    if (temperatureData.empty()) {
        std::cerr << "No data found for country code '" << countryCode << "'. Please check the input or the CSV file.\n";
        return 1;
    }

    // Compute candlestick data from temperature data
    auto candlesticks = computeCandlestickData(temperatureData);

    // Initialize the candlestick graph for visualization
    CandlestickGraph graph(10);
    graph.addCandlesticks(candlesticks);

    // Display the main menu
    int choice;
    do {
        std::cout << "\nChoose an option:\n";
        std::cout << "1. Display candlestick graph\n";
        std::cout << "2. Display graph by predefined ranges (1980–2000 or 2001–2019)\n";
        std::cout << "3. Filter by date range\n";
        std::cout << "4. Filter by temperature range\n";
        std::cout << "5. Predict future candlesticks\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                graph.draw();
                graph.printOHLCData();
                break;

            case 2:
                graph.drawGraphByPredefinedRange();
                break;

            case 3: {
                std::string startYear, endYear;
                std::cout << "Enter start year: ";
                std::cin >> startYear;
                std::cout << "Enter end year: ";
                std::cin >> endYear;

                auto filteredCandles = filterByDateRange(candlesticks, startYear, endYear);
                if (filteredCandles.empty()) {
                    std::cerr << "No data found for the specified date range.\n";
                    break;
                }

                CandlestickGraph filteredGraph(10);
                filteredGraph.addCandlesticks(filteredCandles);
                filteredGraph.draw();
                break;
            }

            case 4: {
                double minTemp, maxTemp;
                std::cout << "Enter minimum temperature: ";
                std::cin >> minTemp;
                std::cout << "Enter maximum temperature: ";
                std::cin >> maxTemp;

                auto filteredCandles = filterByTemperatureRange(candlesticks, minTemp, maxTemp);
                if (filteredCandles.empty()) {
                    std::cerr << "No data found for the specified temperature range.\n";
                    break;
                }

                CandlestickGraph filteredGraph(10);
                filteredGraph.addCandlesticks(filteredCandles);
                filteredGraph.draw();
                break;
            }

            case 5: {
                int yearsToPredict;
                std::cout << "Enter number of years to predict: ";
                std::cin >> yearsToPredict;

                try {
                    auto predictions = predictCandlestickData(candlesticks, yearsToPredict);
                    if (predictions.empty()) {
                        std::cerr << "Prediction failed or returned no data.\n";
                        break;
                    }

                    CandlestickGraph predictionGraph(10);
                    predictionGraph.addCandlesticks(predictions);
                    std::cout << "\nPredicted Data:\n";
                    predictionGraph.draw();
                    predictionGraph.printOHLCData();
                } catch (const std::exception& e) {
                    std::cerr << "Error: " << e.what() << '\n';
                }
                break;
            }

            case 6:
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cerr << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
