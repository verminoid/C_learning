/**
 * 
 *    Работа по теме Класс Rational
 * 
 *    Created by Vermin
 * 
 * */

// Includes
#include <iostream>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <map>
#include <set>
#include <vector>

using namespace std;

// classes
class Rational
{
public:
    Rational()
    {
        numer = 0;
        denomin = 1;
    }

    Rational(int numerator, int denominator)
    {
        int temp;
        temp = gcd(numerator, denominator);
        if (temp > 1)
        {
            numerator /= temp;
            denominator /= temp;
        }

        if (numerator < 0 && denominator < 0)
        {
            numer = abs(numerator);
            denomin = abs(denominator);
        }
        else if (denominator < 0)
        {
            numer = -numerator;
            denomin = abs(denominator);
        }
        else if (numerator == 0)
        {
            numer = 0;
            denomin = 1;
        }
        else
        {
            numer = numerator;
            denomin = denominator;
        }
    }

    int Numerator() const
    {
        return numer;
    }

    int Denominator() const
    {
        return denomin;
    }
    

private:
    int numer;
    int denomin;
};

//function
bool operator==(const Rational &lhs, const Rational &rhs)
{
    if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator())
    {
        return true;
    }
    return false;
}

bool operator>(const Rational &lhs, const Rational &rhs)
{
    if (lhs.Numerator()*rhs.Denominator() > rhs.Numerator() * lhs.Denominator())
    {return true;}
    else
    {
        return false;
    }
    
}

bool operator<(const Rational &lhs, const Rational &rhs)
{
    if (lhs.Numerator()*rhs.Denominator() < rhs.Numerator() * lhs.Denominator())
    {return true;}
    else
    {
        return false;
    }
    
}

Rational operator+(const Rational &lhs, const Rational &rhs)
{
    int sum_num = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
    int sum_den = lhs.Denominator() * rhs.Denominator();
    return Rational(sum_num,sum_den);
}

Rational operator-(const Rational &lhs, const Rational &rhs)
{
    int sum_num = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
    int sum_den = lhs.Denominator() * rhs.Denominator();
    return Rational(sum_num,sum_den);
}
Rational operator*(const Rational &lhs, const Rational &rhs)
{
    int num = lhs.Numerator()*rhs.Numerator();
    int den = lhs.Denominator()*rhs.Denominator();
    return Rational(num,den);
}
Rational operator/(const Rational &lhs, const Rational &rhs)
{
    int num = lhs.Numerator()*rhs.Denominator();
    int den = lhs.Denominator()*rhs.Numerator();
    return Rational(num,den);
}
istream& operator>>(istream& stream, Rational& rational)
{
    int n,m;
    char divider;
    stream >> n;
    stream >> divider;
    stream >> m;
    if (!stream.fail())
    {
        if (divider == '/')
    {
        rational = {n,m};
    }
    
    }
    
    return stream;
}
ostream& operator<<(ostream& stream, const Rational& rational)
{
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

// проверка

/**
 * Main program
 * */
int main(int argc, const char **argv)
{
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }
    
    cout << "OK" << endl;
    return 0;
}
