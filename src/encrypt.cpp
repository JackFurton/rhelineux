#include <iostream>
#include <vector>
#include <fstream>
#include "header.h"
#include "encrypt.h"

std::string encrypt(const std::string& text, int shift) {
    std::string encryptedText = text;

    for (char &c : encryptedText) {
        if(isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
    }

    return encryptedText;
}
