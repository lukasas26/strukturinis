#include <iostream>

using namespace std;


int main() {
    int years = 10;
    int padejo = 1000;
    int marza = 5;

    float gaus = ((padejo * marza/100) + padejo) * years;

    cout << "Po " << years << " metu " << gaus << endl;
}