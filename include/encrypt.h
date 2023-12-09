#pragma once
#include <string>  
#include "/opt/homebrew/Cellar/cryptopp/8.9.0/include/cryptopp/aes.h"
#include "/opt/homebrew/Cellar/cryptopp/8.9.0/include/cryptopp/modes.h"
#include "/opt/homebrew/Cellar/cryptopp/8.9.0/include/cryptopp/filters.h"

std::string encrypt(const std::string& plainText, const CryptoPP::byte key[CryptoPP::AES::DEFAULT_KEYLENGTH], const CryptoPP::byte iv[CryptoPP::AES::BLOCKSIZE]);