#include <iostream>
#include <string>

using namespace std;

int main() {

    string vardas, pavarde, grupe, s_programa;
    int amzius, kursas;
    cout << "----- Pirma uzduotis -------" << endl;

    cout << "Iveskite varda: " << endl;
    cin >> vardas;
    cout << "Iveskite pavarde: " << endl;
    cin >> pavarde;
    cout << "Iveskite amziu: " << endl;
    cin >> amzius;
    cout << "Iveskite grupe: " << endl;
    cin >> grupe;
    cout << "Iveskite kursa: " << endl;
    cin >> kursas;
    cout << "Iveskite studiju programa: " << endl;
    cin >> s_programa;

    cout << "Jusu duomenys:\n";
    cout << "Vardas: "; cout << vardas << endl;
    cout << "Pavarde: "; cout << pavarde << endl;
    cout << "Amzius: "; cout << amzius << endl;
    cout << "Grupe: "; cout << grupe << endl;
    cout << "Kursas: "; cout << kursas << endl;
    cout << "Studiju programa: "; cout << s_programa << endl;

    cout << "------ Antra uzduotis ------" << endl;
    string klubas, savininkas, a_s;
    int metai, vietos;

    cout << "Iveskite klubo pavadinima: " << endl;
    cin >> klubas;
    cout << "Iveskite metus: " << endl;
    cin >> metai;
    cout << "Iveskite savininka: " << endl;
    cin >> savininkas;
    cout << "Arena / stadionas: " << endl;
    cin >> a_s;
    cout << "Iveskite vietu skaiciu: " << endl;
    cin >> vietos;

    cout << "Jusu duomenys:\n";
    cout << "Klubas: "; cout << klubas << endl;
    cout << "Metai: "; cout << metai << endl;
    cout << "Savininkas: "; cout << savininkas << endl;
    cout << "Arena / Stadionas: "; cout << a_s << endl;
    cout << "Vietos: "; cout << vietos << endl;

    cout << "------ Trecia uzduotis ------" << endl;
    string marke, modelis, spalva;
    int pag_metai;
    float litrazas;

    cout << "Iveskite duomenis atskirtus tarpais"
            " (marke, modelis, metai, litrazas, spalva): " << endl;
    cin >> marke >> modelis >> pag_metai >> litrazas >> spalva;
    cout << "Automobilis "; cout  << marke; cout << " yra pagamintas "; cout << pag_metai;
    cout << pag_metai; cout << " metais. Jo motoras "; cout << litrazas; cout << " litrazo. Automobilis yra ";
    cout << spalva; cout << " spalvos.";


    return 0;
}
