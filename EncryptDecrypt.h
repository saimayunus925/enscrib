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
        long PUBLIC_KEY[2]; // public key we'll use to encrypt/decrypt stuff
        long PRIVATE_KEY[2]; // private key we'll use to encrypt/decrypt stuff
        long SYMMETRIC_KEY; // symmetric key we'll use to encrypt/decrypt stuff, for algorithms that only need a symmetric key
        string plain_text; // plaintext to be encrypted
        long cipher_text; // encrypted resulting ciphertext to be decrypted
        bool isPrime(long N); // checks if the long int 'n' is prime, returns true if so and false if not (used for RSA)
        long GCD(long N1, long N2); // returns the GCD of N1 and N2 using Euclid's algorithm
        bool isCoPrime(long N1, long N2); // checks if the long ints N1 and N2 are coprime, returns true if so and false if not (used for RSA)
        long generate_random_large_prime(); // randomly generates a large prime number (for the RSA algorithm)
    public:
        EncryptDecrypt(); // default constructor
        EncryptDecrypt(string PLAINTEXT); // parametrized constructor (parameter for plaintext string)
        void RSA_generate_keys(); // generates public/private keys for RSA algorithm, stores the keys in EncryptDecrypt class's "PUBLIC KEY" and "PRIVATE KEY" variables/properties
        long RSA_encrypt(); // encrypts (with RSA) "plain_text" and stores the result in "cipher_text", then returns "cipher_text" value
        string RSA_decrypt(); // decrypts (with RSA) "cipher_text" and stores the result in "plain_text", then returns "plain_text" value
        // TODO: make encrypt/decrypt functions for AES, DES, and other cryptography algorithms
};


#endif //FILE_ENCRYPTION_PROJECT_ENCRYPTDECRYPT_H
