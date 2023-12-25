#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include "File_IO.h"
#include "EncryptDecrypt.h"

using std::cin, std::cout, std::endl, std::ifstream, std::ofstream;
using std::string;
using std::vector;

int main() {
    // step 1: read in the content of a given input file, line by line, possibly into a string array
    // step 2: write the encryption function (reads in a plaintext string and encrypts it with RSA)
    // step 3: write the decryption function (reads in ciphertext and decrypts it with RSA)
    // step 4: encrypt each line of the input file, then write each line to an output file
    // bonus step 5: decrypt each line of the output file and check if the result is the same as the plaintext file
    std::cout << "Hello, World!" << std::endl;
    // test case for File_IO class: will "read_input_lines()" work for our testFile.txt file?
    File_IO test_obj("../testFile.txt"); // created new File_IO object and passed the path to our input file in the constructor
    test_obj.read_input_lines(); // reads content of testFile into object's 'file_content' vector
    test_obj.print_content(); // prints content of 'file_content' vector (should be each line of input file at this point)
    return 0;
}

