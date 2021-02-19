/******************************************
**
**      File: findstatswith2.cpp
**      Project: workspace
**      Created By VERMIN
**      Date: 19/02/2021
**      Description: 
**
******************************************/


// Includes
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

// Classes and function
template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    const string& prefix) {
        return equal_range(range_begin, range_end, prefix, [&prefix](const string& a,const string& b) { 
            return a.compare(0, prefix.length(), b.substr(0, prefix.length())) < 0;
            });
    };

// Main Code
int main() {
  const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};
  
  const auto mo_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
  for (auto it = mo_result.first; it != mo_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;
  
  const auto mt_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
  cout << (mt_result.first - begin(sorted_strings)) << " " <<
      (mt_result.second - begin(sorted_strings)) << endl;
  
  const auto na_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
  cout << (na_result.first - begin(sorted_strings)) << " " <<
      (na_result.second - begin(sorted_strings)) << endl;
  
  return 0;
}

