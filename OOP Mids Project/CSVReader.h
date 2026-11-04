//
//  csvreader.h
//  OOP mids project 1
//
//  Created by MACBOOK PRO on 25/12/2024.
//

// -------------------------------------------------------------Start CSVReader.h Code---------------------------------------------------------------

#ifndef CSVREADER_H
#define CSVREADER_H

// including necessary data types

#include <vector>
#include <string>


// Reading and Parsing the CSV file to extract temperature data for required country
// This returns a map where the key is the year (string) and the value is the temperature (double)

std::vector<std::pair<std::string, double>> loadCSV(const std::string& filepath, const std::string& countryPrefix);

#endif

// ------------------------------------------------------------End CSVReader.cpp Code----------------------------------------------------------------
