#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include "header.h"
#include "file.h"
#include "user.h"
#include "encrypt.h"
#include <stdio.h>

void loadFromFile(std::map<std::string, UserValue>& users, int shift);
void saveToFile(const std::map<std::string, UserValue>& users, int shift);

void loadFromFile(std::map<std::string, UserValue>& users, int shift) {
        std::ifstream file("saved.txt");
        std::string username, password, email;
        while (file >> username >> password >> email) {
            users.insert({decrypt(username, shift), {decrypt(password, shift), decrypt(email, shift)}});
        }
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
