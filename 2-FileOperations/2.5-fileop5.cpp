// Write a program to find and replace a word in a file.

#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string filename = "example.txt";        // Define the filename
    string searchWord = "Hello", replaceWord = "Hiii";  // Define words to search and replace

    ifstream inputFile(filename);       // Create an inout file stream for example.txt
    stringstream buffer;        // Create a stringstream to hold file content

    // Check if the input file was opened successfully
    if (inputFile.is_open()) {
        buffer << inputFile.rdbuf();    // Read the entire file into the buffer
        inputFile.close();      // Close the input file

        string content = buffer.str();  // Convert buffer into a string
        size_t pos = 0;     // Initialize position for searching

        // Replace occurences of searchWord with replaceWord
        while ((pos = content.find(searchWord, pos)) != string::npos) {
            content.replace(pos, searchWord.length(), replaceWord);     // Perform replacement
            pos += replaceWord.length();    // Move past the replaced word
        }

        ofstream outputFile(filename);      // Create an output file stream for writing back to the same file
        outputFile << content;      // Write the modified content to the output file
        outputFile.close();         // Close the output file

        cout << "Word replaced successfully!" << endl;  // Confirm success
    } else {
        cout << "Unable to open file!" << endl;     // Handle error if file cannot be opened
    }
    return 0;       // Return success
}