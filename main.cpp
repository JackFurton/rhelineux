#include <vector>
#include <iostream>
#include "user.h"
#include "user.cpp"

int main() {


    int shiftKey = 3;
    std::vector<User> users;
    loadFromFile(users, shiftKey);
    addUser(users);
    displayUsers(users);
    saveToFile(users, shiftKey);
    return 0;
}


