// Write a program to read the contents of a file and display it on the console

#include <fstream>
#include <iostream>
using namespace std;

int main(){
    ifstream file("example.txt");   // Create an input file stream object
    string line;                    // Declare a string variable to hold each line
    // Check if the file was opened successfully
    if (file.is_open()){
        // Read the file line by line
        while(getline(file, line)){
            cout << line << endl;   // Output each line to the console
        }
        file.close();               // Close the file after reading
    } else {
        cout << "Unable to open file!" << endl; // Handle error if file cannot be opened
    }
    return 0;   // Return success
}