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
    int cols;
    int rows;
    vector<vector<int>> matrix_2_2;
public:
    Matrix()
    {
        cols = 0;
        rows = 0;
    };

    Matrix(const int& num_rows, const int& num_cols)
    {
        Reset(num_rows,num_cols);
    };

    void Reset(const int& num_rows, const int& num_cols)
    {
        cols = num_cols;
        rows = num_rows;
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
        
        return matrix_2_2.at(row).at(col);
    };
    int& At(const int& col, const int& row) 
    {
        
        return matrix_2_2.at(row).at(col);
    };
    int GetNumRows() const {
      return rows;
    };
    int GetNumCols() const {
      return cols;
    }
    
};

/// Операции с матрицами


int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;
  return 0;
}
