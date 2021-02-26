/******************************************
**
**      File: figures.cpp
**      Project: workspace
**      Created By VERMIN
**      Date: 26/02/2021
**      Description: 

Как видно из кода, есть два вида команд: 

ADD — добавить фигуру в набор;
PRINT — для каждой фигуры в наборе распечатать название, периметр и площадь.
Программа поддерживает три вида фигур: прямоугольник, треугольник и круг. Их добавление описывается так:

ADD RECT width height —  добавить прямоугольник с размерами width и height (например, ADD RECT 2 3).
ADD TRIANGLE a b c —  добавить треугольник со сторонами a, b и c (например, ADD TRIANGLE 3 4 5).
ADD CIRCLE r —  добавить круг радиуса r (например, ADD CIRCLE 5).

Не меняя функцию main, реализуйте недостающие функции и классы:

базовый класс Figure с чисто виртуальными методами Name, Perimeter и Area;
классы Triangle, Rect и Circle, которые являются наследниками класса Figure и переопределяют его виртуальные методы;
функцию CreateFigure, которая в зависимости от содержимого входного потока создаёт shared_ptr<Rect>, shared_ptr<Triangle> или shared_ptr<Circle>.
Гарантируется, что размеры всех фигур — это натуральные числа не больше 1000. В качестве значения PI используйте 3,14.
******************************************/


// Includes
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <iomanip>
#include <math.h>


using namespace std;

// Classes and function
class Figure {

public:
    Figure(const string& name = "FIGURE") : name_(name){};
    virtual string Name() const = 0;
    virtual float Perimeter() const = 0;
    virtual float Area() const = 0;
    const string name_;
};

class Triangle : public Figure {
    public:
    Triangle(const int& a, const int& b, const int& c) : Figure("TRIANGLE"), a_(a),b_(b),c_(c) {};

    string Name() const override {
        return name_;
    };

    float Perimeter() const override {
        return a_+ b_ + c_;
    };

    float Area() const override {
        float p = Perimeter()/2;
        return sqrt(p*(p-a_)*(p-b_)*(p-c_));
    };

    
    const int a_,b_,c_;
};

class Rect : public Figure {
    public:
    Rect(const int& w, const int& h) : Figure("RECT"), widht_(w), height_(h) {};

    string Name() const override {
        return name_;
    };

    float Perimeter() const override {
        return widht_*2 + height_*2;
    };

    float Area() const override {
        return widht_ * height_;
    };

    
    const int widht_,height_;

};

class Circle : public Figure {
    public:
    Circle(const int& r) : Figure("CIRCLE"), r_(r) {};

    string Name() const override {
        return name_;
    };

    float Perimeter() const override {
        return 2 * 3.14 * r_;
    };

    float Area() const override {
        return 3.14 * r_*r_;
    };


    
    const int r_;

};

shared_ptr<Figure> CreateFigure(istringstream& is){
    string name;
    is >> name;
    if (name == "TRIANGLE") {
        int a,b,c;
        is >> ws >> a >> ws >> b >> ws >> c;
        return make_shared<Triangle>(a,b,c);
    }
    else if (name == "RECT"){
        int w,h;
        is >> ws >> w >> ws >> h;
        return make_shared<Rect>(w,h);
    } else if (name == "CIRCLE") {
        int r;
        is >> ws >> r;
        return make_shared<Circle>(r);
    }
    //else { return make_shared<Figure>();}
    return 0;
}

// Main Code
int main(int argc, char const *argv[])
{
    vector<shared_ptr<Figure>> figures;
            for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            // Пропускаем "лишние" ведущие пробелы.
            // Подробнее об std::ws можно узнать здесь:
            // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> ws;
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                     << current_figure->Name() << " "
                     << current_figure->Perimeter() << " "
                     << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}
