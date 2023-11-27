//------------------------file.cpp-----------------
#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
#include <fstream>
#include "header.h"

void loadFromFile(std::map<std::string, UserValue>& users, int shift) {
    std::ifstream file("saved.txt");
    std::string username, password, email;
    while (file >> username >> password >> email) {
        #ifdef DECRYPT_MODE
            username = decrypt(username, shift);
            password = decrypt(password, shift);
            email = decrypt(email, shift);
        #endif
        users[username] = {password, email};
    }
    file.close();
}

void saveToFile(const std::map<std::string, UserValue>& users, int shift) {
    std::ofstream file("saved.txt");
    for (const auto& pair : users) {
        std::string encryptedUsername = encrypt(pair.first, shift);
        std::string encryptedPassword = encrypt(pair.second.password, shift);
        std::string encryptedEmail = encrypt(pair.second.email, shift);

        file << encryptedUsername << " "
             << encryptedPassword << " "
             << encryptedEmail << "\n";
        }
    file.close();
}
