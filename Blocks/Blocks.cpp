/*********************************
 * 
 *    Желтый уровень
 *    Масса блоков
 * 
 * *******************************/
#include <iostream>
#include <vector>

using namespace std;




int main(int argc, char const *argv[])
{
    uint32_t n;
    uint16_t r; 
    cin >> n >> r;
    uint32_t wight_Sum = 0;
    for (uint32_t i = 0; i < n; i++)
    {
        uint32_t w,h,d;
        cin >> w >> h >> d;
        wight_Sum += (w*h*d)*r;
    }
    cout << wight_Sum << endl;

    return 0;
}
 