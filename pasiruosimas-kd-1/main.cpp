// 1
/*Pseudokodas – tai supaprastintas algoritmų aprašymo būdas, kuris nėra skirtas vykdyti kompiuteryje.
 *Leidzia orentuotis tik i logika, o ne pacia sintakse.
/* Pradzia,
 *  int a, n
 *  a = 8
 *  n = 5
 *  rezultatas = a(n-tuoju)
 *  spausdinti (resultatas)
 Pabaiga
 */
// 3
/* Deklaruojama #include <biblioteka>, programos virsuje.
 * Biblioteku pavyzdys: iomanip, cmath ir t.t
// 4
Bazinis žodis - tai rezervuotas zodis, kuris
turi reiksme programavimo kalboje. Pvz: int, double, string ir t.t
// 5
/* Komentarai skirti geriau suprasti kodo struktura, pasizymeti paaiskinimus
 * Komentavimo budai:
 * Vienoje eiluteje (//)
 * Keleta eiluciu (blokinis) --> /* */
// 6
/* Atspausdins skaiciu kvadratus (nuo 1 iki 10)
// 7
Klaidingi: skaiciu suma, skaiciu.suma, 1suma, 2+2suma
//  8
/* Programa grazins skaiciu 12
using namespace std;
*/

#include <iostream>
#include <string>
using namespace std;


int main()
{
     // 9 uzduotis
     int suma = 0;

     for (int i = 0; i<100; i++) {
          suma+=i;
     }

     cout << "Skaiciu suma: " << suma << endl << endl;

     // 10 uzduotis
     string skaicius;
     cout << "Iveskite norime skaiciu: ";
     cin >> skaicius;


     string pilnas_skaicius;

     for (int i = skaicius.length() - 1; i >= 0; i--) {
          pilnas_skaicius += skaicius[i];
     }

     cout << "Sukeistas " << skaicius << " yra " << pilnas_skaicius;

     // 11 uzduotis
     for (int i = 1; i<=20; i++) {

         if (i % 5 == 0) {
             cout << "-" << endl;
             continue;
         }
         else {
             cout << i << endl;
         }
     }

     // 12 uzduotis

    int kiekis, min_skaicius = 0;
    cout << "Iveskite, kiek skaiciu norite: ";
    cin >> kiekis;

    for (int i = 1; i <= kiekis; i++) {
        int skaicius;
        cout << "Iveskite skaiciu " << i << " : ";
        cin >> skaicius;

        if (i == 1) {
            min_skaicius = skaicius;
        }

        if (skaicius < min_skaicius) {
            min_skaicius = skaicius;
        }
    }

    cout << "Maziausias skaicius: " << min_skaicius << endl;

    // 14 uzduotis

    return 0;
}

// 13
/* Grazins elementa nuo 0 iki 9 su nuline reiksme.*/

// 14
/*
int rastiPazymėjimoNumerį(studentai[]) {
    for (int i = 0; i < 30; i++) {
        if (studentai[i].pavarde) {
            return studentai[i].pazmejimoNR;
        }
    }
    return 0;
}*/


