#include "encrypt.h"
#include "/opt/homebrew/Cellar/cryptopp/8.9.0/include/cryptopp/aes.h"
#include "/opt/homebrew/Cellar/cryptopp/8.9.0/include/cryptopp/modes.h"
#include "/opt/homebrew/Cellar/cryptopp/8.9.0/include/cryptopp/filters.h"

std::string encrypt(const std::string& plainText, const CryptoPP::byte key[CryptoPP::AES::DEFAULT_KEYLENGTH], const CryptoPP::byte iv[CryptoPP::AES::BLOCKSIZE]) {
    std::string cipherText;

    CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);

    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(cipherText));
    stfEncryptor.Put(reinterpret_cast<const unsigned char*>(plainText.c_str()), plainText.length() + 1);
    stfEncryptor.MessageEnd();

    return cipherText;
}