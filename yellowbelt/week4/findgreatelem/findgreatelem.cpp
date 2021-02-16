/******************************************
**
**      File: findgreatelem.cpp
**      Project: workspace
**      Created By VERMIN
**      Date: 16/02/2021
**      Description: 
**
******************************************/


// Includes
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Classes and function
template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border)
{
    vector <T> great;
    auto bord = find_if(
        elements.begin(), elements.end(),
        [border](T element) {
            return element > border;
        }
    );
    for (auto it = bord; it != elements.end(); it++)
    {
        great.push_back(*it);
    };
    return great;
}

// Main Code
int main(int argc, char const *argv[])
{
    for (int x: FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
        cout << x << " ";
    }
    cout << endl;

    string to_find = "Python";
    cout << FindGreaterElements(set<string> {"C", "C++"}, to_find).size() << endl;
    return 0;
}
