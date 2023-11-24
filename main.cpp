#include <iostream>
#include <string>
#include <fstream>
using std::cin;
using std::cout;
using std::string;

int encrypt(string plain_text); // encrypts "plain_text" and returns the int ciphertext

string decrypt(int cipher_text); // decrypts "cipher_text" and returns the translated string plaintext

int main() {
    // step 1: read in the content of a given input file, line by line, possibly into a string array
    // step 2: write the encryption function (reads in a plaintext string and encrypts it with RSA)
    // step 3: write the decryption function (reads in ciphertext and decrypts it with RSA)
    // step 4: encrypt each line of the input file, then write each line to an output file
    // bonus step 5: decrypt each line of the output file and check if the result is the same as the plaintext file
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
