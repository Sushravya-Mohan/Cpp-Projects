// Write a program to create a file and write "Hello, World!" into it.

#include <fstream>
#include <iostream>
using namespace std;

int main(){
    ofstream file("example.txt");   // Create an output file stream and open "example.txt"
    // Check if the file was opened successfully
    if (file.is_open()) {
        file << "Hello, World!";    // Write "Hello, World! to the file"
        file.close();               // Close the file after writing
        cout << "File written successfully!" << endl;   // Confirm success
    } else {
        cout << "Unable to open file!" << endl; // Handle error if file cannot be opened
    }
    return 0;   // Return success
}