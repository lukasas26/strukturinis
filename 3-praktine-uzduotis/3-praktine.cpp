#include <iostream>
#include <string>

using namespace std;

char LT_RAIDYNAS[32] =
{
    'A', 'À', 'B', 'C', 'È', 'D', 'E', 'Æ', 'Ë', 'F', 'G', 'H', 'I', 'Á', 'Y', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R',
    'S', 'Ð', 'T', 'U', 'Ø', 'Û', 'V', 'Z', 'Þ'
};

char ASCII_RAIDYNAS[93] =
{
    '!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
    'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z', '{', '|', '}',
    '~'
};

void test1() {
    cout << "Cia bus pirma" << endl;
}

void test2() {
    cout << "Cia bus antra" << endl;
}

void test3() {
    cout << "Cia bus 3" << endl;
}

void test4() {
    cout << "Cia bus 4" << endl;
}

int main() {

    system("chcp 1257 >nul");


    while(true) {

        int pasirinkimas;

        cout << "Pasirinkite: \n1 - Uþðifruoti tekstà\n2 - Deðifruoti tekstà \nIvedimas: ";

        cin >> pasirinkimas;

        switch(pasirinkimas) {
            case 1: {
                cout << "-- Ðifravimas --" << endl;
                cout << "1 - LT abecelë\n2 - ASCII koduotë\nPasirinkite: ";

                int vidinis;
                cin >> vidinis;
                if (vidinis == 1) {
                    test1();
                    break;
                }
                else if(vidinis == 2) {
                    test2();
                    break;
                }
                else {
                    return 0;
                }
            }
            case 2: {
                cout << "-- Deðifravimas --" << endl;
                cout << "1 - LT abecelë\n2 - ASCII koduotë\nPasirinkite: ";

                int vidinis;
                cin >> vidinis;
                if (vidinis == 1) {
                    test3();
                }
                else if(vidinis == 2) {
                    test4();
                }
                else {
                    return 0;
                }
            }
            default: {
                return 0;
            }

        }

    }


    return 0;
}