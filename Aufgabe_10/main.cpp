#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

const size_t buffer_len = 10;
int buffer[buffer_len];
int n = 0;

bool valid_menu_input(char input) {
    return input == 'i' || input == 'I' || input == 's' || input == 'S' || input == 'o' || input == 'O' || input == 'd' || input == 'D' || input == 'q' || input == 'Q';
}

// reads an integer and puts it at the end of the array
void add_at_end() {
    // clear console on windows
    system("cls");

    // if buffer id full
    if(n >= buffer_len) {
        cout << "Fehler: Der Speicher ist voll.\n" << endl;
        return;
    }

    // read number from user
    int new_number;
    while(true) {
        // print menu
        cout << "Welche Zahl möchtest du hinzufügen? -> ";

        // read input
        cin >> new_number;

        // test for error
        if(cin.fail()) {
            // reset cin errors
            cin.clear();

            // ignore chars until line break
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "ungültige Eingabe" << endl;
        }
        else {
            break;
        }
    }

    // add number to buffer
    buffer[n] = new_number;
    n++;

    // clear console
    system("cls");

    cout << "Erfolgreich gespeichert.\n" << endl;
}

// print how many fields are used
void print_used_fields() {
    // clear console on windows
    system("cls");

    cout << "Es sind momentan " << n << " Einträge gespeichert.\n" << endl;
}

// prints all used fields
void print_fieldls() {
    // clear console on windows
    system("cls");

    if(n == 0) {
        cout << "Speicher ist leer.\n" << endl;
        return;
    }

    for(int i = 0; i < n; i++) {
        cout << setw(2) << i+1 << ": " << buffer[i] << endl;
    }
    cout << endl;
}

// delete first element of buffer
void delete_element() {
    // clear conosle on windows
    system("cls");

    if(n == 0) {
        cout << "Fehler: Der Speicher ist leer.\n" << endl;
        return;
    }

    // move all elements to left
    for(int i = 1; i < buffer_len; i++) {
        buffer[i-1] = buffer[i];
    }

    // decrease element count by one
    n -= 1;

    cout << "Erstes Element erfolgreich gelöscht.\n" << endl;
}

int main()
{
    // set utf-8 encoding for windows cmd and clear screen
    system("chcp 65001 & cls");

    // welcome user
    cout << "Herzlich willkommen!\n" << endl;

    // main loop
    while(true) {
        // -------- user input --------
        char input;

        // read user input
        while(true) {
            // print menu
            cout << "Hauptmenü:" << endl;
            cout << "i: Wert einfügen" << endl;
            cout << "s: Gib Anzahl belegte Felder" << endl;
            cout << "o: Drucke belegte Felder" << endl;
            cout << "d: Lösche erstes Element" << endl;
            cout << "q: Beenden" << endl;

            // read input
            cin >> input;

            // test for error
            if(cin.fail() || !valid_menu_input(input)) {
                // reset cin errors
                cin.clear();

                // ignore chars until line break
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                // clear console on windows
                system("cls");

                cout << "ungültige Eingabe\n" << endl;
            }
            else {
                break;
            }
        }

        // valid user input
        // -------- menu ochestration --------
        switch(input) {
            case 'i':
            case 'I':
                add_at_end();
                break;

            case 's':
            case 'S':
                print_used_fields();
                break;

            case 'o':
            case 'O':
                print_fieldls();
                break;

            case 'd':
            case 'D':
                delete_element();
                break;

            case 'q':
            case 'Q':
                return 0;
        }
    }

    return 0;
}
