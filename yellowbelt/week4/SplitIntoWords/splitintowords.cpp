/******************************************
**
**      File: splitintowords.cpp
**      Project: workspace
**      Created By VERMIN
**      Date: 16/02/2021
**      Description: 
**
******************************************/


// Includes
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Classes and function
vector<string> SplitIntoWords(const string& s) {
    vector<string> words;
    auto start = s.begin();
    auto stop = s.end();

    while (start != s.end()) {
        
        if (*start == ' ') { 
            start = start+1;
        }
        
        string::const_iterator stop = find_if(
            start, s.end(),
            [](char simbol) {
                return simbol == ' ';
            }
        );
        string word;
        for (auto it = start; it != stop; it++) {
            word += *it;
        };
        start = stop;
        words.push_back(word);

    };
    
    return words;

};

// Main Code
int main(int argc, char const *argv[])
{
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}
