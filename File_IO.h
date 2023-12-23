//
// Created by Saima Yunus on 12/23/23.
//

#ifndef FILE_ENCRYPTION_PROJECT_FILE_IO_H
#define FILE_ENCRYPTION_PROJECT_FILE_IO_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::cin, std::cout, std::endl, std::ifstream, std::ofstream;
using std::string;
using std::vector;


class File_IO {
    private:
        string inputFile; // name of input file with data to be encrypted/decrypted
        string outputFile; // name of output file where resulting encrypted/decrypted data is written
        vector <string> file_content; // vector where we'll read each line of the file to be encrypted/decrypted
    public:
        File_IO(); // default constructor
        File_IO(string INPUT_FILENAME); // parametrized constructor with only the input file name
        File_IO(string INPUT_FILENAME, string OUTPUT_FILENAME); // parametrized constructor with both file names (input file and output file)
        void read_input_lines(); // reads each line of the input file into 'file_content' vector
        void write_output_lines(); // writes each line of 'file_content' vector into output file
};


#endif //FILE_ENCRYPTION_PROJECT_FILE_IO_H
