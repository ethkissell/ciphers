#include <iostream>
#include <algorithm>
#include <cctype>

#include "vigenere.h"
using namespace std;

void printMenu(vigenere cipher) {
    cout << "Current key: " << cipher.getKey() << endl;
    cout << "1. Generate new table" << endl;
    cout << "2. Encode" << endl;
    cout << "3. Decode" << endl;
    cout << "4. Print table" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    vigenere cipher;
    string input;
    string output;
    string menu;
    bool running = true;

    cout << "Enter key for table: ";
    getline(cin, input);
    transform(input.begin(), input.end(), input.begin(),::toupper); 
    cipher.generateTable(input);

    while (running) {
        printMenu(cipher);
        getline(cin, menu);

        if (menu == "1") { // generate new table
            cout << "Enter keyphrase: ";
            getline(cin, input);
            transform(input.begin(), input.end(), input.begin(),::toupper); 

            cipher.generateTable(input);
        }
        else if (menu == "2") { // encode
            cout << "\nEnter text to encode: ";
            getline(cin, input);
            transform(input.begin(), input.end(), input.begin(),::toupper);

            output = cipher.encode(input);
            cout << "\n " << output << " \n" << endl;
        }
        else if (menu == "3") { // decode
            cout << "\nEnter text to decode: ";
            getline(cin, input);
            transform(input.begin(), input.end(), input.begin(),::toupper);

            output = cipher.decode(input);
            cout << "\n " << output << " \n" << endl;
        }
        else if (menu == "4") { // print table
            cout << "\n-----------------------------------------------------\n";
            cipher.printTable();
            cout << "-----------------------------------------------------\n\n";
        }
        else if (menu == "5") { // exit
            running = false;
        }
        else {
            cout << "\nInvalid input.\n" << endl;
        }
    }
}