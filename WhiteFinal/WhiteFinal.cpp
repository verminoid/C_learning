// White belt
// Final work

#include <iostream>
#include <string>


class Date
{
private:
    int year;
    int month;
    int day;
public:
    Date(/* args */);
    ~Date();
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
};

class Database
{
private:
    Date date_of_event;
    string event;
public:
    Database(/* args */);
    ~Database();

    void AddEvent(const Date& date, const string& event);
    bool DeleteEvent(const Date& date, const string& event);
    int  DeleteDate(const Date& date);

  /* ??? */
    Find(const Date& date) const;
  
    void Print() const;
};



int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

