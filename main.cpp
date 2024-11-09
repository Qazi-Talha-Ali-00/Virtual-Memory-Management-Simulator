#include <bits/stdc++.h>
#include "input.cpp"
#include "frameTable.cpp"
#include "memory.cpp"
#include<thread>
using namespace std;
long long pages, frames;
mainMemory main_arr;
MemoryTable mem;
PageTable P1(1),P2(2);
secondaryMemory secondary_arr;
FrameTable frame_arr;
vector<std::mutex> mtx;

int getByte(int number){
    return number%PAGE_SIZE;
}
int getPage(int number,int pid){
    // offset + page number
    return mem.getAddress(pid) + number/PAGE_SIZE;
}

Page* pageFault(int number,int pid){
    
    // simply load the frame there


}
void MMU(PageTable & P){
    int hit=0,miss= 0;
    ifstream fin;
    string file_name = "input" + to_string(P.getPid()) + ".txt";
    fin.open(file_name);
    string line;
    ofstream fout;
    string file2 = "output" + to_string(P.getPid()) +".txt";
    fout.open(file2);
    while(getline(fin,line)){
        int number = stoi(line);

        int page = getPage(number,P.getPid());
        int byte = getByte(number);
        // hit
        if(P.getEntry(page)->present){
            hit++;
            int frame = P.table[page]->frame;
            char c;
            c = main_arr.memory[frame]->data[byte];
            fout<<c<<endl;
        }else{
            // Page fault
        }

        
    }

    fout.close();
    fin.close();

    
}

int main()
{
    auto element = input();

    pages = element.first;
    frames = element.second;

    // Inititalize the main and secondary memory
    
    main_arr.maininit(frames, PAGE_SIZE);
    secondary_arr.secondaryinit(pages, PAGE_SIZE);
    frame_arr.resize(frames);
    mtx.resize(frames);

    mem.addProcess(1, instanceCreate(secondary_arr, 500));
    mem.addProcess(2, instanceCreate(secondary_arr, 1000));
 
    thread t1(MMU, ref(P1));    
    thread t2(MMU,ref(P2));
    
    t1.join();
    t2.join();
    return 0;
}