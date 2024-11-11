#include <bits/stdc++.h>
#include "input.cpp"
#include "frameTable.cpp"
#include "memory.cpp"
#include "replace_init.cpp"
#include <thread>
using namespace std;
long long pages, frames;
mainMemory main_arr;
MemoryTable mem;
secondaryMemory secondary_arr;
FrameTable frame_arr;
vector<mutex> mtx;
queue<int> fifoQueue; // Used for FIFO
vector<int> accessOrder; // Used for MRU and LRU


int getByte(int number)
{
    return number % PAGE_SIZE;
}
int getPage(int number, int pid)
{
    // offset + page number
    return mem.getAddress(pid) + number / PAGE_SIZE;
}
// FIFO eviction policy
// int evictFIFO() {
//     int frame_to_evict = fifoQueue.front();
//     fifoQueue.pop();
//     return frame_to_evict;
// }
// // MRU eviction policy
// int evictMRU() {
//     int mru_frame = accessOrder.back(); // Most recently accessed frame
//     accessOrder.pop_back();
//     return mru_frame;
// }
// // LRU eviction policy
// int evictLRU() {
//     int lru_frame = -1;
//     for (int i = 0; i < frames; i++) {
//         if (!P1.getEntry(frame_arr.getFrame(i)->pageNum)->reference) {
//             lru_frame = i;
//             break;
//         }
//         P1.getEntry(frame_arr.getFrame(i)->pageNum)->reference = false;
//     }
//     return lru_frame;
// }

// Page *pageFault(int number, int pid)
// {

//     // Traverse the main memory to see if any place is left to load the page and load it there
//     int page = getPage(number, pid);
//     for (int i = 0; i < frames; i++)
//     {
//         if (main_arr.memory[i]->data[0] == '0')
//         {
//             mtx[i].lock();
//             main_arr.memory[i] = secondary_arr.Smemory[page];
//             frame_arr.addFrame(i, pid, page);
//             mtx[i].unlock();
//             return main_arr.memory[i];
//         }
//     }
//     // else eviction scheme
// }
string getinputFile(int id){
    return "input" + to_string(id) + ".txt";
}
string getoutputFile(int id){
    return "output" + to_string(id) + ".txt";
}
void MMU(PageTable &P)
{
    
    string input = getinputFile(P.getPid());
    ifstream fin(input);
    if(!fin.is_open()){
        cout<<"Error opening the file "<<input<<endl;
        return;
    }
    
    string output = getoutputFile(P.getPid());
    ofstream fout(output);
    if(!fout.is_open()){
        cout<<"Error opening the file "<<output<<endl;
        return;
    }
    int hit=0,miss =0;
    string line;
    while(getline(fin,line)){
        int number = stoi(line);
        int page , byte;
        page = getPage(number,P.getPid());
        byte = getByte(number);
        if(!P.isPresent(page)){
            miss++;
        }
    }
    fout.close();
    fin.close(); 
}

int main()
{
    auto element = input();
    replace();

    pages = element.first;
    frames = element.second;

    // Inititalize the main and secondary memory

    main_arr.maininit(frames, PAGE_SIZE);
    secondary_arr.secondaryinit(pages, PAGE_SIZE);
    frame_arr.resize(frames);
    mtx = vector<mutex>(frames);

    PageTable P1(1,500), P2(2,1000);
    mem.addProcess(1, instanceCreate(secondary_arr, 500));
    mem.addProcess(2, instanceCreate(secondary_arr, 1000));

   

    thread t1(MMU, ref(P1));
    thread t2(MMU, ref(P2));
    
    t1.join();
    t2.join();
    return 0;
}