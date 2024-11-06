#include <iostream>
#include <string>
#include <string.h>

using namespace std;

char LT_RAIDYNAS[32] =
{
    'A', '�', 'B', 'C', '�', 'D', 'E', '�', '�', 'F', 'G', 'H', 'I', '�', 'Y', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R',
    'S', '�', 'T', 'U', '�', '�', 'V', 'Z', '�'
};

char ASCII_RAIDYNAS[93] =
{
    '!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
    'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z', '{', '|', '}',
    '~'
};

void sifruoti(const char pirmas[], const char antras[], char final[], const int n, const int masyvas_strlen, const int koduote){ // MasyvoIlgis 30.
    for(int i = 0; i < masyvas_strlen; i++){

        int X = 0, Y = 0; // sifravimo rakto pozicija

         for(int j = 0; j < n; j++){
             switch(koduote){
                 case 1: {
                     if(LT_RAIDYNAS[j] == pirmas[i]) {
                         X = j;
                     }
                     if(LT_RAIDYNAS[j] == antras[i]) {
                         Y = j;
                     }

                     break;
                 }

             }
         }

        int finalinis = 0;

        finalinis = (X + Y) % n; // C = M(i) + K(i ) ( mod n)

        if(koduote == 1) {
            final[i] = LT_RAIDYNAS[finalinis];
        }
    }
    cout << "U��ifruotas �odis: ";
    for(int xz = 0; xz < masyvas_strlen; xz++)
        cout << final[xz];
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

        cout << "Pasirinkite: \n1 - U��ifruoti tekst�\n2 - De�ifruoti tekst� \nIvedimas: ";

        cin >> pasirinkimas;

        switch(pasirinkimas) {
            case 1: {
                cout << "-- �ifravimas --" << endl;
                cout << "1 - LT abecel�\n2 - ASCII koduot�\nPasirinkite: ";

                int vidinis;
                cin >> vidinis;
                if (vidinis == 1) {

                    char pirmas[30] = {0};
                    char raktas[30] = {0};
                    char finalinis[30] = {0};


                    cout << "Iveskite teksta:\n �VEDIMAS: ";

                    cin >> pirmas;

                    for(int xy = 0; xy < strlen(pirmas); xy++)
                        pirmas[xy] = toupper(pirmas[xy]); // didziosios raides

                    cout << "Iveskite rakta:\n�VEDIMAS: ";

                    cin >> raktas;

                    for(int zx = 0; zx < strlen(raktas); zx++)
                        raktas[zx] = toupper(raktas[zx]);

                    int n = sizeof(LT_RAIDYNAS) / sizeof(LT_RAIDYNAS[0]);

                    if(strlen(raktas) < strlen(pirmas)){ // jei raktas trumpestis uz tekstas
                        int x = 0;
                        for(int i = strlen(raktas); i < strlen(pirmas); i++){
                            if(raktas[x] == pirmas[i-1]){
                                x++;
                                raktas[i] = raktas[x];
                            }
                            else{
                                raktas[i] = raktas[x];
                                x++;
                            }
                        }
                    } // Pv� �odis LABAS, RA

                    sifruoti(pirmas, raktas, finalinis, n, strlen(pirmas), 1);


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
                cout << "-- De�ifravimas --" << endl;
                cout << "1 - LT abecel�\n2 - ASCII koduot�\nPasirinkite: ";

                int vidinis;
                cin >> vidinis;
                if (vidinis == 1) {

//
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