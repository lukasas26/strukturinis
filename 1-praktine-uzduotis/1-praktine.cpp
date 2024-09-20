#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{

    int pasirinkimas = 0;

    float gbp_bendras = 0.8593, gbp_pirkti = 0.8450, gbp_parduoti = 0.9060;
    float usd_bendras = 1.0713, usd_pirkti = 1.0547, usd_parduoti = 1.1309;
    float inr_bendras = 88.8260, inr_pirkti = 85.2614, inr_parduoti = 92.8334;


    while (true) {

        cout << "Pasirinkite: " << endl;
        cout << "1. Palyginti" << endl;
        cout << "2. Pirkti" << endl;
        cout << "3. Parduoti" << endl;

        cin >> pasirinkimas;


        switch(pasirinkimas){
            case 1: {

                cout << "----- Valiutu kursai --------" << endl;
                cout << "1 EUR - " << fixed << setprecision(2) << gbp_bendras <<  " GBP" << endl;
                cout << "1 EUR - " << fixed << setprecision(2) << usd_bendras << " USD" <<  endl;
                cout << "1 EUR - " << fixed << setprecision(2) << inr_bendras << " INR" << endl << endl;
                break;


            }
            default:
                break;


        }

    }


}