#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    int pasirinkimas = 0;
    float kiekis = 0;
    float total;


    while (true) {

        float gbp_bendras = 0.8593, gbp_pirkti = 0.8450, gbp_parduoti = 0.9060;
        float usd_bendras = 1.0713, usd_pirkti = 1.0547, usd_parduoti = 1.1309;
        float inr_bendras = 88.8260, inr_pirkti = 85.2614, inr_parduoti = 92.8334;

        cout << "Pasirinkite: " << endl;
        cout << "1. Palyginti" << endl;
        cout << "2. Pirkti" << endl;
        cout << "3. Parduoti" << endl;
        cout << "Kitas skaicius - iseiti" << endl;

        cin >> pasirinkimas;

        if ((pasirinkimas != 1) && (pasirinkimas != 2) && (pasirinkimas != 3)){
            break;
        }

        switch(pasirinkimas){
            case 0: {
                break;
            }
            case 1: {

                cout << "------ Valiutos palyginimas ----" << endl;
                cout << "Iveskite, kokios valiutos norite:" << endl;

                cout << "1. GBP" << endl;
                cout << "2. USD" << endl;
                cout << "3. INR" << endl;
                cout << "Kitas skaicius - iseiti" << endl;

                cin >> pasirinkimas;

                if ((pasirinkimas != 1) && (pasirinkimas != 2) && (pasirinkimas != 3)){
                    break;
                }

                cout << "Iveskite, kiek valiutos norite (eurais):" << endl;
                cin >> kiekis;

                if(!cin.fail()) {
                    if (pasirinkimas == 1)
                    {
                        total = gbp_bendras * kiekis;

                        cout << kiekis << " EUR " << fixed << setprecision(2) << "---> " << total << " GBP" << endl;
                        break;
                    }
                    else if (pasirinkimas == 2)
                    {
                        total = usd_bendras * kiekis;

                        cout << kiekis << " EUR " << fixed << setprecision(2) << "---> " << total << " USD" << endl;
                        break;
                    }
                    else if (pasirinkimas == 3)
                    {
                        total = inr_bendras * kiekis;

                        cout << kiekis << " EUR " << fixed << setprecision(2) << "---> " << total << " INR" << endl;
                        break;
                    }

                }
                else {
                    cout << "[CIN --> Pasirinkimas] Klaida: Ivestas ne skaicius" << endl;

                    break;
                }


            }
            case 2:
            {
                cout << "------ Valiutos pirkimas ----" << endl;
                cout << "Iveskite, kokios valiutos norite:" << endl;

                cout << "1. GBP" << endl;
                cout << "2. USD" << endl;
                cout << "3. INR" << endl;
                cout << "Kitas skaicius - iseiti" << endl;

                cin >> pasirinkimas;

                if ((pasirinkimas != 1) && (pasirinkimas != 2) && (pasirinkimas != 3)){
                    break;
                }

                cout << "Iveskite, kiek valiutos norite:" << endl;
                cin >> kiekis;


                if (!cin.fail())
                {
                    if (pasirinkimas == 1)
                    {
                        total = kiekis / gbp_pirkti;

                        cout << "Jus gausite " << fixed << setprecision(2) << total << " EUR uz " << kiekis << " GBP" <<
                                endl;
                        break;
                    }
                    else if (pasirinkimas == 2)
                    {
                        total = kiekis / usd_pirkti;

                        cout << "Jus gausite " << fixed << setprecision(2) << total << " EUR uz " << kiekis << " USD" <<
                                endl;
                        break;
                    }
                    else if (pasirinkimas == 3)
                    {
                        total = kiekis / inr_pirkti;

                        cout << "Jus gausite " << fixed << setprecision(2) << total << " EUR uz " << kiekis << " INR" <<
                                endl;
                        break;
                    }

                } else {
                    cout << "[CIN] Klaida: Ivestas ne skaicius" << endl;

                    break;
                }
            }
            case 3: {
                cout << "------ Valiutos pardavimas ----" << endl;
                cout << "Iveskite, kokios valiutos norite:" << endl;

                cout << "1. GBP" << endl;
                cout << "2. USD" << endl;
                cout << "3. INR" << endl;
                cout << "Kitas skaicius - iseiti" << endl;

                cin >> pasirinkimas;

                if ((pasirinkimas != 1) && (pasirinkimas != 2) && (pasirinkimas != 3)){
                    break;
                }

                cout << "Iveskite, kiek valiutos norite:" << endl;
                cin >> kiekis;

                if (!cin.fail())
                {
                    if (pasirinkimas == 1)
                    {
                        total = kiekis/gbp_parduoti;

                        cout << "Jus gausite "<<fixed << setprecision(2) << total << " EUR uz " <<kiekis << " GBP" << endl;
                        break;
                    }
                    else if (pasirinkimas == 2)
                    {
                        total = kiekis/usd_parduoti;

                        cout << "Jus gausite "<<fixed << setprecision(2) << total << " EUR uz " <<kiekis << " USD" << endl;
                        break;
                    }
                    else if (pasirinkimas == 3) {
                        total = kiekis/inr_parduoti;

                        cout << "Jus gausite "<<fixed << setprecision(2) << total << " EUR uz " <<kiekis << " INR" << endl;
                        break;
                    }

                }
                else {
                    cout << "[CIN] Klaida: Ivestas ne skaicius" << endl;
                    break;
                }

            }
            default: {
                break;
            }



        }


    }


}