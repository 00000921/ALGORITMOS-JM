// header guards
#ifndef READER_H
#define READER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Define the structure for storing sales information
struct StockData
{
    string stock_id;
    string company_name;
    string trade_date;
    double trade_price;
    int trade_volume;
};

// Function to convert a string to an integer
int stringToInt(const string &str)
{
    return stoi(str);
}

// Function to convert a string to an double
int stringToDouble(const string &str)
{
    return stod(str);
}

void load_data(StockData *data, const int rows = 1000, const int cols = 5)
{
    // Define the file name
    string filename = "stocks.txt";

    const int numRows = rows;    // Number of rows
    const int numColumns = cols; // Number of columns

    // Open the file
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Failed to open the file." << endl;
        return;
    }

    for (int i = 0; i < numRows; i++)
    {
        string line;
        if (getline(file, line))
        {
            size_t start = 0;
            size_t end = line.find('\t');
            int j = 0; // Column index

            // Store the remaining columns in the FlightInfo structure
            while (end != (string::npos+1) && j < numColumns)
            {
                if (j == 0)
                    data[i].stock_id = line.substr(start, end - start);
                if (j == 1)
                    data[i].company_name = line.substr(start, end - start);
                if (j == 2)
                    data[i].trade_date = line.substr(start, end - start);
                if (j == 3)
                {
                    string price = line.substr(start, end - start);
                    // cout << price << endl;
                    data[i].trade_price = stod(price);
                }

                if (j == 4)
                {
                   
                    data[i].trade_volume = stringToInt(line.substr(start, end - start));
                }
                start = end + 1;
                end = line.find('\t', start);
                j++;
            }
        }
        else
        {
            cerr << "Error: Not enough lines in the file." << endl;
            break;
        }
    }

    // Close the file
    file.close();
}

#endif