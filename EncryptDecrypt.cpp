//
// Created by Saima Yunus on 12/23/23.
//

#include "EncryptDecrypt.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <numeric>
#include <cmath>

using std::cin, std::cout, std::endl, std::ifstream, std::ofstream;
using std::string;
using std::vector;

// TODO: write the encrypt/decrypt algorithms for RSA, AES, and DES. Make sure they encrypt plaintext files and decrypt resulting ciphertext correctly.

EncryptDecrypt::EncryptDecrypt() { // default constructor: initialize all values to 0/null/empty
    this->cipher_text = 0;
    this->plain_text = "";
    this->KEY = 0;
}

EncryptDecrypt::EncryptDecrypt(std::string PLAINTEXT) { // parametrized constructor: initialize 'plain_text' variable to PLAINTEXT parameter
    this->cipher_text = 0;
    this->plain_text = PLAINTEXT;
    this->KEY = 0;
}

bool EncryptDecrypt::isPrime(long N) {
    // step 1: If the given number n is less than 2, it is not prime
    if (N < 2)
        return false;
    // step 2: Iterate from 2 to (n-1) -> all the possible factors of n if n isn't prime
    for (int f = 2; f < N; f++) {
        // step 3: For each possible factor f of our num n, check if n is divisible by the factor (the current iteration value).
        if (N % f == 0)
            return false; // If it is divisible, the number is not prime.
    }
    return true; // If no divisors are found for all iterations, the number is prime.
}

bool EncryptDecrypt::isCoPrime(long N1, long N2) {
    // method: find GCD of N1 and N2 using Euclid's algorithm. If the GCD is 1, N1 and N2 are coprime.
    /*
    */
}

long EncryptDecrypt::generate_random_large_prime() {
    time_t current_time = time(NULL); // timestamp for our random number generator
    srand(current_time); // seed (using prev timestamp) for the generator
    long randomPrime = rand() % 100000000000000; // todo: make this an n-bit random number generator
    if (isPrime(randomPrime))
        return randomPrime; // if the large prime number is prime, return it
    else
        return -1; // otherwise, if the number isn't prime, return -1 as a "no match found" signal
}

void EncryptDecrypt::RSA_generate_key() {
    // generates key for RSA algorithm, stores it in EncryptDecrypt class's KEY field
    // step 1: Choose two large prime numbers, p and q.
    long p = generate_random_large_prime(), q = generate_random_large_prime();
    long N = p * q; // step 2: calculate N (product of p and q). The harder it is to factor N, the more secure our algorithm is
    long eulerTotient = (p-1) * (q-1); // step 3: find Euler's totient function, phi(n), for p and q.
    // step 4: now that we have phi(n), we need to find an int e SUCH THAT e > 1 and e < phi(n), i.e. 1 < e < phi(n). Also, e must be coprime with phi(n) - no common factors other than 1.
}
