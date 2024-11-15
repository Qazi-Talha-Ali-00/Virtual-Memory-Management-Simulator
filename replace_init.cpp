#include <bits/stdc++.h>
using namespace std;
string policy = "LRU";
vector<int> future_accesses;
void replace()
{
    cout << "Do you wish to change the replacement scheme yes or No? " << endl
         << "Note the default scheme is LRU" << endl;
    cout << "Enter 1 for yes 0 for No " << endl;
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << "************************************************************************" << endl;
        return;
    }
    cout << "Enter" << endl
         << "1: LRU" << endl
         << "2: FIFO" << endl;
    cout << "3: MRU" << endl;
    cout << "4: Optimal" << endl;
    cout << "************************************************************************" << endl;
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        policy.clear();
        policy += "LRU";
        break;
    case 2:
        policy.clear();
        policy += "FIFO";
        break;
    case 3:
        policy.clear();
        policy += "MRU";
        break;
    default:
        policy.clear();
        policy += "Optimal";
    }

    return;
}