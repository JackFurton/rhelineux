#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include "header.h"
#include "file.h"
#include "user.h"
#include "encrypt.h"


void loadFromFile(std::map<std::string, UserValue>& users, int shift);
void saveToFile(const std::map<std::string, UserValue>& users, int shift);

void loadFromFile(std::map<std::string, UserValue>& users, int shift) {
        std::ifstream file("saved.txt");
        if (!file) {
            std::cout << "Error opening file\n";
            return;
        }

        std::string line;
        std::istringstream iss(line); // Define the iss object
        while (std::getline(file, line)) {
            std::string encryptedKey, encryptedValue;
            if (!(iss >> encryptedKey >> encryptedValue)) {
                std::cout << "Error reading file\n";
                continue;
            }
            std::string decryptedKey = decrypt(encryptedKey, shift);
            std::string decryptedValue = decrypt(encryptedValue, shift);
            users[decryptedKey] = UserValue{decryptedValue};
        }
        file.close();
}
     

void saveToFile(const std::map<std::string, UserValue>& users, int shift) {
        std::ofstream file("saved.txt");
        if (!file.is_open()) {
            std::cout << "Error opening file\n";
            return;
        }

        for (const auto& pair : users) {
            std::string encryptionKey = encrypt(pair.first, shift); 
            std::string encryptionValue = encrypt(pair.second.password, shift); 
            file << encryptionKey << " " << encryptionValue << "\n";
        }
        file.close();
}
