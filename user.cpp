//-----------------------user.cpp----------------------
#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include "header.h"

void addUser(std::vector<User>& users) {
    User newUser;
    std::cout << "enter Username: ";
    std::cin >> newUser.username;
    std::cout << "enter email: ";
    std::cin >> newUser.email;
    std::cout << "enter password: ";
    std::cin >> newUser.password;

    users.push_back(newUser);
}

void displayUsers(const std::vector<User>& users) {
    for (const auto& user : users) {
        std::cout << "Username: " << user.username << "\nEmail: " << user.email << std::endl;
    }
}
