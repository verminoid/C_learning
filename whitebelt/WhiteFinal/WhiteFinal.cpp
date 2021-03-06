// White belt
// Final work

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <sstream>
#include <exception>

using namespace std;

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
    };
    Date(const int &y, const int &m, const int &d)
    {
        year = y;
        month = m;
        day = d;
    };
    
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
        std::cout << setw(4) << setfill('0') << year << "-";
        std::cout << setw(2) << setfill('0') << month << "-";
        std::cout << setw(2) << setfill('0') << day;
    }
};

bool operator<(const Date &lhs, const Date &rhs)
{
    if (lhs.GetYear() < rhs.GetYear())
    {
        return true;
    }
    else if (lhs.GetMonth() < rhs.GetMonth())
    {
        return true;
    }
    else if (lhs.GetDay() < rhs.GetDay())
    {
        return true;
    }
    return false;
}

class Database
{
private:
    map<Date, set<string>> eve;

public:
   

    void AddEvent(const Date &date, const string &event)
    {
        eve[date].insert(event);
    };
    bool DeleteEvent(const Date &date, const string &event)
    {
        if (eve.count(date))
        {
            if (eve.at(date).count(event))
            {
                eve[date].erase(event);
                return true;
            };
        };
        return false;
    };
    int DeleteDate(const Date &date)
    {
        int size = eve[date].size();
        eve.erase(date);
        return size;
    };

    /* ??? */
    void Find(const Date &date) const
    {
        if (eve.count(date))
        {
            set<string> dateevents = eve.at(date);
            for (const string &s : dateevents)
            {
                std::cout << s << std::endl;
            };
        };
    };

    void Print() const
    {
        for (const auto &i : eve)
        {
            i.first.PrintDate();
            for (const auto &s : i.second)
            {
                std::cout << s << " " << std::endl;
            };

            std::cout << std::endl;
        }
    };
};

int StringToValueDate (stringstream& stream, const string& str)
{
    if (stream.peek() == '-')
        {   
            int value;
            stream.ignore(1);
            stream >> value;
            return value;
        }
    else
    {
        stringstream errmsg;
        errmsg << "Wrong date format: " << str;
        throw runtime_error(errmsg.str());
    }
    
}

Date StringToDate(const string &ds)
{
    if (ds.empty())
    {
        stringstream errmsg;
        errmsg << "Wrong date format: " << ds;
        throw runtime_error(errmsg.str());
    }
    else
    {
        stringstream ss(ds);
        int year, month, day;
        ss >> year;
        month = StringToValueDate(ss, ds);
        day = StringToValueDate(ss,ds);
        if (month < 1 || month > 12)
        {
            stringstream errmsg;
            errmsg << "Month value is invalid: " << month;
            throw runtime_error(errmsg.str());
        }
        if (day < 1 || day > 31)
        {
            stringstream errmsg;
            errmsg << "Day value is invalid: " << day;
            throw runtime_error(errmsg.str());
        }
        Date date{year,month,day};
        return date;
        
    };
}

int main(int argc, char const *argv[])
{
    try
    {
        Database db;
        
        string command;
        while (getline(cin, command))
        {
            if (!(command.empty()))
            {
                string request;
                stringstream stream(command);
                stream >> request;
                if (request == "Print")
                {
                    db.Print();
                }
                else if (request == "Add" || request == "Del" || request == "Find")
                {
                    Date date;
                    string event;
                    string datastring;
                    stream >> datastring;
                    date = StringToDate(datastring);
                    if (request == "Add")
                    {
                        stream >> event;
                        db.AddEvent(date, event);
                    }
                    if (request == "Del")
                    {
                        stream >> event;
                        if (event.empty())
                        {
                            int count;
                            count = db.DeleteDate(date);
                            std::cout << "Deleted " << count << " events." << std::endl;
                        } else
                        {
                            if (db.DeleteEvent(date, event))
                            {
                                std::cout << "Deleted successfully" << std::endl;
                            } else
                            {
                                std::cout << "Event not found" << std::endl;
                            }
                        }
                    }
                    if (request == "Find")
                    {
                        db.Find(date);

                    }
                    
                    
                }
                else
                {
                    stringstream errmsg;
                    errmsg << "Unknown command: " << request;
                    throw runtime_error(errmsg.str());
                }
            }
            
        }

        
    }
    catch (exception &e)
            {
                cout << e.what() << '\n';
            }

    return 0;
}
