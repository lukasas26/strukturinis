#include <iostream>
#include <string>

using namespace std;

int main()
{

    cout << "----- 4 uzduotis ------";
    int a, b;
    float c;
    a = 13, b = 5, c = 17.5;

    cout << static_cast<double>(a + b) - c << endl;
    cout << 15 / 2 + c << endl;
    cout << a / static_cast<double>(b) + 2 * c << endl;
    cout << 14 % 3 + 6.3 + static_cast<double>(b) / a << endl;
    cout << static_cast<int>(c) % 5 + a - b << endl;
    cout << 13.5 / 2 + 4.0 * 3.5 + 18 << endl;


    cout << "------- 5 uzduotis -------";
    double aa, bb, cc, dd, ee;
    cout << "Iveskite 5 skaicius atskiriant tarpu: (1, 2,3,4,5): " << endl;
    cin >> aa >> bb >> cc >> dd >> ee;

    float vidurkis;
    vidurkis = (aa + bb + cc + dd + ee)/5;
    cout << "Vidurkis:"; cout << vidurkis;
    


    return 0;
}