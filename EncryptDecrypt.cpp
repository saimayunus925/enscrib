//
// Created by Saima Yunus on 12/23/23.
//

#include "EncryptDecrypt.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>

using std::cin, std::cout, std::endl, std::ifstream, std::ofstream;
using std::string;
using std::vector;

// TODO: write the encrypt/decrypt algorithms for RSA, AES, and DES. Make sure they encrypt plaintext files and decrypt resulting ciphertext correctly.

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

long EncryptDecrypt::generate_random_large_prime() {
    time_t current_time = time(NULL); // timestamp for our random number generator
    srand(current_time); // seed (using prev timestamp) for the generator
    long randomPrime = rand() % 100000000000000; // todo: make this an n-bit random number generator
    if (isPrime(randomPrime))
        return randomPrime; // if the large prime number is prime, return it
    else
        return -1; // otherwise, if the number isn't prime, return -1 as a "no match found" signal
}
