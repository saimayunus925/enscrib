//
// Created by Saima Yunus on 12/23/23.
//

#include "File_IO.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::cin, std::cout, std::endl, std::ifstream, std::ofstream;
using std::string;
using std::vector;

File_IO::File_IO() {
    // initializing both file names to blank strings
    this->inputFile = "";
    this->outputFile = "";
}

File_IO::File_IO(std::string INPUT_FILENAME) {
    // initializing input file name to passed-in name and output file name to blank string
    this->inputFile = INPUT_FILENAME;
    this->outputFile = "";
}

File_IO::File_IO(std::string INPUT_FILENAME, std::string OUTPUT_FILENAME) {
    // initializing both file names to the passed-in names
    this->inputFile = INPUT_FILENAME;
    this->outputFile = OUTPUT_FILENAME;
}

void File_IO::read_input_lines() {
    // step 1: open the input file
    ifstream input; // the file stream object
    input.open(this->inputFile); // opening the file
    // step 2: make sure the file is open
    bool OPEN = input.is_open(); // this returns true if the file opened correctly
    if (!OPEN) {
        perror("ERROR"); // this prints "ERROR" and then the error message for clarity
        exit(1); // exit if file didn't open
    }
    // step 3: read each line of the file into the 'file_content' vector
    while (!input.eof()) {
        // as long as we're not at the end of the file, we'll read each line of it
        string newLine = ""; // the variable to store each line of the file
        getline(input, newLine); // the big step: reading in the current line from our file into 'newLine' str
        this->file_content.push_back(newLine) // add the 'newLine' var (with our current file line's content) into 'file_content' vector
    }
    input.close(); // closing file now that we're done with it
}
