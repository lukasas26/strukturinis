#include <iostream>
#include <string>

using namespace std;

bool balsis(char simbolis) {
    const string balsiai = "aeiou";

    for (int i = 0; i < balsiai.length(); i++) {
        if (simbolis == balsiai[i]) {
            return true;
        }
    }

    return false;
}

int EuklidoAlgoritmas(int skaicius1, int skaicius2) {
    while (skaicius2 != 0) {
        int temp = skaicius2;
        skaicius2 = skaicius1 % skaicius2;
        skaicius1 = temp;
    }
    return skaicius1;
}

int MaziausiasBendrasDaliklis(int skaicius1, int skaicius2) {
    return (skaicius1 * skaicius2) / EuklidoAlgoritmas(skaicius1, skaicius2);
}

int RandomNum(int nuo, int iki) {
    return rand() % iki + nuo;
}


void zaidimas() {
    int pasirinkimas = RandomNum(1, 100);

    cout << pasirinkimas << endl;

    cout << "------------- [ATSPEK SKAICIU] -------------------" << endl;
    cout << "Atspekite skaiciu nuo 1 iki 100, kuri sugalvojo kompiuteris:" << endl;

    while (true) {

        int spejimas;
        cin >> spejimas;

        if (pasirinkimas != spejimas) {
            if (pasirinkimas < spejimas) {
                cout << "Pamegink dar karta! Skaicius buvo mazesnis." << endl;
            } else if (pasirinkimas > spejimas) {
                cout << "Pamegink dar karta! Skaicius buvo didesnis." << endl;
            }
        } else {
            cout << "Valio! Skaicius buvo " << spejimas << " ." << endl;
            break;
        }
    }

}

void funkcija4() {
    cout << "Cia funkcija 4" << endl;
}

int main() {

    int pasirinkimas;

    while (true) {
        cout << "\nPasirinkite viena is siu funkciju:" << endl;
        cout << "1. Balsiu tikrinimas" << endl;
        cout << "2. Maziausias / didziausias bendras daliklis" << endl;
        cout << "3. Zaidimas 'Atspek Skaiciu'" << endl;
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
                int pirmas, antras, dbd, mbd;
                cout << "Iveskite pirma skaiciu: " << endl;
                cin >> pirmas;
                cout << "Iveskite antra skaiciu: " << endl;
                cin >> antras;

                dbd = EuklidoAlgoritmas(pirmas, antras);
                mbd = MaziausiasBendrasDaliklis(pirmas, antras);

                cout << "Maziausias bendras daliklis " << pirmas << " ir " << antras << " yra: " << mbd << endl;
                cout << "Didziausias bendras daliklis " << pirmas << " ir " << antras << " yra: " << dbd << endl;

                break;
            }
            case 3: {
                zaidimas();
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

