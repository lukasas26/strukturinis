#include <iostream>

using namespace std;


int main()
{

    int grade1, grade2, grade3;
    float vidurkis;

    cout << "Iveskite 1 dalyko pazymi: " << endl; cin >> grade1;
    cout << "Iveskite 2 dalyko pazymi: " << endl; cin >> grade2;
    cout << "Iveskite 3 dalyko pazymi: " << endl; cin >> grade3;

    if (vidurkis == 10)
    {
        cout << "Puiku " << endl;
    }
    else if (vidurkis >= 8)
    {
        cout << "Labai gerai " << endl;
    }
    else if (vidurkis >= 7)
    {
        cout << "Gerai " << endl;
    }
    else if (vidurkis >= 5)
    {
        cout << "Patenkinamai " << endl;
    }
    else if (vidurkis < 5)
    {
        cout << "Egzaminas neislaikytas " << endl;
    }


    vidurkis = ((grade1+grade2+grade3)/3);

    cout << "Dalyku vidurkis: " << vidurkis << endl;

    if (vidurkis >= 5)
    {
        cout << "Dalyku vidurkis teigiamas" << endl;
    }
    else
    {
        cout << "Dalyku vidurkis neigiamas" << endl;
    }

    return 0;
}

