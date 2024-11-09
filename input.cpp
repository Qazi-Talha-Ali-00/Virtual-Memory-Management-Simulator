#include<bits/stdc++.h>
using namespace std;
int PAGE_SIZE;
int LAS;
int PAS;
int input(){
    cout<<"Enter the Page size in bytes :  ";
    cin>>PAGE_SIZE;
    cout<<"\nEnter the logical address space bits :  ";
    cin>>LAS;
    cout<<"\nEnter the physical address space bits :  ";
    cin>>PAS;
    cout<<endl;
    return 0;
}