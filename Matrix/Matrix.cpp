#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix
class Matrix
{
private:
    vector<vector<int>> matrix_2_2;
public:
    Matrix()
    {
        matrix_2_2 = {0};
    };

    Matrix(const int& num_rows, const int& num_cols)
    {
        matrix_2_2.assign(num_rows, vector<int>(5));
    };

    Reset(const int& num_rows, const int& num_cols)
    {
        matrix_2_2.assign(num_rows, vector<int>(num_cols));
        for(auto rows : matrix_2_2)
        {
            for(auto cols : rows)
            {
                cols = 0;
            }
        };
        
    };

    int At(const int& col, const int& row) const
    {
        
        return matrix_2_2.At(row).At(col);
    };
    int& At(const int& col, const int& row) 
    {
        
        return matrix_2_2.At(row).At(col);
    }

    
};




int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;
  return 0;
}
