//
// Created by Saima Yunus on 12/23/23.
//

#ifndef FILE_ENCRYPTION_PROJECT_ENCRYPTDECRYPT_H
#define FILE_ENCRYPTION_PROJECT_ENCRYPTDECRYPT_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>

using std::cin, std::cout, std::endl, std::ifstream, std::ofstream;
using std::string;
using std::vector;

class EncryptDecrypt {
    private:
        long __KEY; // key we'll use to encrypt/decrypt stuff
        string plain_text; // plaintext to be encrypted
        long cipher_text; // encrypted resulting ciphertext to be decrypted
    public:
        long RSA_encrypt(string plain_text); // encrypts (with RSA) "plain_text" and returns the int ciphertext
        string RSA_decrypt(long cipher_text); // decrypts (with RSA) "cipher_text" and returns the translated string plaintext
        // TODO: make encrypt/decrypt functions for AES, DES, and other cryptography algorithms
};


#endif //FILE_ENCRYPTION_PROJECT_ENCRYPTDECRYPT_H
