//----------------header.h-----------------------
#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <vector>
#include <map>

struct UserValue {
    std::string password;
    std::string email;
};

struct User {
    std::string username;
    UserValue value;
};


void addUser(std::map<std::string, UserValue>& users);
void displayUsers(const std::map<std::string, UserValue>& users);


void loadFromFile(std::map<std::string, UserValue>& users,int shift);
void saveToFile(const std::map<std::string, UserValue>& users, int shift);


std::string encrypt(const std::string& text, int shift);
std::string decrypt(const std::string& text, int shift);

bool retrieveUserData(const std::map<std::string, UserValue>& users, const std::string& username, UserValue& outValue);
#endif
