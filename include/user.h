#pragma once
#ifndef USER_H
#define USER_H

#include <map>
#include <string> 

struct UserValue;

void addUser(std::map<std::string, UserValue>& users);
void displayUsers(const std::map<std::string, UserValue>& users);

#endif