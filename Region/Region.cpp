/******************************************
**
**      File: Region.cpp
**      Project: Learning
**      Created By VERMIN
**      Date: 23/09/2020
**      Description: 
**
******************************************/

// Includes
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// Classes and function
struct Region
{
    string std_name;
    string parent_std_name;
    map<Lang, string> names;
    int64_t population;
};
enum class Lang
{
    DE,
    FR,
    IT
};

// TODO: написать эту функцию
int FindMaxRepetitionCount(const vector<Region> &regions)
{
    int count = 0;
    if (regions.empty())
    {
        return 0;
    }
    
    for(auto item : regions)
    {
        
    }
    return count; //todo
}
    
// Main Code
int main(int argc, char const *argv[])
{
    cout << FindMaxRepetitionCount({
                {"Moscow",
                 "Russia",
                 {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                 89},
                {"Russia",
                 "Eurasia",
                 {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                 89},
                {"Moscow",
                 "Russia",
                 {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                 89},
                {"Moscow",
                 "Russia",
                 {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                 89},
                {"Russia",
                 "Eurasia",
                 {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                 89},
            })
         << endl;

    cout << FindMaxRepetitionCount({
                {"Moscow",
                 "Russia",
                 {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                 89},
                {"Russia",
                 "Eurasia",
                 {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                 89},
                {"Moscow",
                 "Russia",
                 {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
                 89},
                {"Moscow",
                 "Toulouse",
                 {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                 89},
                {"Moscow",
                 "Russia",
                 {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                 31},
            })
         << endl;

    return 0;
}
