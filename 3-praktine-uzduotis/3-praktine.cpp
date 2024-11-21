#include <iostream>
#include <string>
#include <string.h>

using namespace std;

const char LT_RAIDYNAS[] = {
    'A', '�', 'B', 'C', '�', 'D', 'E', '�', '�', 'F', 'G', 'H', 'I', '�', 'Y',
    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', '�', 'T', 'U', '�', '�', 'V',
    'Z', '�'
};

// Tvarkom rakta, kad jo ilgis atitikt� �ifruojamo arba de�ifruojamo teksto ilg�.
void adaptuoti_rakta(char raktas[], const char pirmas[], int tekstas_ilgis) {
    int raktas_ilgis = strlen(raktas);
    for (int i = 0; i < tekstas_ilgis; i++) {
        raktas[i] = raktas[i % raktas_ilgis];
    }
    raktas[tekstas_ilgis] = '\0';
}

void sifruoti(const char pirmas[], const char raktas[], char final[], const int n, const int masyvas_strlen, const int koduote) {
    int finalinis;
    for (int i = 0; i < masyvas_strlen; i++) {
        int X = 0, Y = 0;

        if (koduote == 2) {
            X = static_cast<int>(pirmas[i]);
            Y = static_cast<int>(raktas[i]);
            finalinis = ((X + Y - 64) % 95) + 32; // naikinam neiterpiamus simbolius buvo 64

        } else {
            for (int j = 0; j < n; j++) {
                if (LT_RAIDYNAS[j] == pirmas[i]) X = j;
                if (LT_RAIDYNAS[j] == raktas[i]) Y = j;
            }
            finalinis = (X + Y) % n; // C = M(i) + K(i) (mod n)
        }

        if (koduote == 1) {
            final[i] = LT_RAIDYNAS[finalinis];
        } else if (koduote == 2) {
            final[i] = static_cast<char>(finalinis);
        }
    }

    cout << "U��ifruotas �odis: ";
    for (int xz = 0; xz < masyvas_strlen; xz++)
        cout << final[xz];
}

void issifruoti(char pirmas[], char raktas[], const int n, const int masyvas_strlen, const int koduote) {

    int finalinis;
    for (int i = 0; i < masyvas_strlen; i++) {
        int X = 0, Y = 0;

        if (koduote == 2) {
            X = static_cast<int>(pirmas[i]);
            Y = static_cast<int>(raktas[i]);

            finalinis = ((X - Y + 95) % 95) + 32;

        } else {
            for (int j = 0; j < n; j++) {
                if (LT_RAIDYNAS[j] == pirmas[i]) X = j;
                if (LT_RAIDYNAS[j] == raktas[i]) Y = j;

            }
            finalinis = (X - Y + n) % n;
        }


        if (koduote == 1) {
            pirmas[i] = LT_RAIDYNAS[finalinis];
        } else if (koduote == 2) {
            pirmas[i] = static_cast<char>(finalinis);
        }
    }

    cout << "De�ifruotas �odis: ";
    for (int zx = 0; zx < masyvas_strlen; zx++)
        cout << pirmas[zx];
}

int main() {
    system("chcp 1257 >nul");

    while (true) {
        int pasirinkimas;

        cout << "\nPasirinkite: \n1 - U��ifruoti tekst�\n2 - De�ifruoti tekst� \nIvedimas: ";

        cin >> pasirinkimas;

        switch (pasirinkimas) {
            case 1: {
                cout << "-- �ifravimas --" << endl;
                cout << "1 - LT abecel�\n2 - ASCII koduot�\nPasirinkite: ";

                int vidinis;
                cin >> vidinis;
                if ((vidinis == 1) || (vidinis == 2)) {
                    char pirmas[50] = {0};
                    char raktas[50] = {0};
                    char finalinis[50] = {0};

                    cout << "Iveskite teksta:\n �VEDIMAS: ";
                    cin >> pirmas;

                    if (vidinis != 2) {
                        for (int xy = 0; xy < strlen(pirmas); xy++)
                            pirmas[xy] = toupper(pirmas[xy]); // didziosios raides
                    }

                    cout << "Iveskite rakta:\n�VEDIMAS: ";
                    cin >> raktas;

                    if (vidinis != 2) {
                        for (int zx = 0; zx < strlen(raktas); zx++)
                            raktas[zx] = toupper(raktas[zx]);
                    }

                    if (strlen(raktas) < strlen(pirmas)) {
                        adaptuoti_rakta(raktas, pirmas, strlen(pirmas));
                    }

                    if (vidinis == 1) {
                        int n = sizeof(LT_RAIDYNAS) / sizeof(LT_RAIDYNAS[0]);
                        sifruoti(pirmas, raktas, finalinis, n, strlen(pirmas), 1);
                        break;
                    } else if (vidinis == 2) {
                        int n = 128;
                        sifruoti(pirmas, raktas, finalinis, n, strlen(pirmas), 2);
                        break;
                    }
                } else {
                    return 0;
                }
            }
            case 2: {
                cout << "-- De�ifravimas --" << endl;
                cout << "1 - LT abecel�\n2 - ASCII koduot�\nPasirinkite: ";

                int vidinis;
                cin >> vidinis;
                if ((vidinis == 1) || (vidinis == 2)) {
                    char pirmas[50] = {0};
                    char raktas[50] = {0};

                    cout << "Iveskite teksta:\n �VEDIMAS: ";
                    cin >> pirmas;

                    if (vidinis != 2) {
                        for (int xy = 0; xy < strlen(pirmas); xy++)
                            pirmas[xy] = toupper(pirmas[xy]); // didziosios raides
                    }

                    cout << "Iveskite rakta:\n�VEDIMAS: ";
                    cin >> raktas;

                    if (vidinis != 2) {
                        for (int zx = 0; zx < strlen(raktas); zx++)
                            raktas[zx] = toupper(raktas[zx]);
                    }

                    if (strlen(raktas) < strlen(pirmas)) {
                        adaptuoti_rakta(raktas, pirmas, strlen(pirmas));
                    }

                    if (vidinis == 1) {
                        int n = sizeof(LT_RAIDYNAS) / sizeof(LT_RAIDYNAS[0]);
                        issifruoti(pirmas, raktas, n, strlen(pirmas), 1);
                        break;
                    } else if (vidinis == 2) {
                        int n = 128;
                        issifruoti(pirmas, raktas, n, strlen(pirmas), 2);
                        break;
                    }
                } else {
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