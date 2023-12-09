#include <vector>
#include <iostream>
#include <string>
#include "header.h"
#include "file.h"

int main() {
    std::map<std::string, UserValue> users;
    std::map<std::string, UserValue> decryptedUsers;
    int shift = 0;

    loadFromFile(users, shift);
    saveToFile(users, shift);

    return 0;
}