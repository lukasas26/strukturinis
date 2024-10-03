#include <iostream>

using namespace std;

int KvadratoSuskaiciuotiPerimetra(float krastine) {
    return 4*krastine;
}

void suskaiciuotiPlota(int krastine, int& plotas) {
    plotas = krastine * krastine;
}

double celsiusToFahrenheit(double tempCelcius) {
    tempCelcius = ((tempCelcius*1.8)+32);
    return tempCelcius;

}

void fahrenheitToCelsius(double tempFahrenheit, double& tempCelsius) {
    tempCelsius = (tempFahrenheit - 32) * 5.0 / 9.0;
}

int main() {

    int krastine;
    int plotas;

    cout << "Iveskite kvadrato krastine: ";
    cin >> krastine;

    suskaiciuotiPlota(krastine, plotas);

    cout << "Kvadrato plotas: " << plotas << endl;

    cout << celsiusToFahrenheit(25) << endl;

    double tempFahrenheit;
    double tempCelsius;

    cout << "Iveskite temperatura Farenheite: ";
    cin >> tempFahrenheit;

    fahrenheitToCelsius(tempFahrenheit, tempCelsius);

    cout << tempFahrenheit << " F yra " << tempCelsius << " C." << endl;

    return 0;
}