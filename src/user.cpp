#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <map>
#include "header.h"
#include "user.h"

void addUser(std::map<std::string, UserValue>& users) {
    std::string username;
    char addMore = 'y';
    int shift = 3;

    do { // the lords loop
        UserValue value;
        std::cout << "enter Username: ";
        std::cin >> username;
        std::cout << "enter email: ";
        std::cin >> value.email;
        std::cout << "enter password: ";
        std::cin >> value.password;

        std::string encryptionUsername = encrypt(username, shift);
        std::string encryptionPassword = encrypt(value.password, shift);

        users[encryptionUsername] = {encryptionPassword, value.email}; // insert into map 

        std::cout << "add another user? (y/n): ";
        std::cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');
}

bool retrieveUserData(const std::map<std::string, UserValue>& users, const std::string& username, UserValue& outValue) {
    auto it = users.find(username);
    if (it != users.end()) {
        outValue = it->second;
        return true;
    }
    return false;
}

void displayUsers(const std::map<std::string, UserValue>& users) {
    for (const auto& pair : users) {
        std::cout << "Username: " << pair.first
                  << "\nEmail: " << pair.second.email
                  << "\nPassword: " << pair.second.password
                  << std::endl;
    }
}
