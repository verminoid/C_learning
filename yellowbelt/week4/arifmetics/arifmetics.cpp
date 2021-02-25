/******************************************
**
**      File: arifmetics.cpp
**      Project: workspace
**      Created By VERMIN
**      Date: 20/02/2021
**      Description: 
**
******************************************/


// Includes
#include <iostream>
#include <string>
#include <deque>
#include <iomanip>
#include <sstream>


using namespace std;

// Classes and function
enum class QueryType {
    add,
    sub,
    mul,
    div
};

struct Query {
    QueryType type;
    string value;
};

istream& operator>> (istream& is, Query& q) {
    string typestr;
    is >> typestr;
    if (typestr == "+") {
        q.type = QueryType::add;
        is >> q.value;
    } else if (typestr == "-") {
        q.type = QueryType::sub;
        is >> q.value; 
    } else if (typestr == "*") {
        q.type = QueryType::mul;
        is >> q.value;
    } else if (typestr == "/") {
        q.type = QueryType::div;
        is >> q.value;
    } 
    return is;
};
// Main Code
int main(int argc, char const *argv[])
{
    int x;
    cout << "Input starter: ";
    cin >> x;
    int n;
    cout << "Number of operation: ";
    cin >> n;
    Query q;

    deque<string> d;
    d.push_back(to_string(x));
    for (size_t i = 0; i < n; i++)
    {
        cin >> q;
        switch (q.type)
        {
        case QueryType::add:
            d.push_front("(");
            d.push_back(")");
            d.push_back("+");
            d.push_back(q.value);
            break;
        case QueryType::sub:
            d.push_front("(");
            d.push_back(")");
            d.push_back("-");
            d.push_back(q.value);
            break;
        case QueryType::mul:
            d.push_front("(");
            d.push_back(")");
            d.push_back("*");
            d.push_back(q.value);
            break;
        case QueryType::div:
            d.push_front("(");
            d.push_back(")");
            d.push_back("/");
            d.push_back(q.value);
            break;
        
        default:
            break;
        }
    }
    for (auto& item:d) {
        if (item == "+" || item == "-" || item == "*" || item == "/"){
            cout << " " << item << " ";

        } else {
            cout << item;
        }
    }
    return 0;
}
