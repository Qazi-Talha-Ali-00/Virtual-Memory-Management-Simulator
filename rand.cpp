#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

void init(int size) {
    ofstream fout;
    fout.open("input1.txt");
    
    // 4 is page size in this particular example
    for(int i = 0; i < size*4; i++) {
        int address = rand() % (size * 4);
        fout << address << endl;  // Write number and newline
    }
    
    fout.close();
}

int main() {
    srand(time(0));  // Seed the random number generator
    
    // size = page number
    int size = 500;   // Example size
    init(size);
    
    return 0;
}