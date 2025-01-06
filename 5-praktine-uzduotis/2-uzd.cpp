#include <iostream>
#include <string>

using namespace std;

struct Contact {
    int id;
    string firstName;
    string lastName;
    string phoneNumber;
    string email;
};

void addContact(Contact*& contacts, int& size, int& nextId);
void viewContacts(Contact* contacts, int size);
void updateContact(Contact* contacts, int size);
void deleteContact(Contact*& contacts, int& size);

int main() {
    system("chcp 1257 > null");

    Contact* contacts = nullptr;
    int size = 0;
    int nextId = 1; // Unikalus ID kiekvienam kontaktui
    int choice;

    do {
        cout << "\n===== Kontakt� valdymo sistema =====\n";
        cout << "1. Prid�ti kontakt�\n";
        cout << "2. Per�i�r�ti kontaktus\n";
        cout << "3. Redaguoti kontakt�\n";
        cout << "4. Pa�alinti kontakt�\n";
        cout << "0. I�eiti\n";
        cout << "Pasirinkite veiksm�: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {
            case 1:
                addContact(contacts, size, nextId);
                break;
            case 2:
                viewContacts(contacts, size);
                break;
            case 3:
                updateContact(contacts, size);
                break;
            case 4:
                deleteContact(contacts, size);
                break;
            case 0:
                cout << "I�einama i� programos...\n";
                break;
            default:
                cout << "Neteisingas pasirinkimas. Bandykite dar kart�.\n";
        }
    } while (choice != 0);

    // Atlaisvinti atminti
    delete[] contacts;

    return 0;
}

void addContact(Contact*& contacts, int& size, int& nextId) {
    Contact* newContact = new Contact;
    newContact->id = nextId++;

    cout << "�veskite vard�: ";
    getline(cin, newContact->firstName);
    cout << "�veskite pavard�: ";
    getline(cin, newContact->lastName);
    cout << "�veskite telefono numer�: ";
    getline(cin, newContact->phoneNumber);
    cout << "�veskite el. pa�t�: ";
    getline(cin, newContact->email);

    Contact* newContacts = new Contact[size + 1];

    for (int i = 0; i < size; i++) {
        newContacts[i] = contacts[i];
    }


    // Prid�ti nauj� kontakt�
    newContacts[size] = *newContact;

    delete[] contacts;
    delete newContact;

    contacts = newContacts;
    size++;

    cout << "Kontaktas prid�tas s�kmingai!\n";
}

void viewContacts(Contact* contacts, int size) {
    if (size == 0) {
        cout << "Kontakt� s�ra�as tu��ias.\n";
        return;
    }

    cout << "\n===== Kontakt� s�ra�as =====\n";
    for (int i = 0; i < size; i++) {
        cout << "ID: " << contacts[i].id << "\n";
        cout << "Vardas: " << contacts[i].firstName << "\n";
        cout << "Pavard�: " << contacts[i].lastName << "\n";
        cout << "Telefonas: " << contacts[i].phoneNumber << "\n";
        cout << "El. pa�tas: " << contacts[i].email << "\n";
        cout << "-----------------------------\n";
    }
}

void updateContact(Contact* contacts, int size) {
    int id;
    cout << "�veskite kontakt� ID redagavimui: ";
    cin >> id;
    cin.ignore();

    for (int i = 0; i < size; i++) {
        if (contacts[i].id == id) {
            cout << "Redaguojamas kontaktas: \n";
            cout << "Dabartinis vardas: " << contacts[i].firstName << "\n";
            cout << "�veskite nauj� vard� (arba palikite tu��i�): ";
            string input;
            getline(cin, input);
            if (!input.empty()) contacts[i].firstName = input;

            cout << "Dabartin� pavard�: " << contacts[i].lastName << "\n";
            cout << "�veskite nauj� pavard� (arba palikite tu��i�): ";
            getline(cin, input);
            if (!input.empty()) contacts[i].lastName = input;

            cout << "Dabartinis telefonas: " << contacts[i].phoneNumber << "\n";
            cout << "�veskite nauj� telefon� (arba palikite tu��i�): ";
            getline(cin, input);
            if (!input.empty()) contacts[i].phoneNumber = input;

            cout << "Dabartinis el. pa�tas: " << contacts[i].email << "\n";
            cout << "�veskite nauj� el. pa�t� (arba palikite tu��i�): ";
            getline(cin, input);
            if (!input.empty()) contacts[i].email = input;

            cout << "Kontaktas atnaujintas s�kmingai!\n";
            return;
        }
    }

    cout << "Kontaktas su ID " << id << " nerastas.\n";
}

void deleteContact(Contact*& contacts, int& size) {
    if (size == 0) {
        cout << "Kontakt� s�ra�as tu��ias.\n";
        return;
    }

    int id;
    cout << "�veskite kontakt� ID pa�alinimui: ";
    cin >> id;

    int indexToDelete = -1;
    for (int i = 0; i < size; i++) {
        if (contacts[i].id == id) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete == -1) {
        cout << "Kontaktas su ID " << id << " nerastas.\n";
        return;
    }

    Contact* newContacts = new Contact[size - 1];

    for (int i = 0, j = 0; i < size; i++) {
        if (i != indexToDelete) {
            newContacts[j++] = contacts[i];
        }
    }

    delete[] contacts;
    contacts = newContacts;
    size--;

    cout << "Kontaktas pa�alintas s�kmingai!\n";
}