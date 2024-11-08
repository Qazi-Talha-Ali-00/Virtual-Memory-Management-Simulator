#include<bits/stdc++.h>
using namespace std;

class PageTableEntry{
    public:
    int frame;
    bool dirty;
    bool present;
    int reference;
     PageTableEntry(){
        dirty = false;
        present = false;
        reference = false;
    }
};
class PageTable{
    int Pid;
    unordered_map<int,PageTableEntry*> table;
};