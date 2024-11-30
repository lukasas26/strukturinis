#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct menuItemType {
    string menuItem;
    double menuPrice;
};

void getData(menuItemType menuList[]) {
    menuList[0] = {"Kiau�inien�", 1.45};
    menuList[1] = {"Kiaulienos �onin� su keptu kiau�iniu", 2.45};
    menuList[2] = {"Keksiukas su vy�nia", 0.99};
    menuList[3] = {"Pranc�zi�kas skrebutis", 1.99};
    menuList[4] = {"Vaisi� salotos", 2.49};
    menuList[5] = {"Pusry�i� dribsniai", 0.69};
    menuList[6] = {"Kava", 0.50};
    menuList[7] = {"Arbata", 0.75};
}

void showMenu(const menuItemType menuList[]) {
    cout << "Pasirinkite pusry�i� patiekalus i� �io meniu:" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << (i + 1) << ". " << menuList[i].menuItem << setw(6) << fixed << setprecision(2) << menuList[i].menuPrice << "�" << endl;
    }
    cout << "--------------------------------------" << endl;
    cout << "�veskite '0', kad u�baigti u�sakym�." << endl;
    cout << "--------------------------------------" << endl;
}

void printCheck(const menuItemType menuList[], int orders[]) {
    constexpr double pvm = 0.21; // 21% mokes�i� tarifas
    double subtotal = 0.0;

    ofstream failas("saskaita.txt");

    cout << "\nSveiki atvyk� � restoran� �Kaimas�\n" << endl;
    failas << "Sveiki atvyk� � restoran� �Kaimas�\n\n";

    for (int i = 0; i < 8; ++i) {
        if (orders[i] > 0) {
            double itemTotal = orders[i] * menuList[i].menuPrice;
            subtotal += itemTotal;

            cout << left << setw(34) << menuList[i].menuItem
                 << " [x" << orders[i] << "]"
                 << right << setw(13) << fixed << setprecision(2) << itemTotal << "�" << endl;

            failas << left << setw(34) << menuList[i].menuItem
                   << " [x" << orders[i] << "]"
                   << right << setw(13) << fixed << setprecision(2) << itemTotal << "�" << endl;
        }
    }

    // PVM ir bendras
    double mokesciai = subtotal * pvm;
    double total = subtotal + mokesciai;

    cout << left << setw(40) << "Mokes�iai"
         << right << setw(13) << fixed << setprecision(2) << mokesciai << "�" << endl;

    cout << left << setw(40) << "Galutin� suma"
         << right << setw(13) << fixed << setprecision(2) << total << "�" << endl;

    // Failo i�vedimas
    failas << left << setw(40) << "Mokes�iai"
           << right << setw(13) << fixed << setprecision(2) << mokesciai << "�" << endl;

    failas << left << setw(40) << "Galutin� suma"
           << right << setw(13) << fixed << setprecision(2) << total << "�" << endl;

    failas.close();
}

int main() {
    system("chcp 1257 >nul");

    menuItemType menuList[20];
    int orders[20] = {0}; // Uzsakymu masyvas (pradzioje visi 0)

    getData(menuList);

    showMenu(menuList);

    int quantity;
    int choice;

    while (true) {
        cout << "�veskite patiekalo numer�: ";
        cin >> choice;

        if (choice == 0) {
            cout << "----------------------" << endl;
            cout << "U�sakymas baigtas." << endl;
            cout << "----------------------" << endl;
            break;
        }

        if (choice < 1 || choice > 8) {
            cout << "Klaidingas pasirinkimas!" << endl;
            continue;
        }

        cout << "�veskite kiek�: ";
        cin >> quantity;
        if (quantity <= 0) {
            cout << "Kiekis turi b�ti teigiamas!" << endl;
            continue;
        }

        orders[choice - 1] += quantity;
    }

    printCheck(menuList, orders);

    cout << "\nS�skaita i�saugota faile 'saskaita.txt'!" << endl;

    return 0;
}