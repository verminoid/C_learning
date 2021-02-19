/******************************************
**
**      File: mergesort.cpp
**      Project: workspace
**      Created By VERMIN
**      Date: 17/02/2021
**      Description: 
**
******************************************/


// Includes
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Classes and function
template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
    //algorithm
    // 1
    if (distance(range_begin, range_end) < 2) {
        return;
    }
    // 2
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    // 3
    auto it = elements.begin() + elements.size()/2;

    MergeSort(elements.begin(), it);
    MergeSort(it, elements.end());
    // 5
    merge(elements.begin(), it, it, elements.end(), range_begin);


};

// Main Code
int main(int argc, char const *argv[])
{
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
