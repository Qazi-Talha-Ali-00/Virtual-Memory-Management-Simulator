#include<vector>
#include<cstdlib>
#include<iostream>
#include<unordered_map>
#include"frameTable.cpp"
using namespace std;
class Page{
    public:
    vector<char> data;
    Page(){
        data.resize(1024);
    }
    Page(int pageSize){
        data.resize(pageSize);
        for(auto &c : data){
            c = '0';
        }
    }
};
class mainMemory{
    public:
    vector<Page*> memory;
    void resize(int size){
        memory.resize(size);
    }
    void maininit(int frames,int size){
    for(int i=0;i<frames;i++){
        memory.push_back(new Page(size));
    }
}
};

class secondaryMemory{
    public:
    vector<Page*> Smemory;
    void resize(int size){
        Smemory.resize(size);
    }
    void secondaryinit(int pages,int size){
        for(int i=0;i<pages;i++){
            Smemory.push_back(new Page(size));
        }
    }
};
class MemoryTable {
public:
    unordered_map<int, int> processStartPage;  // Maps Pid to starting page in secondary memory
    unordered_map<int,PageTable*> process;
    // Method to update starting address for a process
    void addProcess(int pid, int startPage) {
        processStartPage[pid] = startPage;
    }
    int getAddress(int id){
        return processStartPage[id];
    }
};


void fillPageWithRandomData(Page* &page) {
    for (auto &byte : page->data) {
        byte = 'A' + (rand() % 26);  // Random character from 'A' to 'Z'
    }
}

int instanceCreate(secondaryMemory &secondary_arr,int pages){
    int start = 0;
    for(int i=0;i<secondary_arr.Smemory.size();i++){
        if(secondary_arr.Smemory[i]->data[0] =='0'){
            start = i;
            break;
        }
    }
    for(int i=start;i<pages;i++){
        fillPageWithRandomData(secondary_arr.Smemory[i]);
    }
    return start;


}
