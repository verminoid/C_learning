/******************************************
**
**      File: Decomp.cpp
**      Project: Learning
**      Created By VERMIN
**      Date: 28/09/2020
**      Description: 
Условие задачи «Автобусные остановки — 1»
Реализуйте систему хранения автобусных маршрутов. Вам нужно обрабатывать следующие запросы:

NEW_BUS bus stop_count stop1 stop2 ... — добавить маршрут автобуса с названием bus и stop_count остановками с названиями stop1, stop2, ...
BUSES_FOR_STOP stop — вывести названия всех маршрутов автобуса, проходящих через остановку stop.
STOPS_FOR_BUS bus — вывести названия всех остановок маршрута bus со списком автобусов, на которые можно пересесть на каждой из остановок.
ALL_BUSES — вывести список всех маршрутов с остановками.
Формат ввода
В первой строке ввода содержится количество запросов Q, затем в Q строках следуют описания запросов.

Гарантируется, что все названия маршрутов и остановок состоят лишь из латинских букв, цифр и знаков подчёркивания.

Для каждого запроса NEW_BUS bus stop_count stop1 stop2 ... гарантируется, что маршрут bus отсутствует, количество остановок больше 0, а после числа stop_count следует именно такое количество названий остановок, причём все названия в каждом списке различны.

Формат вывода
Для каждого запроса, кроме NEW_BUS, выведите соответствующий ответ на него:

На запрос BUSES_FOR_STOP stop выведите через пробел список автобусов, проезжающих через эту остановку, в том порядке, в котором они создавались командами NEW_BUS. Если остановка stop не существует, выведите No stop.
На запрос STOPS_FOR_BUS bus выведите описания остановок маршрута bus в отдельных строках в том порядке, в котором они были заданы в соответствующей команде NEW_BUS. Описание каждой остановки stop должно иметь вид Stop stop: bus1 bus2 ..., где bus1 bus2 ... — список автобусов, проезжающих через остановку stop, в порядке, в котором они создавались командами NEW_BUS, за исключением исходного маршрута bus. Если через остановку stop не проезжает ни один автобус, кроме bus, вместо списка автобусов для неё выведите no interchange. Если маршрут bus не существует, выведите No bus.
На запрос ALL_BUSES выведите описания всех автобусов в алфавитном порядке. Описание каждого маршрута bus должно иметь вид Bus bus: stop1 stop2 ..., где stop1 stop2 ... — список остановок автобуса bus в порядке, в котором они были заданы в соответствующей команде NEW_BUS. Если автобусы отсутствуют, выведите No buses.
**
******************************************/

// Includes
#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

// Classes and function

enum class QueryType
{
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query
{
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream &operator>>(istream &is, Query &q)
{
    // Реализуйте эту функцию
    return is;
}

struct BusesForStopResponse
{
    // Наполните полями эту структуру
};

ostream &operator<<(ostream &os, const BusesForStopResponse &r)
{
    // Реализуйте эту функцию
    return os;
}

struct StopsForBusResponse
{
    // Наполните полями эту структуру
};

ostream &operator<<(ostream &os, const StopsForBusResponse &r)
{
    // Реализуйте эту функцию
    return os;
}

struct AllBusesResponse
{
    // Наполните полями эту структуру
};

ostream &operator<<(ostream &os, const AllBusesResponse &r)
{
    // Реализуйте эту функцию
    return os;
}

class BusManager
{
public:
    void AddBus(const string &bus, const vector<string> &stops)
    {
        // Реализуйте этот метод
    }

    BusesForStopResponse GetBusesForStop(const string &stop) const
    {
        // Реализуйте этот метод
    }

    StopsForBusResponse GetStopsForBus(const string &bus) const
    {
        // Реализуйте этот метод
    }

    AllBusesResponse GetAllBuses() const
    {
        // Реализуйте этот метод
    }
};

// Не меняя тела функции main, реализуйте функции и классы выше
// Main Code
int main(int argc, char const *argv[])
{
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i)
    {
        cin >> q;
        switch (q.type)
        {
        case QueryType::NewBus:
            bm.AddBus(q.bus, q.stops);
            break;
        case QueryType::BusesForStop:
            cout << bm.GetBusesForStop(q.stop) << endl;
            break;
        case QueryType::StopsForBus:
            cout << bm.GetStopsForBus(q.bus) << endl;
            break;
        case QueryType::AllBuses:
            cout << bm.GetAllBuses() << endl;
            break;
        }
    }
    /*  old code
    int q;
    cin >> q;

    map<string, vector<string>> buses_to_stops, stops_to_buses;

    for (int i = 0; i < q; ++i)
    {
        string operation_code;
        cin >> operation_code;

        if (operation_code == "NEW_BUS")
        {

            string bus;
            cin >> bus;
            int stop_count;
            cin >> stop_count;
            vector<string> &stops = buses_to_stops[bus];
            stops.resize(stop_count);
            for (string &stop : stops)
            {
                cin >> stop;
                stops_to_buses[stop].push_back(bus);
            }
        }
        else if (operation_code == "BUSES_FOR_STOP")
        {

            string stop;
            cin >> stop;
            if (stops_to_buses.count(stop) == 0)
            {
                cout << "No stop" << endl;
            }
            else
            {
                for (const string &bus : stops_to_buses[stop])
                {
                    cout << bus << " ";
                }
                cout << endl;
            }
        }
        else if (operation_code == "STOPS_FOR_BUS")
        {

            string bus;
            cin >> bus;
            if (buses_to_stops.count(bus) == 0)
            {
                cout << "No bus" << endl;
            }
            else
            {
                for (const string &stop : buses_to_stops[bus])
                {
                    cout << "Stop " << stop << ": ";
                    if (stops_to_buses[stop].size() == 1)
                    {
                        cout << "no interchange";
                    }
                    else
                    {
                        for (const string &other_bus : stops_to_buses[stop])
                        {
                            if (bus != other_bus)
                            {
                                cout << other_bus << " ";
                            }
                        }
                    }
                    cout << endl;
                }
            }
        }
        else if (operation_code == "ALL_BUSES")
        {

            if (buses_to_stops.empty())
            {
                cout << "No buses" << endl;
            }
            else
            {
                for (const auto &bus_item : buses_to_stops)
                {
                    cout << "Bus " << bus_item.first << ": ";
                    for (const string &stop : bus_item.second)
                    {
                        cout << stop << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
*/

    return 0;
}
