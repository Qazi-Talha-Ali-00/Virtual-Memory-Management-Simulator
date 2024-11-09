#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readFile() {
    ifstream fin("input1.txt");
    string line;
    int lineNumber = 1;  // To keep track of line numbers
    
    // Check if file opened successfully
    if (!fin.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    
    // Read file line by line
    while (getline(fin, line)) {
        // Convert string to integer
        int number = stoi(line);
        cout << "Line " << lineNumber << ": " << number << endl;
        lineNumber++;
    }
    
    fin.close();
}

int main() {
    readFile();
    return 0;
}