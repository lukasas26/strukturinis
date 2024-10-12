#include <iostream>
#include <string>

using namespace std;

bool balsis(char simbolis) {
    const string balsiai = "aeiouąęįųū";

    for (int i = 0; i < balsiai.length(); i++) {
        if (simbolis == balsiai[i]) {
            return true;
        }
    }

    return false;
}

void funkcija2() {
    cout << "Cia funkcija 2" << endl;
}

void funkcija3() {
    cout << "Cia funkcija 3" << endl;
}

void funkcija4() {
    cout << "Cia funkcija 4" << endl;
}

int main() {

    int pasirinkimas;

    while (true) {
        cout << "\nPasirinkite viena is siu funkciju:" << endl;
        cout << "1. Balsiu tikrinimas" << endl;
        cout << "2. Funkcija 2" << endl;
        cout << "3. Funkcija 3" << endl;
        cout << "4. Funkcija 4" << endl;
        cout << "9. Iseiti is programos" << endl;

        cout << "Iveskite pasirinkima (1-5): ";
        cin >> pasirinkimas;

        switch (pasirinkimas) {
            case 1: {
                char simbolis;
                cout << "Iveskite simboli, kuri norit patikrinti: " << endl;
                cin >> simbolis;
                cout << balsis(simbolis);
                break;
            }
            case 2: {
                funkcija2();
                break;
            }
            case 3: {
                funkcija3();
                break;
            }
            case 4: {
                funkcija4();
                break;
            }
            case 9: {
                cout << "Programa sustabdyta." << endl;
                return 0;
            }
            default: {
                cout << "Netinkamas pasirinkimas. Bandykite dar karta." << endl;
                return 0;
            }
        }
    }
}

