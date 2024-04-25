#ifndef READER_HPP
#define READER_HPP

#include<iostream>
#include<fstream>
#include<string>
#include"object.hpp"

string double_quote(ifstream* file, string str){
    string temp;
    getline(*file, temp, ',');
    str += temp;
    return str;
}

void load_data(Agent *data)
{
    // Define the file name
    string filename = "Secret_Agents.csv";

    string code, idStr, keyphrase, country, longStr, latStr, daysStr;

    // Open the file
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Failed to open the file." << endl;
        return;
    }

    // Removing the column headers
    getline(file, code, '\n');
    
    // Reading the data
    int i = 0;
    while(getline(file, code, ',')){
        if(code[0] == '\"'){
            code = double_quote(&file, code);
        }
        data[i].setCode(code);
        
        getline(file, idStr, ',');
        // stoi == String to Integer
        data[i].setId(stoi(idStr));

        getline(file, keyphrase, ',');
        if(keyphrase[0] == '\"'){
            keyphrase = double_quote(&file, keyphrase);
        }
        data[i].setKeyphrase(keyphrase);

        getline(file, country, ',');
        if(country[0] == '\"'){
            country = double_quote(&file, country);
        }
        data[i].setCountry(country);

        getline(file, longStr, ',');
        // stod == String to Double
        data[i].setDeadDropLong(stod(longStr));

        getline(file, latStr, ',');
        // stod == String to Double
        data[i].setDeadDropLat(stod(latStr));

        getline(file, daysStr, '\n');
        // stoi == String to Integer
        data[i].setDaysSinceLastContact(stoi(daysStr));
        
        ++i;
    }

    // Close the file
    file.close();
}
#endif