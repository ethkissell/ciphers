#include <iostream>
#include <algorithm>
#include <cctype>

#include "./vigenere/vigenere.h"
using namespace std;

void printMenu(vigenere cipher) {
    cout << "Current key: " << cipher.getKey() << endl;
    cout << "1. Generate new table" << endl;
    cout << "2. Encode" << endl;
    cout << "3. Decode" << endl;
    cout << "4. Print table" << endl;
    cout << "5. Encode by word" << endl;
    cout << "6. Decode by word" << endl;
    cout << "7. Exit" << endl;
}

bool checkInput(string input) {
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

int main() {
    vigenere cipher;
    string input;
    string output;
    string seed;
    string menu;
    int memory;
    bool running = true;
    bool tableGen = false;

    while (running) {
        printMenu(cipher);
        getline(cin, menu);

        if (menu == "1") { // generate new table
            cout << "\nEnter keyphrase, will remove duplicate characters: ";
            getline(cin, input);
            if (checkInput(input)) {
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
            transform(seed.begin(), seed.end(), seed.begin(),::toupper);

            cout << "Enter text to encode: ";
            getline(cin, input);
            transform(input.begin(), input.end(), input.begin(),::toupper);

            output = cipher.byWordEncode(seed, input);
            cout << "* " << output << " \n" << endl;
            cipher.setKey(" ");
            tableGen = false;
        }
        else if (menu == "6") { // decode by word
            cout << "\nEnter seed: ";
            getline(cin, seed);
            transform(seed.begin(), seed.end(), seed.begin(),::toupper);

            cout << "Enter text to decode: ";
            getline(cin, input);
            transform(input.begin(), input.end(), input.begin(),::toupper);

            output = cipher.byWordDecode(seed, input);
            cout << "* " << output << " \n" << endl;
            cipher.setKey(" ");
            tableGen = false;
        }
        else if (menu == "7") { // exit
            running = false;
            cout << "\n";
        }
        else {
            cout << "\nInvalid input.\n" << endl;
        }}
}