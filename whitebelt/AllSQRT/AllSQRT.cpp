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
// предварительное объявление
template <typename T> T& Sqr(T& value);
template <typename T> vector<T>& Sqr(vector<T>& vi);
template <typename First, typename Second> pair<First,Second>& Sqr(pair<First,Second>& p);
template <typename Key, typename Value> map<Key,Value>& Sqr(map<Key,Value>& m);

// шаблон общий
template <typename T>
T& Sqr(T& value)
{
    value=value*value;
    return value;
};

// Шаблон для вектора
template <typename T>
vector<T>& Sqr(vector<T>& vi)
{
    for (auto &i : vi)
    {
        i=Sqr(i);
    }
    return vi;
};

// шаблон для pair
template <typename First, typename Second>
pair<First,Second>& Sqr(pair<First,Second>& p)
{
    
        p.first = Sqr(p.first);
        p.second = Sqr(p.second);
    
    return p;
}

// шаблон для map
template <typename Key, typename Value>
map<Key,Value>& Sqr(map<Key,Value>& m)
{
    for(auto &i : m)
    {
        i.second = Sqr(i.second);
    }
    return m;
}



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
