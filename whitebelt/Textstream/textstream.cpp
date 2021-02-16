#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student
{
    string name;
    string Surname;
    int day;
    int mounth;
    int year;
};

struct Request
{
    string request;
    int num;
};

int main()
{
    int n;
    cin >> n;
    vector<Student> Students;
    for (int i = 0; i < n; i++)
    {
        Students.push_back(Student{});
        cin >> Students[i].name >> Students[i].Surname >> Students[i].day >> Students[i].mounth >> Students[i].year;
    }
    int m;
    cin >> m;
    vector<Request> Requests;
    for (int i = 0; i < m; i++)
    {
        int temp;
        Requests.push_back(Request{});
        cin >> Requests[i].request;

        cin >> Requests[i].num;
        --Requests[i].num;
    }

    for (auto i : Requests)
    {
        if (i.request == "name")
        {
            cout << Students[i.num].name << " " << Students[i.num].Surname << endl;
        }
        else
        {
            if (i.request == "date")
            {
                cout << Students[i.num].day << "." << Students[i.num].mounth << "." << Students[i.num].year << endl;
            }
            else
            {
                cout << "Bad Request" << endl;
            }
        }
    }

    return 0;
}

/*
int main() {
    ifstream input ("input.txt" );
    int n,m;
    int num;

    if (input.is_open()) {
        input >> n;
        input >> m;
        
        // перебираем строки

    for (int i = 0; i < n; ++i) {

    // перебираем столбцы

        for (int j = 0; j < m; ++j) {

      // считываем очередное число

            int x;

            input >> x;

      // пропускаем следующий символ

            input.ignore(1);

      // выводим число в поле ширины 10

            cout << setw(10) << x;

      // выводим пробел, если только этот столбец не последний

            if (j != m - 1) {

                cout << " ";

            }

        }

    // выводим перевод строки, если только эта строка не последняя

        if (i != n - 1) {

             cout << endl;

        }

    }  
            
            
    
    } else {
        cout << "error!";
    }
    
   
    return 0;
}
*/
