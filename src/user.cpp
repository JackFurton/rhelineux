#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <map>
#include "header.h"
#include "user.h"
#include "encrypt.h"

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