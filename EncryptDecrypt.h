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
        long __KEY; // symmetric key we'll use to encrypt/decrypt stuff
        string plain_text; // plaintext to be encrypted
        long cipher_text; // encrypted resulting ciphertext to be decrypted
    public:
        EncryptDecrypt(); // default constructor
        EncryptDecrypt(string PLAINTEXT); // parametrized constructor (parameter for plaintext string)
        void RSA_encrypt(); // encrypts (with RSA) "plain_text" and stores the result in "ciphertext"
        void RSA_decrypt(); // decrypts (with RSA) "cipher_text" and stores the result in "plaintext"
        // TODO: make encrypt/decrypt functions for AES, DES, and other cryptography algorithms
        void AES_encrypt(); // encrypts (with AES) "plain_text" and stores the result in "ciphertext"
        void AES_decrypt(); // decrypts (with AES) "cipher_text" and stores the result in "plaintext"
        void DES_encrypt(); // encrypts (with DES) "plain_text" and stores the result in "ciphertext"
        void DES_decrypt(); // decrypts (with DES) "cipher_text" and stores the result in "plaintext"
};


#endif //FILE_ENCRYPTION_PROJECT_ENCRYPTDECRYPT_H
