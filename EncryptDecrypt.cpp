//
// Created by Saima Yunus on 12/23/23.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "EncryptDecrypt.h"

using namespace std;

// TODO: write the encrypt/decrypt algorithms for RSA, AES, and DES. Make sure they encrypt plaintext files and decrypt resulting ciphertext correctly.

EncryptDecrypt::EncryptDecrypt() { // default constructor: initialize all values to 0/null/empty
    this->cipher_text = 0;
    this->plain_text = "";
    this->SYMMETRIC_KEY = 0;
}

EncryptDecrypt::EncryptDecrypt(string PLAINTEXT) { // parametrized constructor: initialize 'plain_text' variable to PLAINTEXT parameter
    this->cipher_text = 0;
    this->plain_text = PLAINTEXT;
    this->SYMMETRIC_KEY = 0;
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

long EncryptDecrypt::GCD(long N1, long N2) {
    /*
    Euclidean Algorithm for GCD(N1, N2):
     * N1 = 0: GCD(N1, N2) = N2, b/c GCD(0, N2) = N2. Then check if N2 = 1, return true or false accordingly.
     * N2 = 0: GCD(N1, N2) = N1, b/c GCD(N1, 0) = N1. Then check if N1 = 1, return true or false accordingly.
     * otherwise, write N1 in quotient form: N1 = (N2 * Q) + R
     * basically, get R (remainder) of N1/N2 with modulus operator, then find GCD(N2, R) since GCD(N1, N2) == GCD(N2, R)
     * base case: N1 = 0 or N2 = 0
     * recursive case: divide N1 and N2 and get remainder, call GCD on N2 and remainder
    SOURCE: https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/the-euclidean-algorithm
    */
    if (N1 == 0 || N2 == 0) { // BASE CASES
        if (N1 == 0) // N1 = 0: GCD(N1, N2) = N2, b/c GCD(0, N2) = N2
            return N2;
        else if (N2 == 0) // N2 = 0: GCD(N1, N2) = N1, b/c GCD(N1, 0) = N1
            return N1;
    }
    // RECURSIVE CASE: divide N1 and N2 and get remainder, call GCD on N2 and remainder
    long R = N1 % N2; // R: remainder of N1/N2
    return GCD(N2, R); // find GCD of N2 and R (remainder)
}

bool EncryptDecrypt::isCoPrime(long N1, long N2) {
    // method: find GCD of N1 and N2 using Euclid's algorithm. If the GCD is 1, N1 and N2 are coprime.
    bool RESULT = (this->GCD(N1, N2) == 1) ? true : false; // if GCD of N1 and N2 is 1, RESULT is true. Else, it's false.
    return RESULT;
}

long EncryptDecrypt::generate_random_large_prime() {
    time_t current_time = time(nullptr); // timestamp for our random number generator
    srand(current_time); // seed (using prev timestamp) for the generator
    long randomPrime = rand() % 100000000000000; // todo: make this an n-bit random number generator
    if (isPrime(randomPrime))
        return randomPrime; // if the large prime number is prime, return it
    else
        return -1; // otherwise, if the number isn't prime, return -1 as a "no match found" signal
}

void EncryptDecrypt::RSA_generate_key() {
    time_t current_time = time(nullptr); // timestamp for our random number generator
    srand(current_time); // seed (using prev timestamp) for the generator
    // generates key for RSA algorithm, stores it in EncryptDecrypt class's KEY field
    // step 1: Choose two large prime numbers, p and q.
    long p = generate_random_large_prime(), q = generate_random_large_prime();
    long N = p * q; // step 2: calculate N (product of p and q). The harder it is to factor N, the more secure our algorithm is
    long eulerTotient = (p-1) * (q-1); // step 3: find Euler's totient function, phi(n), for p and q.
    // step 4: now that we have phi(n), we need to find an int e SUCH THAT e > 1 and e < phi(n), i.e. 1 < e < phi(n). Also, e must be coprime with phi(n) - no common factors other than 1.
    long e = rand() % eulerTotient + 1; // generates a random number between 1 and phi(n), AKA e
    if (!isCoPrime(e, eulerTotient)) {
        // if e and phi(n) aren't coprime, print an error msg and exit.
        cout << "ERROR - e and phi(n) are not coprime" << endl;
        exit(1);
    }
    // at this point, we know that e is between 1 and phi(n) AND e is coprime with phi(n).
}
