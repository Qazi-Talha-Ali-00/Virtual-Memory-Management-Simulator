#include <unordered_map>
using namespace std;
class FrameEntry {
public:
    int Pid; // Process ID owning this frame
    int pageNum; // Page number in the process
    FrameEntry(){
        Pid=-1;
        pageNum = -1;
    }
    FrameEntry(int Pid, int pageNum){
        this->Pid = Pid;
        this->pageNum = pageNum;
    }
};

class FrameTable {
public:
    vector<FrameEntry*> frameTable; // Frame number -> FrameEntry

    void resize(int size){
        for(int i=0;i<size;i++){
            frameTable.push_back(new FrameEntry(-1,-1));
        }
    }
    
};
class PageTableEntry {
public:
    int frame; // Frame number in main memory, -1 if not present
    bool present; // Is present in main memory or not
    bool reference; // Has it been referenced earlier or not

    PageTableEntry(){
        frame = -1;
        present = false;
        reference = false;
    }
    void setPresent(bool value){
        present = value;
    }
    void setFrame (int value){
        frame = value;
    }
    void setReference(bool value){
        reference = value;
    }
    int getFrame(){
        return this->frame;
    }
    bool getReference(){
        return this->reference;
    }
    bool getPresent(){
        return this->present;
    }
};

class PageTable {
public:
    int Pid; // Process ID
    vector<PageTableEntry*> table; // Page number -> PageTableEntry

    
    PageTable(int id,int size){
        Pid = id;
        for(int i=0;i<size;i++){
            table.push_back(new PageTableEntry());
        }
    }

    // Access or create an entry for a specific page
    PageTableEntry* getEntry(int pageNum) {
        return table[pageNum];
    }
    int getPid(){
        return this->Pid;
    }
    bool isPresent(int pageNum){
        bool value=false;
        if(pageNum>=0 && pageNum < table.size()){
            value = table[pageNum]->getPresent();
        }
        return value;
    }

};
