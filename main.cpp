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
queue<int> fifoQueue;    // Used for FIFO
vector<int> accessOrder; // Used for MRU and LRU

int getByte(int number)
{
    return number % PAGE_SIZE;
}
int getPage(int number, int pid)
{
    //  page number
    return number / PAGE_SIZE;
}
// FIFO eviction policy
int evictFIFO() {
    return 0;
  
}
// // MRU eviction policy
int evictMRU() {
    return 0;
   
}
// // LRU eviction policy
int evictLRU() {
   return 0;
}

int evictOptimal(){
    return 0;

}

Page *pageFault(int number, int pid,PageTable &P)
{

    // Traverse the main memory to see if any place is left to load the page and load it there
    int page = getPage(number,pid);
    int address = mem.getAddress(pid);
    for(int i=0;i<main_arr.memory.size();i++){
        if(main_arr.memory[i]->data[0] == '0'){
            // copy from the seondary memory to main memory
            main_arr.memory[i] = secondary_arr.Smemory[address];
            frame_arr.frameTable[i]->pageNum = page;
            frame_arr.frameTable[i]->Pid = pid;
            P.table[page]->setFrame(i);
            P.table[page]->setPresent(true);
            return main_arr.memory[i];
        }
    }
    // else eviction scheme
    int evict = -1;
    if(policy == "LRU"){
        evict = evictLRU();
    }else if(policy == "FIFO"){
        evict = evictFIFO();
    }else if(policy == "MRU"){
        evict = evictMRU();
    }else{
        evict = evictOptimal();
    }
    return NULL;
}
string getinputFile(int id)
{
    return "input" + to_string(id) + ".txt";
}
string getoutputFile(int id)
{
    return "output" + to_string(id) + ".txt";
}
void MMU(PageTable &P)
{

    string input = getinputFile(P.getPid());
    ifstream fin(input);
    if (!fin.is_open())
    {
        cout << "Error opening the file " << input << endl;
        return;
    }

    string output = getoutputFile(P.getPid());
    ofstream fout(output);
    if (!fout.is_open())
    {
        cout << "Error opening the file " << output << endl;
        return;
    }
    int hit = 0, miss = 0;
    string line;
    while (getline(fin, line))
    {
        int number = stoi(line);
        int page, byte;
        page = getPage(number, P.getPid());
        byte = getByte(number);
        if (!P.isPresent(page))
        {
            // Page fault
            miss++;
            pageFault(number,P.getPid(),P);
            
        }
        else
        {
            // hit
            hit++;
            int frame = P.getEntry(page)->frame;
            char c;
            mtx[frame].lock();
            c = main_arr.memory[frame]->data[byte];
            mtx[frame].unlock();
            fout << c << endl;
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

    PageTable P1(1, 500), P2(2, 1000);
    mem.addProcess(1, instanceCreate(secondary_arr, 500));
    mem.addProcess(2, instanceCreate(secondary_arr, 1000));

    thread t1(MMU, ref(P1));
    thread t2(MMU, ref(P2));

    t1.join();
    t2.join();
    return 0;
}