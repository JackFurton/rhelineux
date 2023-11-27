//------------------------main.cpp--------------------
#include <vector>
#include <iostream>
#include <string>
#include "header.h"

int main(int argc, char* argv[]){
    int shiftKey = 3;
    std::map<std::string, UserValue> users;

    loadFromFile(users, shiftKey);

    if (argc > 1 && std::string(argv[1]) == "--find") {
        std::string username;
        std::cout << "Enter username to retrieve data: ";
        std::cin >> username;
        UserValue value;
        if(retrieveUserData(users, username, value)) {
            std::cout << "Email: " << value.email << "\nPassword: " << value.password <<std::endl;
        } else {
            std::cout << "User not found." << std::endl;
        }
    }

    #ifdef DECRYPT_MODE
        std::cout << "Running in decrypt mode" << std::endl;
        loadFromFile(users, shiftKey);
        displayUsers(users);
    #else
        std::cout << "Running in encryption mode" << std::endl;
        addUser(users);
        saveToFile(users, shiftKey);
    #endif
    return 0;
}
