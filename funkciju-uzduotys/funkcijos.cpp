#include <iostream>
#include <string>

using namespace std;

void ProgramuSistemuInfo(string name, string args);

void kolegija() {
    cout << "Vilniaus kolegija" << endl;
}

void fakultetas() {
    cout << "Elektronikos ir informatikos fakultetas." << endl;
}

int RandomNum(int nuo, int iki) {
    int RandomInt = rand() % iki + nuo;
    return RandomInt;
}

float suma(float skc1, float skc2) {
    return skc1+skc2;
}
float skirtumas(float skc1, float skc2) {
    return skc1-skc2;
}

float sandauga(float skc1, float skc2) {
    return skc1*skc2;
}

float dalyba(float skc1, float skc2) {

    if (skc2 == 0)
        return 0;

    return skc1/skc2;
}

void palyginimas(float skc1, float skc2)
{
    if (skc1 > skc2) {
        cout << skc1;
    }
    else if(skc1 < skc2) {
        cout << skc2;
    }
    else if(skc1 == skc2)
        cout << skc1 << " ir " << skc2 << " lygus.";
}


int main() {
    ProgramuSistemuInfo("Lukas", "patiko viskas ir t.t");

    kolegija();
    fakultetas();

    cout << suma(1.2, 5) << endl;
    cout << skirtumas(2.3, 1.1) << endl;
    cout << sandauga(3.5, 2) << endl;
    cout << dalyba(1, 2) << endl;

    cout << "-----------------------" << endl;
    palyginimas(2.1, 5.5);
    cout << "" << endl;
    palyginimas(2.3, 2.3);
    cout << "" << endl;
    palyginimas(4.1, 2.4);
    cout << "" << endl;
    cout << "------------------------" << endl;


    for (int i = 1; i<10; i++) {

        cout << RandomNum(1, 5) << endl;

    }

    return 0;
}

void ProgramuSistemuInfo(string name, string args) {
    cout << name <<". " << "Pasirinkau, nes" << args << endl;
}
