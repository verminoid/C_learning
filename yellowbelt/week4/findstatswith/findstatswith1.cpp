/******************************************
**
**      File: findstatswith1.cpp
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
    char prefix) {
        auto f = lower_bound(range_begin, range_end, string {prefix});
        auto s = upper_bound(range_begin, range_end, string {static_cast<char>(prefix+1)});

        return make_pair(f, s);
    };


// Main Code
int main(int argc, char const *argv[])
{
    const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};

    const auto m_result = 
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto p_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    cout << (p_result.first - begin(sorted_strings)) << " " <<
        (p_result.second - begin(sorted_strings)) << endl;
  
    const auto z_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    cout << (z_result.first - begin(sorted_strings)) << " " <<
        (z_result.second - begin(sorted_strings)) << endl;

    return 0;
}
