/******************************************
**
**      File: AllSQRT.cpp
**      Project: Learning
**      Created By VERMIN
**      Date: 25/09/2020
**      Description: 
**
******************************************/
/*
Реализуйте шаблонную функцию Sqr, которая работает не только для чисел, но и для контейнеров. Функция должна возвращать копию исходного контейнера, модифицировав его следующим образом:

для vector элементы нужно возвести в квадрат;
для map в квадрат нужно возвести только значения, но не ключи;
для pair в квадрат нужно возвести каждый элемент пары.

Функция должна корректно работать не только для контейнеров, состоящих из чисел, но и для составных объектов, например, векторов словарей пар чисел.


*/

// // Предварительное объявление шаблонных функций
// template<typename T> T FuncA(T x);
// template<typename T> void FuncB(T x);

// // Объявляем шаблонные функции
// template <typename T>
// T FuncA(T x) { /*...*/ }

// template <typename T>
// void FuncB(T x) { /*...*/ }


// Includes
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <string>

using namespace std;

// Classes and function



// Main Code
int main(int argc, char const *argv[])
{
    // Пример вызова функции
vector<int> v = {1, 2, 3};
cout << "vector:";
for (int x : Sqr(v)) {
  cout << ' ' << x;
}
cout << endl;

map<int, pair<int, int>> map_of_pairs = {
  {4, {2, 2}},
  {7, {4, 3}}
};
cout << "map of pairs:" << endl;
for (const auto& x : Sqr(map_of_pairs)) {
  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
}
    return 0;
}
