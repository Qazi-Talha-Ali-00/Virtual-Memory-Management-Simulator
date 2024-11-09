#include <unordered_map>
using namespace std;
class FrameEntry {
public:
    int Pid; // Process ID owning this frame
    int pageNum; // Page number in the process
    FrameEntry(){
        Pid=-1;
    }
    FrameEntry(int Pid, int pageNum){
        this->Pid = Pid;
        this->pageNum = pageNum;
    }
};

class FrameTable {
public:
    vector<FrameEntry> frameTable; // Frame number -> FrameEntry

    // Adds a frame entry to the frame table
    void addFrame(int frameNum, int Pid, int pageNum) {
        frameTable[frameNum] = FrameEntry(Pid, pageNum);
    }

    // Removes a frame entry from the frame table
    void removeFrame(int frameNum) {
        frameTable[frameNum].Pid = -1;
    }

    // Retrieves a frame entry by frame number
    FrameEntry* getFrame(int frameNum) {
         // Returns nullptr if frame number is not found
         return &frameTable[frameNum];
    }
    void resize(int size){
        frameTable.resize(size);
    }
};
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
    vector<PageTableEntry*> table; // Page number -> PageTableEntry

    PageTable(int id) : Pid(id) {}

    // Access or create an entry for a specific page
    PageTableEntry* getEntry(int pageNum) {
        return table[pageNum];
    }
    int getPid(){
        return this->Pid;
    }

};
