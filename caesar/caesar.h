#ifndef CAESAR_H__
#define CAESAR_H__

class caesar {
    private:
        const char ALPHABET[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        char cipher [26];
        int shift = 0;
    public:
        void printCipher();
        void generateCipher(int n);

        std::string encode(std::string text);
        std::string decode(std::string text);

        std::string byLetterEncode(std::string key, std::string text);
        std::string byLetterDecode(std::string key, std::string text);

        int getShift();
        void setShift(int _n);
};

#endif