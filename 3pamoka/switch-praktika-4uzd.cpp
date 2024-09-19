#include <iostream>

using namespace std;


int main() {
    int grade1, grade2, grade3;
    int vidurkis;

    cout << "Iveskite 1 dalyko pazymi: " << endl; cin >> grade1;
    cout << "Iveskite 2 dalyko pazymi: " << endl; cin >> grade2;
    cout << "Iveskite 3 dalyko pazymi: " << endl; cin >> grade3;

    vidurkis = ((grade1+grade2+grade3)/3);


    switch(vidurkis)
    {
        case 10: {
            cout << "Puiku " << endl;
            break;
        }
        case 8: {
            cout << "Labai gerai " << endl;
            break;
        }
        case 9: {
            cout << "Labai gerai " << endl;
            break;
        }
        case 7: {
            cout << "Gerai " << endl;
            break;
        }
        case 5: {
            cout << "Patenkinamai" << endl;
            break;
        }
        case 6: {
            cout << "Patenkinamai" << endl;
            break;
        }
        case 4: {
            cout << "Egzaminas neislaikytas" << endl;
            break;
        }
        case 3: {
            cout << "Egzaminas neislaikytas" << endl;
            break;
        }
        case 2: {
            cout << "Egzaminas neislaikytas" << endl;
            break;
        }
        case 1: {
            cout << "Egzaminas neislaikytas" << endl;
            break;
        }


    }

    return 0;
}