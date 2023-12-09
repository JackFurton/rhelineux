#include <vector>
#include <iostream>
#include <string>
#include "header.h"
#include "file.h"

int main() {
    std::map<std::string, UserValue> users;
    std::map<std::string, UserValue> decryptedUsers;
    int shift = 0;
#if DECRYPT_MODE == 0
    addUser(users);
    loadFromFile(users, shift);
    saveToFile(users, shift);
#elif DECRYPT_MODE == 1
    loadFromFile(users, shift);
#endif

    return 0;
}