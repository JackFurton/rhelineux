#pragma once
#ifndef FILE_H
#define FILE_H
#include <vector>
#include <map>
#include <iostream>
#include <string>

void loadFromFile(std::map<std::string, UserValue>& users, int shift);
void saveToFile(const std::map<std::string, UserValue>& users, int shift);

#endif