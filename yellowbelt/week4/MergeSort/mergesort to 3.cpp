/******************************************
**
**      File: mergesort to 3.cpp
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
    if (distance(range_begin, range_end) < 3) {
        return;
    }
    // 2
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    // 3
    auto it = elements.begin() + elements.size()/3;
    auto it2 = elements.begin() + elements.size()/3*2;

    MergeSort(elements.begin(), it);
    MergeSort(it, it2);
    MergeSort(it2, elements.end());
    // 5
    vector<typename RandomIt::value_type> temp;
    merge(elements.begin(), it, it, it2, back_inserter(temp));
    merge(temp.begin(), temp.end(), it2, elements.end(), range_begin);


};

// Main Code
int main(int argc, char const *argv[])
{
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
