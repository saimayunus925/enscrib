#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using std::cin, std::cout, std::endl, std::ifstream, std::ofstream;
using std::string;
using std::vector;

vector <string> read_lines(string file_name); // reads each line of the file 'file_name' into a string vector, returns that vector

long encrypt(string plain_text); // encrypts "plain_text" and returns the int ciphertext

string decrypt(long cipher_text); // decrypts "cipher_text" and returns the translated string plaintext

int main() {
    // step 1: read in the content of a given input file, line by line, possibly into a string array
    // step 2: write the encryption function (reads in a plaintext string and encrypts it with RSA)
    // step 3: write the decryption function (reads in ciphertext and decrypts it with RSA)
    // step 4: encrypt each line of the input file, then write each line to an output file
    // bonus step 5: decrypt each line of the output file and check if the result is the same as the plaintext file
    std::cout << "Hello, World!" << std::endl;
    // cout << "CURRENT PATH: " << fs::current_path() << endl;
    vector <string> fileContent = read_lines("../testFile.txt"); // read all lines from a test file into 'fileContent' vector
    for (int i = 0; i < fileContent.size(); i++) // testing purposes: print each line of 'fileContent' to see if the file input worked
        cout << "Element " << i+1 << ": " << fileContent.at(i) << endl;
    return 0;
}

vector <string> read_lines(string file_name) {
    // step 1: open the file
    ifstream input; // the file stream object
    input.open(file_name); // opening the file
    // step 2: make sure the file is open
    bool OPEN = input.is_open(); // this returns true if the file opened correctly
    if (!OPEN) {
        perror("ERROR"); // this prints "ERROR" and then the error message for clarity
        exit(1); // exit if file didn't open
    }
    // step 3: make the result vector
    vector <string> result;
    // step 4: read each line of the file into the result vector
    while (!input.eof()) {
        // as long as we're not at the end of the file, we'll read each line of it
        string newLine = ""; // the variable to store each line of the file
        getline(input, newLine); // the big step: reading in the current line from our file into 'newLine' str
        result.push_back(newLine); // add the 'newLine' var (with our current file line's content) into 'result' vector
    }
    input.close(); // closing file now that we're done with it
    return result; // return the vector
}