//----------------header.h-----------------------
#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <vector>

struct User {
    std::string username;
    std::string password;
    std::string email;
};


void addUser(std::vector<User>& users);
void displayUsers(const std::vector<User>& users);
void loadFromFile(std::vector<User>& users, int shift);
void saveToFile(const std::vector<User>& users, int shift);
std::string encrypt(const std::string& text, int shift);
std::string decrypt(const std::string& text, int shift);

#endif
