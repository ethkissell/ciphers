#include <iostream>
#include <cstdlib>

#include "../caesar/caesar.h"

void warmCipher(char arr[26]) {
    for (int i = 0; i < 26; i++) {
        arr[i] = '+';
    }
}

void caesar::printCipher() {
    std::cout << "* ";
    for (int i = 0; i < 26; i++) {
        std::cout << ALPHABET[i] << " ";
    }
    std::cout << "\n* ";
    for (int i = 0; i < 26; i++) {
        std::cout << cipher[i] << " ";
    }
    std::cout << "\n";
}

int caesar::getShift() {
    return shift;
}
void caesar::setShift(int _n) {
    shift = _n;
}

void caesar::generateCipher(int n) {
    warmCipher(cipher);
    shift = n;

    for (int i = 0; i < 26; i++) {
        if (n >= 26) n = 0;
        cipher[i] = ALPHABET[n];
        n++;
    }
}

std::string caesar::encode(std::string text) {
    std::string result = "";
    int size = text.length();
    int index;

    for (int i = 0; i < size; i++) {
        if (!isalpha(text[i])) result += text[i];
        else {
            for (int ii = 0; ii < 26; ii++) {
                if (text[i] == ALPHABET[ii]) {
                result += cipher[ii];
    }}}}

    return result;
}
std::string caesar::decode(std::string text) {
    std::string result = "";
    int size = text.length();
    int index;

    for (int i = 0; i < size; i++) {
        if (!isalpha(text[i])) result += text[i];
        else {
            for (int ii = 0; ii < 26; ii++) {
                if (text[i] == cipher[ii]) {
                result += ALPHABET[ii];
    }}}}

    return result;
}

unsigned int generateSeedCaesar(std::string key) {
    unsigned int seed = 0;
    int size = key.length();

    for (int i = 0; i < size; i++) seed += key[i];
    seed = seed * size;

    return seed;
}

std::string caesar::byLetterEncode(std::string startSeed, std::string text) {
    std::string result = "";
    int size = text.length();
    unsigned int seed = generateSeedCaesar(startSeed);
    srand(seed);

    generateCipher(rand() % 26);

    for (int i = 0; i < size; i++) {
        if (isalpha(text[i])) {
            result += encode(std::string(1, text[i]));
            generateCipher(rand() % 26);
        } else result += text[i];
    }

    return result;
}
std::string caesar::byLetterDecode(std::string startSeed, std::string text) {
    std::string result = "";
    int size = text.length();
    unsigned int seed = generateSeedCaesar(startSeed);
    srand(seed);

    generateCipher(rand() % 26);

    for (int i = 0; i < size; i++) {
        if (isalpha(text[i])) {
            result += decode(std::string(1, text[i]));
            generateCipher(rand() % 26);
        } else result += text[i];
    }

    return result;
}