#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>

using namespace std;

// Define the structure for storing agent information
struct Agent
{
private:
    // Parameters
    string code;
    int id;
    string keyphrase;
    string country;
    float deadDropLong;
    float deadDropLat;
    int daysSinceLastContact;

public:
    // Getters and Setters
    string getCode()
    {
        return code;
    }
    void setCode(string code)
    {
        this->code = code;
    }

    int getId()
    {
        return id;
    }
    void setId(int id)
    {
        this->id = id;
    }

    string getKeyphrase()
    {
        return keyphrase;
    }
    void setKeyphrase(string keyphrase)
    {
        this->keyphrase = keyphrase;
    }

    string getCountry()
    {
        return country;
    }
    void setCountry(string country)
    {
        this->country = country;
    }

    float getDeadDropLong()
    {
        return deadDropLong;
    }
    void setDeadDropLong(float Long)
    {
        this->deadDropLong = Long;
    }

    float getDeadDropLat()
    {
        return deadDropLat;
    }
    void setDeadDropLat(float Lat)
    {
        this->deadDropLat = Lat;
    }

    int getDaysSinceLastContact()
    {
        return daysSinceLastContact;
    }
    void setDaysSinceLastContact(int days)
    {
        this->daysSinceLastContact = days;
    }

    // Constructors
    Agent()
    {
        code = "";
        id = 0;
        keyphrase = "";
        country = "";
        deadDropLong = 0.0;
        deadDropLat = 0.0;
        daysSinceLastContact = 0;
    }
    Agent(string code, int id, string keyphrase, string country, float Long, float Lat, int daysSince)
    {
        this->code = code;
        this->id = id;
        this->keyphrase = keyphrase;
        this->country = country;
        this->deadDropLong = Long;
        this->deadDropLat = Lat;
        this->daysSinceLastContact = daysSince;
    }
};

#endif
