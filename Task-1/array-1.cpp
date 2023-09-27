#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main()
{
    time_t t;
    srand((unsigned) time(&t));
    int n;
    cout<<"How many number do you want to generate automatically: ";
    cin>>n;
    int data[n+1];
    for(int i=0;i<n;i++){
        data[i] = rand();
    }
    for(int i=0;i<n;i++){
        cout<<data[i]<<" ";
    }
}
