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

## Code Structure

* **`CandlestickData`**: Holds the core candlestick fields (date, open, high, low, close) and turns the raw hourly rows into yearly summaries[cite: 98, 99].
* **`CandlestickGraph`**: Handles drawing the charts in your terminal[cite: 101]. It checks the min and max temperatures to scale everything properly and prints out the candlesticks using standard ASCII characters[cite: 101, 103].
* **`CSVReader`**: Simple parser that reads the weather data from disk and loads it into memory[cite: 97, 98].
* **`DataFiltering`**: Lets you slice the records down by choosing a specific year range or setting temperature limits[cite: 104, 106].
* **`DataPrediction`**: Looks at the year-over-year changes in highs, lows, and closing averages to forecast values for upcoming years[cite: 109, 110].
* **`main.cpp`**: The main entry point that runs the interactive console menu[cite: 105, 107].
* **`sample_weather_data.csv`**: A small cut of the full dataset so anyone cloning the repo can compile and test the app right away.