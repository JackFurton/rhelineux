#include <iostream>
#include <vector>
#include <fstream>
#include "user.h"

//encryption function
std::string encryption(const std::string& text, int shift) {
    std::string encryptedText = text;

    for (char &c : encryptedText) {
        if(isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
    }

    return encryptedText;
}

//decryption function
std::string decryption(const std::string& text, int shift) {
    return encryption(text, 26 - shift);
}
