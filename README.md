# C++ Meteorological Candlestick Analysis & Trend Forecaster

A technical analysis and time-series modeling tool written in C++ using Object-Oriented Programming (OOP) principles[cite: 97]. The application processes multi-decade hourly meteorological temperature records, aggregates them into yearly Open-High-Low-Close (OHLC) candlestick vectors, and renders interactive ASCII-based terminal visualizations with multi-criteria filtering and forward forecasting[cite: 97, 98, 100, 101, 106, 109].

---

## Technical Highlights

- Object-Oriented Architecture: Encapsulates annual temperature distributions within an explicit `Candlestick` class (`open`, `high`, `low`, `close`, `date`)[cite: 98]. Uses modular C++ header/source separations across CSV ingestion, filtering, graph generation, and forecasting pipelines[cite: 102, 106, 109, 166].
- OHLC Metric Aggregation: Parses continuous hourly data streams into annual meteorological metrics[cite: 98]:
  - `Open`: Mean temperature benchmark derived from preceding meteorological observations[cite: 98].
  - `Close`: Mean annual temperature of the current operational period[cite: 98].
  - `High` / `Low`: Absolute historical temperature bounds experienced during the recording window[cite: 98].
- Terminal-Based ASCII Rendering Engine: Dynamically calculates temperature extremes (`findMaxMinTemp`) to scale variable data ranges onto a console grid[cite: 101, 102, 103]. Renders candlestick bodies using custom ASCII delimiters with directional markers (`H`, `L`, `O`, `C`)[cite: 101].
- Multi-Criteria Data Filtering: Supports dynamic subset analysis across custom chronological spans (e.g., 1980–2000, 2001–2019) or thermal boundary thresholds[cite: 104, 105, 106].
- Trend Forecasting Algorithm: Analyzes multi-year rate-of-change deltas across high, low, and close values to extrapolate future candlestick bounds over user-specified forecast horizons[cite: 109].

---

## Project Structure

```text
├── CandlestickData.h / .cpp    # Candlestick entity class & aggregation logic[cite: 98, 166]
├── CandlestickGraph.h / .cpp   # Terminal ASCII graph rendering & scaling engine[cite: 102, 103, 166]
├── CSVReader.h / .cpp          # Fast CSV parsing & tokenization
├── DataFiltering.h / .cpp      # Date & temperature boundary filter routines[cite: 106, 166]
├── DataPrediction.h / .cpp     # Multi-year delta trend extrapolation[cite: 109, 166]
├── main.cpp                    # Interactive terminal menu loop[cite: 166]
└── weather_data.csv            # Historical hourly meteorological dataset[cite: 167]