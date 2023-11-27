//------------------------file.cpp-----------------
#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include "header.h"

void loadFromFile(std::vector<User>& users, int shift) {
    std::ifstream file("saved.txt");
    User temp;
    while (file >> temp.username >> temp.password >> temp.email) {
        #ifdef DECRYPT_MODE
            temp.username = decrypt(temp.username, shift);
            temp.password = decrypt(temp.password, shift);
            temp.email = decrypt(temp.email, shift);
        #endif
        users.push_back(temp);
    }
    file.close();
}

void saveToFile(const std::vector<User>& users, int shift) {
    std::ofstream file("saved.txt");
    for (const auto& user : users) {
        #ifdef DECRYPT_MODE
            file << user.username << " " << user.password << " " << user.email << "\n";
        #else
            file << encrypt(user.username, shift) << " " 
                 << encrypt(user.password, shift) << " " 
                 << encrypt(user.email, shift) << "\n";
        #endif
        }
    file.close();
}
