#include <iostream>

using namespace std;


int main()
{
    int suma = 0, i = 0;

    for (suma; i<=20; i++)
    {
        if (i % 2 != 0) {
            suma += i;
            cout << "Skaicius: " << i << endl; cout << "Tarpine suma: " << suma << endl;
        }
    }
}

