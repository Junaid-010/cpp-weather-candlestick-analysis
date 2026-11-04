//
//  csvreader.cpp
//  OOP mids project 1
//
//  Created by MACBOOK PRO on 25/12/2024.
//

// ----------------------------------------------------------Start CSVReader.cpp Code----------------------------------------------------------------

//  Importing necessary files
#include "CSVReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

//   This function reads and parses a CSV file to extract temperature data for a given country code
std::vector<std::pair<std::string, double>> loadCSV(const std::string& filepath, const std::string& countryPrefix) {
    std::vector<std::pair<std::string, double>> data;
    std::ifstream file(filepath);
    std::string line;
    int tempIndex = -1;

    if (file.is_open()) {
//     Reading the header line and determining the index of country's temperature
        getline(file, line);
        std::stringstream ss(line);
        std::string header;
        int currentIndex = 0;
        while (getline(ss, header, ',')) {
            if (header == countryPrefix + "_temperature") {
                tempIndex = currentIndex;
                break;
            }
            currentIndex++;
        }

//      Reading each coming line
        while (getline(file, line)) {
            std::stringstream linestream(line);
            std::string segment;
            std::vector<std::string> seglist;

            while (getline(linestream, segment, ',')) {
                seglist.push_back(segment);
            }

            if (tempIndex != -1 && tempIndex < seglist.size()) {
                std::string date = seglist[0].substr(0, 10);
                double temperature = std::stod(seglist[tempIndex]);
                data.push_back({ date, temperature });
            }
        }
        file.close();
//        Displaying error in case of file is not accessable
    } else {
        std::cerr << "Failed to open file" << std::endl;
    }
    return data;
}

// ----------------------------------------------------------End CSVReader.cpp Code------------------------------------------------------------------
