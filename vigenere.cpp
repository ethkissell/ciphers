#include <iostream>

#include "vigenere.h"

// setup tables for logic using comparisons with unused signs to be replaced with characters
void warmAlphabet (char arr[26]) {
    for (int i = 0; i < 26; i++)
        arr[i] = '+';
}
void warmTable (char table[28][27]) {
    for (int i = 0; i < 28; i++) {
        for (int ii = 0; ii < 27; ii++) {
            table[i][ii] = '-';
    }}
}

void vigenere::printTable() {
    for (int i = 0; i < 28; i++) {
        for (int ii = 0; ii < 27; ii++) {
            std::cout << table[i][ii] << " ";
            if (ii == 26)
                std::cout << "\n";
    }}
}
std::string vigenere::getKey() {
    return internalKey;
}

void vigenere::generateTable(std::string key) {
    warmTable(table);
    internalKey = key;

    // add top and bottom alphabets for reference
    for (int i = 0; i < 27; i++) {
        if (i == 0 || i == 28) {
            table[0][i] = ' ';
            table[27][i] = ' ';
        } else {
            table[0][i] = ALPHABET[i - 1];
            table[27][i] = ALPHABET[i - 1];
    }}

    // add sidebar
    for (int i = 1; i < 27; i++) {
        table[i][0] = ALPHABET[i - 1];
    }

    // setup temporary alphabet to be pulled from when generating the cipher table
    char tempAlphabet[26];
    for (int i = 0; i < 26; i++)
        tempAlphabet[i] = ALPHABET[i];

    // generating cipher from key
    char cipherString[26];
    warmAlphabet(cipherString);
    int keySize = internalKey.length();
    int index; // save index for placing alphabet in order after key is inserted into cipher text

    // take out key from aphabet and replace used characters with '-' removing them from letter pool
    for (int i = 0; i < keySize; i++) {
        cipherString[i] = internalKey[i];
        for (int ii = 0; ii < 26; ii++) {
            if (tempAlphabet[ii] == internalKey[i]) {
                tempAlphabet[ii] = '-';
                break;
        }}
        index = i + 1;
    }
    // populate the rest of the cipher string for input into table
    for (int i = 0; i < 26; i++) {
        if (tempAlphabet[i] != '-' && cipherString[index] == '+') {
            cipherString[index] = tempAlphabet[i];
            tempAlphabet[i] = '-';
            index++;
    }}

    // populating table from generated cipher string
    char temp;
    for (int i = 1; i < 27; i++) {
        for (int ii = 1; ii < 27; ii++) {
            table[i][ii] = cipherString[ii - 1];
        }

        // shifting cipher text one to the left and pushing first char to end
        temp = cipherString[0]; 
        for (int ii = 0; ii < 26; ii++) {
            cipherString[ii] = cipherString[ii + 1];
        }
        cipherString[25] = temp;
    }
}

std::string vigenere::encode(std::string text) {
    int textSize = text.length();
    int keySize = internalKey.length();
    int keyIndex = 0;
    int col;
    int row;
    std::string result = "";
    
    // begin encoding
    for (int i = 0; i < textSize; i++) {
        // if text is longer than key return to start of key
        if (keyIndex >= keySize)
            keyIndex = 0;

        // add special characters
        if (text[i] == ' ' || text[i] == '.' || text[i] == ',' || text[i] == '?' || text[i] == '!' || text[i] == '\'') result += text[i];
        else {
            // get column using key
            for (int ii = 1; ii < 27; ii++) {
                if (table[0][ii] == internalKey[keyIndex]) {
                    col = ii;
                    break;
            }}

            // get row using text
            for (int iii = 1; iii < 27; iii++) {
                if (table[iii][0] == text[i]) {
                    row = iii;
                    break;
            }}

            // print encoded letter
            // cout << table[row][col] << endl;

            // append encoded letter to result and shift along key
            result += table[row][col];
            keyIndex++;
    }}
    
    return result;
}
std::string vigenere::decode(std::string text) {
    int textSize = text.length();
    int keySize = internalKey.length();
    int keyIndex = 0;
    int col;
    int row;
    std::string result;

    // begin decoding
    for (int i = 0; i < textSize; i++) {
        // if text is longer than key return to start of key
        if (keyIndex >= keySize)
            keyIndex = 0;

        // add special characters
        if (text[i] == ' ' || text[i] == '.' || text[i] == ',' || text[i] == '?' || text[i] == '!' || text[i] == '\'') result += text[i];
        else {
            // get row from key
            for (int ii = 1; ii < 27; ii++) {
                // cout << ii << ": " << table[ii][0] << " : " << key[keyIndex] << endl;
                if (table[ii][0] == internalKey[keyIndex]) {
                    row = ii;
                    break;
            }}

            // get column from text from row
            for (int iii = 1; iii < 27; iii++) {
                // cout << iii << ": " << table[row][iii] << endl;
                if (table[row][iii] == text[i]) {
                    col = iii;
                    break;
            }}

            // get deciphered letter from topbar using column
            result += table[0][col];
            keyIndex++;
    }}
    
    return result;
}