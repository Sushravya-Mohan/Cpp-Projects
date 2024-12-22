// Write a program to count the number of words in a file

#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream file("example.txt");   // Create an input file stream to open "example.txt"
    string word;                    // Declare a string variable to hold each word
    int wordCount = 0;              // Initialize a counter for words
    // Check if the file was opened successfully
    if (file.is_open()) {
        // Read words from the file until EOF (End Of File)
        while (file >> word) {
            wordCount++;    // Increment the word count for each word read
        }
        file.close();       // Close the file after reading
        cout << "Number of words: " << wordCount << endl;   // Output the total number of word count
    } else {
        cout << "Unable to open file!" << endl;        // Handle error if file cannot be opened
    }
    return 0;   // Return success
}