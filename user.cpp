#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include "user.h"

void displayUsers(std::vector<User>& users) {
    for (const auto& user : users) {
        std::cout << "Username: " << user.username << "\nEmail: " << user.email << std::endl;
    }
}

void loadFromFile(std::vector<User>& users, int shift) {
    std::ifstream file("saved.txt");
    User temp;
    while (file >> temp.username >> temp.password >> temp.email) {
        temp.username = decrypt(temp.username, shift);
        temp.password = decrypt(temp.password, shift);
        temp.email = decrypt(temp.email, shift);
        users.push_back(temp);
    }
    file.close();
}

void saveToFile(const std::vector<User>& users, int shift) {
    std::ofstream file("saved.txt");
    for (const auto& user : users) {
    file << encrypt(user.username, shift) << " " 
         << encrypt(user.password, shift) << " " 
         << encrypt(user.email, shift) << "\n";
    }
    file.close();
}
