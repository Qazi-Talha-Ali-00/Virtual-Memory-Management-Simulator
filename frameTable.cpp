#include <unordered_map>
using namespace std;
class FrameEntry {
public:
    int Pid; // Process ID owning this frame
    int pageNum; // Page number in the process

    FrameEntry(int Pid, int pageNum) : Pid(Pid), pageNum(pageNum) {}
};

class FrameTable {
public:
    unordered_map<int, FrameEntry> frameTable; // Frame number -> FrameEntry

    // Adds a frame entry to the frame table
    void addFrame(int frameNum, int Pid, int pageNum) {
        frameTable[frameNum] = FrameEntry(Pid, pageNum);
    }

    // Removes a frame entry from the frame table
    void removeFrame(int frameNum) {
        frameTable.erase(frameNum);
    }

    // Retrieves a frame entry by frame number
    FrameEntry* getFrame(int frameNum) {
        auto it = frameTable.find(frameNum);
        if (it != frameTable.end()) {
            return &(it->second);
        }
        return nullptr; // Returns nullptr if frame number is not found
    }
};
