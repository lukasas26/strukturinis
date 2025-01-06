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
        cout << "\n===== Kontaktø valdymo sistema =====\n";
        cout << "1. Pridëti kontaktà\n";
        cout << "2. Perþiûrëti kontaktus\n";
        cout << "3. Redaguoti kontaktà\n";
        cout << "4. Paðalinti kontaktà\n";
        cout << "0. Iðeiti\n";
        cout << "Pasirinkite veiksmà: ";
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
                cout << "Iðeinama ið programos...\n";
                break;
            default:
                cout << "Neteisingas pasirinkimas. Bandykite dar kartà.\n";
        }
    } while (choice != 0);

    // Atlaisvinti atminti
    delete[] contacts;

    return 0;
}

void addContact(Contact*& contacts, int& size, int& nextId) {
    Contact* newContact = new Contact;
    newContact->id = nextId++;

    cout << "Áveskite vardà: ";
    getline(cin, newContact->firstName);
    cout << "Áveskite pavardæ: ";
    getline(cin, newContact->lastName);
    cout << "Áveskite telefono numerá: ";
    getline(cin, newContact->phoneNumber);
    cout << "Áveskite el. paðtà: ";
    getline(cin, newContact->email);

    Contact* newContacts = new Contact[size + 1];

    for (int i = 0; i < size; i++) {
        newContacts[i] = contacts[i];
    }


    // Pridëti naujà kontaktà
    newContacts[size] = *newContact;

    delete[] contacts;
    delete newContact;

    contacts = newContacts;
    size++;

    cout << "Kontaktas pridëtas sëkmingai!\n";
}

void viewContacts(Contact* contacts, int size) {
    if (size == 0) {
        cout << "Kontaktø sàraðas tuðèias.\n";
        return;
    }

    cout << "\n===== Kontaktø sàraðas =====\n";
    for (int i = 0; i < size; i++) {
        cout << "ID: " << contacts[i].id << "\n";
        cout << "Vardas: " << contacts[i].firstName << "\n";
        cout << "Pavardë: " << contacts[i].lastName << "\n";
        cout << "Telefonas: " << contacts[i].phoneNumber << "\n";
        cout << "El. paðtas: " << contacts[i].email << "\n";
        cout << "-----------------------------\n";
    }
}

void updateContact(Contact* contacts, int size) {
    int id;
    cout << "Áveskite kontaktà ID redagavimui: ";
    cin >> id;
    cin.ignore();

    for (int i = 0; i < size; i++) {
        if (contacts[i].id == id) {
            cout << "Redaguojamas kontaktas: \n";
            cout << "Dabartinis vardas: " << contacts[i].firstName << "\n";
            cout << "Áveskite naujà vardà (arba palikite tuðèià): ";
            string input;
            getline(cin, input);
            if (!input.empty()) contacts[i].firstName = input;

            cout << "Dabartinë pavardë: " << contacts[i].lastName << "\n";
            cout << "Áveskite naujà pavardæ (arba palikite tuðèià): ";
            getline(cin, input);
            if (!input.empty()) contacts[i].lastName = input;

            cout << "Dabartinis telefonas: " << contacts[i].phoneNumber << "\n";
            cout << "Áveskite naujà telefonà (arba palikite tuðèià): ";
            getline(cin, input);
            if (!input.empty()) contacts[i].phoneNumber = input;

            cout << "Dabartinis el. paðtas: " << contacts[i].email << "\n";
            cout << "Áveskite naujà el. paðtà (arba palikite tuðèià): ";
            getline(cin, input);
            if (!input.empty()) contacts[i].email = input;

            cout << "Kontaktas atnaujintas sëkmingai!\n";
            return;
        }
    }

    cout << "Kontaktas su ID " << id << " nerastas.\n";
}

void deleteContact(Contact*& contacts, int& size) {
    if (size == 0) {
        cout << "Kontaktø sàraðas tuðèias.\n";
        return;
    }

    int id;
    cout << "Áveskite kontaktà ID paðalinimui: ";
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

    cout << "Kontaktas paðalintas sëkmingai!\n";
}