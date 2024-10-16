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

void fizzbuzz(int n) {
    for (int i = 1; i <= n; i++) {
        {
            if ((i % 3 == 0) && (i % 5 == 0)) {
                cout << i << endl;
                cout << "FizzBuzz" << endl;

            }
            else if (i % 3 == 0) {
                cout << i << endl;
                cout << "Fizz" << endl;
            }
            else if (i % 5 == 0) {
                cout << i << endl;
                cout << "Buzz" << endl;
            }
            else {
                cout << i << endl;
            }

        }
    }
}


int main(){

    int pasirinkimas;

    while (true) {
        cout << "\nPasirinkite viena is siu funkciju:" << endl;
        cout << "1. Balsiu tikrinimas" << endl;
        cout << "2. Maziausias / didziausias bendras daliklis" << endl;
        cout << "3. Zaidimas 'Atspek Skaiciu'" << endl;
        cout << "4. FizzBuzz" << endl;
        cout << "9. Iseiti is programos" << endl;
        cout << "Iveskite pasirinkima (1-4): ";
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
                int pirmas, antras;
                cout << "Iveskite pirma skaiciu: " << endl;
                cin >> pirmas;
                cout << "Iveskite antra skaiciu: " << endl;
                cin >> antras;

                int dbd = EuklidoAlgoritmas(pirmas, antras);
                int mbd = MaziausiasBendrasDaliklis(pirmas, antras);

                cout << "Maziausias bendras daliklis " << pirmas << " ir " << antras << " yra: " << mbd << endl;
                cout << "Didziausias bendras daliklis " << pirmas << " ir " << antras << " yra: " << dbd << endl;

                break;
            }
            case 3: {
                zaidimas();
                break;
            }
            case 4: {
                int skaicius;
                cout << "----- FizzBuzz -----" << endl;
                cout << "Paisirinkite sekos skaiciu (iki): " << endl;
                cin >> skaicius;
                fizzbuzz(skaicius);
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

