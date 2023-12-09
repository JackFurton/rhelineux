#include <iostream>
#include <vector>
#include <fstream>
#include "decrypt.h"

std::string decrypt(const std::string& text, int shift) {
    return encrypt(text, 26 - shift);
}
