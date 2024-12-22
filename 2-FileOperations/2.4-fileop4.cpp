// Write a program to copy the contents of one file to another

#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream inputFile("example.txt");          // Create an input file stream for example.txt
    ofstream outputFile("destination.txt");     // Create an output file stream for destination.txt
    string line;              // Declare a string variable to hold each line
    // Check if both files were opened successfully
    if (inputFile.is_open() && outputFile.is_open()) {
        // Read lines from the input file and write them to the output file
        while (getline(inputFile, line)) {
            outputFile << line << endl;
        }
        inputFile.close();          // Close the input file
        outputFile.close();         // Close the output file
        cout << "File copied successfully!" << endl;        // Confirm successful copy
    } else {
        cout << "Unable to open files!" << endl;        // Handle error if files cannot be opened
    }   
    return 0;       // Return success
}