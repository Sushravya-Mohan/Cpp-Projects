// Write a program to merge the contents of two files into a third file
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    // Open two input files and one output files
    ifstream file1("example.txt"), file2("destination.txt");
    ofstream mergedfile("merged.txt");

    string line;    // Declare a string variable to hold each line

    // Check if all the files were opened successfully
    if (file1.is_open() && file2.is_open() && mergedfile.is_open()) {
        // Read lines from the first file and write them to the merged file
        while (getline(file1, line)) {
            mergedfile << line << endl;
        }
        // Read lines from the second file and write them to the merged file
        while (getline(file2, line)) {
            mergedfile << line << endl;
        }
        // Close all files after processing
        file1.close();
        file2.close();
        mergedfile.close();
        // Confirm success
        cout << "Files merged successfully!" << endl;
    } else {
        // Handle error if any files cannot be opened
        cout << "Unable to open files!" << endl;
    }
    return 0;   // Return success
}