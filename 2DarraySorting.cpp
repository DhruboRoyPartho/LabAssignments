//Author: Dhrubo Roy Partho
//Date: 27-09-2023

#include<bits/stdc++.h>
using namespace std;

#define ARR_SIZE 100       //Defining array size for declare array
int data[ARR_SIZE][ARR_SIZE], singleArray[ARR_SIZE*ARR_SIZE+1];

//Function for take input values
void takeValue(int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>data[i][j];
        }
    }
}

//Function for display 2D array
void display2D(int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }
}

void sort2D(int n)
{
    int l = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            singleArray[l] = data[i][j];
            l++;
        }
    }
    sort(singleArray, singleArray+(n*n)); // here you can make own sorting system.such as, bubble, selection, insertion, merge, quick etc. sorts. i used built-in sort for simplicity.
    // for(int i=0;i<n*n;i++){
    //     cout<<singleArray[i]<<" ";
    // }
    // cout<<endl;
    l=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            data[i][j] = singleArray[l];
            l++;
        }
    }
    display2D(n);
}

int main()
{
    int n;
    cout<<"Enter row/col number for square matrix 2D array: "<<endl;
    cin>>n;
    cout<<"Enter the values: \n"; 
    takeValue(n);
    cout<<"Your entered values are: "<<endl;
    display2D(n);
    cout<<"Sort 2D:"<<endl;
    sort2D(n);
    return 0;   
}
