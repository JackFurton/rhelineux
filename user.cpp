//-----------------------user.cpp----------------------
#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <map>
#include "header.h"

void addUser(std::map<std::string, UserValue>& users) {
    std::string username;
    UserValue value;
    std::cout << "enter Username: ";
    std::cin >> username;
    std::cout << "enter email: ";
    std::cin >> value.email;
    std::cout << "enter password: ";
    std::cin >> value.password;

    users[username] = value;
}

void displayUsers(const std::map<std::string, UserValue>& users) {
    for (const auto& pair : users) {
        std::cout << "Username: " << pair.first
                  << "\nEmail: " << pair.second.email
                  << "\nPassword: " << pair.second.password
                  << std::endl;
    }
}
