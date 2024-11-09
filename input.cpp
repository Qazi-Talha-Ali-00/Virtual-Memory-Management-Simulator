#include <bits/stdc++.h>
using namespace std;

int PAGE_SIZE;
int LAS;  // Logical address space in bits
int PAS;  // Physical address space in bits

pair<long long,long long> input() {
    cout << "Enter the Page size in bytes: ";
    cin >> PAGE_SIZE;
    cout << "Enter the logical address space (in bytes): ";
    cin >> LAS;
    cout << "Enter the physical address space (in bytes): ";
    cin >> PAS;

    long long pages , frames;
    pages = pow(2,LAS)/PAGE_SIZE;
    frames = pow(2,PAS)/PAGE_SIZE;
    cout<<"Number of pages -> "<<pages<<endl;
    cout<<"Number of frames -> "<<frames<<endl;
    return {pages,frames};
}
