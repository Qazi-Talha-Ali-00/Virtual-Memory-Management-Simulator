#include <unordered_map>
using namespace std;

class PageTableEntry {
public:
    int frame; // Frame number in main memory, -1 if not present
    bool dirty; // Modified or not
    bool present; // Is present in main memory or not
    bool reference; // Has it been referenced earlier or not

    PageTableEntry() : frame(-1), dirty(false), present(false), reference(false) {}
};

class PageTable {
public:
    int Pid; // Process ID
    unordered_map<int, PageTableEntry> table; // Page number -> PageTableEntry

    PageTable(int id) : Pid(id) {}

    // Access or create an entry for a specific page
    PageTableEntry& getEntry(int pageNum) {
        return table[pageNum];
    }
};
