#include <iostream>
#include <string>
#include <string.h>

using namespace std;

char LT_RAIDYNAS[32] =
{
    'A', 'À', 'B', 'C', 'È', 'D', 'E', 'Æ', 'Ë', 'F', 'G', 'H', 'I', 'Á', 'Y', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R',
    'S', 'Ð', 'T', 'U', 'Ø', 'Û', 'V', 'Z', 'Þ'
};


void sifruoti(const char pirmas[], const char raktas[], char final[], const int n, const int masyvas_strlen, const int koduote) {
    for (int i = 0; i < masyvas_strlen; i++) {
        int X = 0, Y = 0;

        if (koduote == 2) {
            X = static_cast<int>(pirmas[i]);
            Y = static_cast<int>(raktas[i]);
        } else {
            for (int j = 0; j < n; j++) {
                if (LT_RAIDYNAS[j] == pirmas[i]) X = j;
                if (LT_RAIDYNAS[j] == raktas[i]) Y = j;
            }
        }

        int finalinis = (X + Y) % n; // C = M(i) + K(i) (mod n)

        if (koduote == 1) {
            final[i] = LT_RAIDYNAS[finalinis];
        } else if (koduote == 2) {
            final[i] = static_cast<char>(finalinis);
        }
    }

    cout << "Uþðifruotas þodis: ";
    for (int xz = 0; xz < masyvas_strlen; xz++)
        cout << final[xz];
}


void issifruoti(char pirmas[], char raktas[], const int n, const int masyvas_strlen, const int koduote) {
    for (int i = 0; i < masyvas_strlen; i++) {
        int X = 0, Y = 0;

        if (koduote == 2) {
            X = static_cast<int>(pirmas[i]);
            Y = static_cast<int>(raktas[i]);
        } else {
            for (int j = 0; j < n; j++) {
                if (LT_RAIDYNAS[j] == pirmas[i]) X = j;
                if (LT_RAIDYNAS[j] == raktas[i]) Y = j;
            }
        }

        int finalinis = (X - Y + n) % n;


        if (koduote == 1) {
            pirmas[i] = LT_RAIDYNAS[finalinis];
        } else if (koduote == 2) {
            pirmas[i] = static_cast<char>(finalinis);
        }
    }

    cout << "Deðifruotas þodis: ";
    for (int zx = 0; zx < masyvas_strlen; zx++)
        cout << pirmas[zx];
}




int main() {

    system("chcp 1257 >nul");


    while(true) {

        int pasirinkimas;

        cout << "\nPasirinkite: \n1 - Uþðififruoti tekstà\n2 - Deðifruoti tekstà \nIvedimas: ";

        cin >> pasirinkimas;

        switch(pasirinkimas) {
            case 1: {
                cout << "-- Ðifravimas --" << endl;
                cout << "1 - LT abecelë\n2 - ASCII koduotë\nPasirinkite: ";

                int vidinis;
                cin >> vidinis;
                if ((vidinis == 1) || (vidinis == 2)) {

                    char pirmas[50] = {0};
                    char raktas[50] = {0};
                    char finalinis[50] = {0};


                    cout << "Iveskite teksta:\n ÁVEDIMAS: ";

                    cin >> pirmas;


                    if (vidinis != 2) {
                        for(int xy = 0; xy < strlen(pirmas); xy++)
                            pirmas[xy] = toupper(pirmas[xy]); // didziosios raides
                    }

                    cout << "Iveskite rakta:\nÁVEDIMAS: ";

                    cin >> raktas;

                    if (vidinis != 2) {
                        for(int zx = 0; zx < strlen(raktas); zx++)
                            raktas[zx] = toupper(raktas[zx]);
                    }

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
                    }

                    if(vidinis == 1) {
                        int n = sizeof(LT_RAIDYNAS) / sizeof(LT_RAIDYNAS[0]);
                        sifruoti(pirmas, raktas, finalinis, n, strlen(pirmas), 1);
                        break;
                    }
                    else if (vidinis == 2) {
                        int n = 128;
                        sifruoti(pirmas, raktas, finalinis, n, strlen(pirmas), 2);
                        break;
                    }
                }
                else {
                    return 0;
                }
            }
            case 2: {
                cout << "-- Desifravimas (issifravimas) --" << endl;
                cout << "1 - LT abecelë\n2 - ASCII koduotë\nPasirinkite: ";

                int vidinis;
                cin >> vidinis;
                if ((vidinis == 1) || (vidinis == 2)) {

                    char pirmas[50] = {0};
                    char raktas[50] = {0};


                    cout << "Iveskite teksta:\n ÁVEDIMAS: ";

                    cin >> pirmas;


                    if (vidinis != 2) {
                        for(int xy = 0; xy < strlen(pirmas); xy++)
                            pirmas[xy] = toupper(pirmas[xy]); // didziosios raides
                    }

                    cout << "Iveskite rakta:\nÁVEDIMAS: ";

                    cin >> raktas;

                    if (vidinis != 2) {
                        for(int zx = 0; zx < strlen(raktas); zx++)
                            raktas[zx] = toupper(raktas[zx]);
                    }

                    if (strlen(raktas) < strlen(pirmas)) {
                        int ilgis = strlen(raktas);
                        for (int i = ilgis; i < strlen(pirmas); i++) {
                            raktas[i] = raktas[i % ilgis];
                        }
                        raktas[strlen(pirmas)] = '\0';
                    }

                    if(vidinis == 1) {
                        int n = sizeof(LT_RAIDYNAS) / sizeof(LT_RAIDYNAS[0]);
                        issifruoti(pirmas, raktas, n, strlen(pirmas), 1);
                        break;
                    }
                    else if (vidinis == 2) {
                        int n = 128;  // ASCII simboliø skaièius
                        issifruoti(pirmas, raktas, n, strlen(pirmas), 2);
                        break;
                    }
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