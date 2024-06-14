#include <iostream>
#include <algorithm>
#include <cctype>

#include "./vigenere/vigenere.h"
#include "./caesar/caesar.h"

using namespace std;

void printMenuVigenere(vigenere cipher) {
    cout << "Current key: " << cipher.getKey() << endl;
    cout << "1. Generate new table" << endl;
    cout << "2. Encode" << endl;
    cout << "3. Decode" << endl;
    cout << "4. Print table" << endl;
    cout << "5. Encode by word" << endl;
    cout << "6. Decode by word" << endl;
    cout << "7. Exit" << endl;
}
bool checkInputVigenere(string input) {
    int length = input.length();
    if (length > 26) {
        cout << "Please enter a phrase less than 26 characters.\n";
        return false;
    } 
    else if (length == 0) {
        cout << "Please enter a phrase.\n";
        return false;
    }

    for (char c : input) {
        if (!isalpha(c)) {
            cout << "Please enter only alphabetic characters.\n";
            return false;
    }}

    return true;
}
void runVigenere() {
    vigenere cipher;
    string input;
    string output;
    string seed;
    string menu;
    int memory;
    bool running = true;
    bool tableGen = false;

    cout << "\n";
    while (running) {
        printMenuVigenere(cipher);
        getline(cin, menu);

        if (menu == "1") { // generate new table
            cout << "\nEnter keyphrase, will remove duplicate characters: ";
            getline(cin, input);
            if (checkInputVigenere(input)) {
                transform(input.begin(), input.end(), input.begin(),::toupper);
                cipher.generateTable(input);
                tableGen = true;
            }
            
            cout << "\n";
        }
        else if (menu == "2") { // encode
            if (tableGen) {
                cout << "\nEnter text to encode: ";
                getline(cin, input);
                transform(input.begin(), input.end(), input.begin(),::toupper);

                memory = 0;
                output = cipher.encode(input, memory);
                cout << "* " << output << " \n" << endl;
            } else {
                cout << "\nPlease generate a table.\n\n";
            }
        }
        else if (menu == "3") { // decode
            if (tableGen) {
                cout << "\nEnter text to decode: ";
                getline(cin, input);
                transform(input.begin(), input.end(), input.begin(),::toupper);

                memory = 0;
                output = cipher.decode(input, memory);
                cout << "* " << output << " \n" << endl;
            } else {
                cout << "\nPlease generate a table.\n\n";
            }
        }
        else if (menu == "4") { // print table
            if (tableGen) {
                cout << "\n-----------------------------------------------------\n";
                cipher.printTable();
                cout << "-----------------------------------------------------\n\n";
            } else {
                cout << "\nPlease generate a table.\n\n";
            }
        }
        else if (menu == "5") { // encode by word
            cout << "\nEnter seed: ";
            getline(cin, seed);
            if (seed.length() == 0) {
                cout << "Seed must contain at least one character.\n\n";
            } else {
                transform(seed.begin(), seed.end(), seed.begin(),::toupper);

                cout << "Enter text to encode: ";
                getline(cin, input);
                transform(input.begin(), input.end(), input.begin(),::toupper);

                output = cipher.byWordEncode(seed, input);
                cout << "* " << output << " \n" << endl;
                cipher.setKey(" ");
                tableGen = false;
            }
        }
        else if (menu == "6") { // decode by word
            cout << "\nEnter seed: ";
            getline(cin, seed);
            if (seed.length() == 0) {
                cout << "Seed must contain at least one character.\n\n";
            } else {
                transform(seed.begin(), seed.end(), seed.begin(),::toupper);

                cout << "Enter text to decode: ";
                getline(cin, input);
                transform(input.begin(), input.end(), input.begin(),::toupper);

                output = cipher.byWordDecode(seed, input);
                cout << "* " << output << " \n" << endl;
                cipher.setKey(" ");
                tableGen = false;
            }
        }
        else if (menu == "7") { // exit
            running = false;
            cout << "\n";
        }
        else {
            cout << "\nInvalid input.\n" << endl;
        }}
};

void printMenuCaesar(caesar cipher) {
    cout << "Current shift: " << cipher.getShift() << endl;
    cout << "1. Generate cipher" << endl;
    cout << "2. Encode" << endl;
    cout << "3. Decode" << endl;
    cout << "4. Print cipher" << endl;
    cout << "5. Encode by letter" << endl;
    cout << "6. Decode by letter" << endl;
    cout << "7. Exit" << endl;
}
void runCaesar() {
    caesar cipher;
    string input;
    string output;
    string seed;
    string menu;
    int shift;
    bool running = true;
    bool tableGen = false;

    cout << "\n";
    while (running) {
        printMenuCaesar(cipher);
        getline(cin, menu);

        if (menu == "1") { // generate new cipher
            cout << "\nEnter a number, must be between 0 and 26: ";
            cin >> shift;
            if (0 <= shift && 26 >= shift) {
                cipher.generateCipher(shift);
                tableGen = true;
            } else {
                cout << "Please enter a value between 0 and 26.\n";
            }

            cin.ignore();
            cout << "\n";
        }
        else if (menu == "2") { // encode
            if (tableGen) {
                cout << "\nEnter text to encode: ";
                getline(cin, input);
                transform(input.begin(), input.end(), input.begin(),::toupper);

                output = cipher.encode(input);
                cout << "* " << output << " \n" << endl;
            } else {
                cout << "\nPlease generate a cipher.\n\n";
            }
        }
        else if (menu == "3") { // decode
            if (tableGen) {
                cout << "\nEnter text to decode: ";
                getline(cin, input);
                transform(input.begin(), input.end(), input.begin(),::toupper);

                output = cipher.decode(input);
                cout << "* " << output << " \n" << endl;
            } else {
                cout << "\nPlease generate a cipher.\n\n";
            }
        }
        else if (menu == "4") { // print table
            if (tableGen) {
                cout << "\n-----------------------------------------------------\n";
                cipher.printCipher();
                cout << "-----------------------------------------------------\n\n";
            } else {
                cout << "\nPlease generate a cipher.\n\n";
            }
        }
        else if (menu == "5") { // encode by letter
            cout << "\nEnter seed: ";
            getline(cin, seed);
            if (seed.length() == 0) cout << "Seed must contain at least one character.\n\n";
            else {
                transform(seed.begin(), seed.end(), seed.begin(),::toupper);

                cout << "Enter text to encode: ";
                getline(cin, input);
                transform(input.begin(), input.end(), input.begin(),::toupper);

                output = cipher.byLetterEncode(seed, input);
                cout << "* " << output << " \n" << endl;
                cipher.setShift(0);
                tableGen = false;
            }
        }
        else if (menu == "6") { // decode by letter
            cout << "\nEnter seed: ";
            getline(cin, seed);
            if (seed.length() == 0) cout << "Seed must contain at least one character.\n\n";
            else {
                transform(seed.begin(), seed.end(), seed.begin(),::toupper);

                cout << "Enter text to decode: ";
                getline(cin, input);
                transform(input.begin(), input.end(), input.begin(),::toupper);

                output = cipher.byLetterDecode(seed, input);
                cout << "* " << output << " \n" << endl;
                cipher.setShift(0);
                tableGen = false;
            }
        }
        else if (menu == "7") { // exit
            running = false;
            cout << "\n";
        }
        else {
            cout << "\nInvalid input.\n" << endl;
        }}        
}

void printMainMenu() {
    cout << "1. Vigenere" << endl;
    cout << "2. Caesar" << endl;
    cout << "9. Quit" << endl;
}
int main() {
    string menu;
    bool running = true;

    while (running) {
        printMainMenu();
        getline(cin, menu);

        if (menu == "1") { // vigenere
            runVigenere();
        }
        else if (menu == "2") { // caesar
            runCaesar();
        }

        else if (menu == "9") {
            running = false;
        }
        else {
            cout << "\nInvalid input.\n" << endl;
        }}
}