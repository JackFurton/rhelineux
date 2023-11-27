//------------------------main.cpp--------------------
#include <vector>
#include <iostream>
#include <string>
#include "header.h"

int main(){
    int shiftKey = 3;
    std::map<std::string, UserValue> users;

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
