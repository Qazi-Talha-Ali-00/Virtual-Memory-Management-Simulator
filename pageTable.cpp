#include<bits/stdc++.h>
using namespace std;

class PageTableEntry{
    public:
    int frame; // address of the frame
    bool dirty; // Modified or not
    bool present; // Is present in the main memory or not
    int reference; // has it been referenced earlier or not
    // basic constructor
     PageTableEntry(){
        dirty = false;
        present = false;
        reference = false;
    }
};
class PageTable{
    int Pid;
    // key is page number 
    unordered_map<int,PageTableEntry*> table;
};