// White belt
// Final work

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "set"
#include "iomanip"


class Date
{
private:
    int year;
    int month;
    int day;
public:
    Date()
    {
        year = 0;
        month = 1;
        day = 1;
    }
    Date(const int& y, const int& m, const int& d)
    {
        year = y;
        month = m;
        day = d;
    };
    ~Date();
    int GetYear() const
    {
        return year;
    };
    int GetMonth() const
    {
        return month;
    };
    int GetDay() const
    {
        return day;
    };
    void PrintDate() const
    {
        std::cout << setw(4) << serfill('0') << year << "-" ;
        std::cout << setw(2) << serfill('0') << month << "-" ;
        std::cout << setw(2) << serfill('0') << day  ;
    }
};

bool operator<(const Date& lhs, const Date& rhs)
{
    if (lhs.GetYear()<rhs.GetYear())
    {
        return true;
    } else if (lhs.GetMonth()<rhs.GetMonth())
    {
        return true;
    } else if (lhs.GetDay()<rhs.GetDay())
    {
        return true;
    }
    return false;
}

class Database
{
private:
    map <Date, set<string>> eve;
public:
    Database(/* args */);
    ~Database();

    void AddEvent(const Date& date, const string& event)
    {
        eve[date].insert(event);
    };
    bool DeleteEvent(const Date& date, const string& event)
    {
        if (eve.count(date))
        {
            if(eve.at(date).count(event))
            {
                eve[date].erase(event);
                return true;
            };
        };
        return false;
    };
    int  DeleteDate(const Date& date)
    {
        int size = eve[date].size();
        eve.erase(date);
        return size;
    };

  /* ??? */
    Find(const Date& date) const
    {
        if (eve.count(date))
        {
            set<string> dateevents = eve.at(date);
            for (const string& s: dateevents)
            {
                std::cout << s << std::endl;
            };
        };
    };
  
    void Print() const
    {
        for (const auto& i: eve)
        {
            i.first.PrintDate();
            for (const auto& s: i.second)
                {
                    std::cout << s << " " << std::endl;
                };
            };
            std::cout << std::endl;
        }
    };

};



int main(int argc, char const *argv[])
{
    Database db;
    
  string command;
  while (getline(cin, command)) {
    
  }
    return 0;
}

