#ifndef VIGENERE_H__
#define VIGENERE_H__

class vigenere {
    private:
        const char ALPHABET[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        char table[28][27];
        std::string keyPool[100];
        std::string internalKey;
    public:
        vigenere();

        void printTable();
        void generateTable(std::string key);
        
        std::string encode(std::string text, int& memory);
        std::string decode(std::string text, int& memory);

        std::string byWordEncode(std::string key, std::string text);
        std::string byWordDecode(std::string key, std::string text);

        std::string getKey();
        void setKey(std::string _key);
};

#endif