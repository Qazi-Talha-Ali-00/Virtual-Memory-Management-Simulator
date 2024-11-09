#include<vector>
using namespace std;
class Page{
    public:
    vector<char> num;
    Page(int pageSize){
        num.resize(pageSize);
    }
};