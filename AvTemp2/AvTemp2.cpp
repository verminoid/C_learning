/*
/  Средняя температура 2
*/
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    uint16_t n;
    cin >> n;
    vector<int32_t> temperatures(n);
    int32_t sum = 0;
    for (int32_t &temperature : temperatures)
    {
        cin >> temperature;
        sum += temperature;
    }

    int32_t average = sum / static_cast<int32_t>(n);
    vector<int32_t> result_indices;
    for (uint16_t i = 0; i < n; ++i)
    {
        if (temperatures[i] > average)
        {
            result_indices.push_back(i);
        }
    }

    cout << result_indices.size() << endl;
    for (uint16_t result_index : result_indices)
    {
        cout << result_index << " ";
    }
    cout << endl;
    return 0;
}
