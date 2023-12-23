#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include "File_IO.h"

using std::cin, std::cout, std::endl, std::ifstream, std::ofstream;
using std::string;
using std::vector;

bool isPrime(long N); // checks if the long int 'n' is prime, returns true if so and false if not

void isPrimeTest(long N); // uses isPrime() to check if N is prime, prints true if so or false if not

int main() {
    // step 1: read in the content of a given input file, line by line, possibly into a string array
    // step 2: write the encryption function (reads in a plaintext string and encrypts it with RSA)
    // step 3: write the decryption function (reads in ciphertext and decrypts it with RSA)
    // step 4: encrypt each line of the input file, then write each line to an output file
    // bonus step 5: decrypt each line of the output file and check if the result is the same as the plaintext file
    std::cout << "Hello, World!" << std::endl;
    // test cases for isPrime(): 2 (is prime), 7 (is prime), 15 (is NOT prime), 23 (is prime), 50 (is NOT prime), 121 (is NOT prime)
    isPrimeTest(2);
    isPrimeTest(7);
    isPrimeTest(15);
    isPrimeTest(23);
    isPrimeTest(50);
    isPrimeTest(121);
    // test case for File_IO class: will "read_input_lines()" work for our testFile.txt file?
    File_IO test_obj("../testFile.txt"); // created new File_IO object and passed the path to our input file in the constructor
    test_obj.read_input_lines(); // reads content of testFile into object's 'file_content' vector
    test_obj.print_content(); // prints content of 'file_content' vector (should be each line of input file at this point)
    return 0;
}

bool isPrime(long N) {
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

void isPrimeTest(long N) {
    bool result = isPrime(N); // true if N is prime, false if N isn't prime
    string trueOrFalse = (result == true) ? "TRUE" : "FALSE"; // this string is "TRUE" if N is prime, or "FALSE" if N isn't prime
    cout << N << " is prime: " << trueOrFalse << endl; // prints "N is prime: TRUE/FALSE" depending on result
}