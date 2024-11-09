#include<vector>
#include"pageData.cpp"
using namespace std;
class mainMemory{
    public:
    vector<Page> memory;
    mainMemory(int size){
        memory.resize(size);
    }
};