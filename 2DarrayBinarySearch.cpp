//Author: Dhrubo Roy Partho
//Date: 27-09-2023

#include<bits/stdc++.h>
using namespace std;

#define ARR_SIZE 100     //First I defined the size of array
int data[ARR_SIZE][ARR_SIZE], singleArray[ARR_SIZE*ARR_SIZE];   //data array for 2D matrix
                                                                // singleArray array for store 2D array in single array

//Function for input data
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


//Function for sort 2D array
void sort2D(int n)
{
    int l = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            singleArray[l] = data[i][j];
            l++;
        }
    }
    sort(singleArray, singleArray+(n*n)); // here you can make own sorting system.i used built-in sort for simplicity.
    // for(int i=0;i<n*n;i++){
    //     cout<<singleArray[i]<<" ";
    // }
    // cout<<endl;
    l=0;
    for(int i=0;i<n;i++){          //Here I made 2D array into 1D array. You can do it when you take input
        for(int j=0;j<n;j++){
            data[i][j] = singleArray[l];
            l++;
        }
    }
    display2D(n);      // For display sorted 2D array
}

//Binary search Function
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;    // m for mid value
 
        // Check if x is present at mid
        if (arr[m] == x){
            return m;
        }
 
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // If we reach here, then element was not present
    return -1;
}

int main()
{
    
    int n,x;
    cout<<"Enter row/col number for square matrix 2D array: "<<endl;
    cin>>n;
    cout<<"Enter the values: \n"; 
    takeValue(n);
    cout<<"Your entered values are: "<<endl;
    display2D(n);
    cout<<"Sort 2D:"<<endl;
    sort2D(n);
    cout<<"Which number do you want to search: ";
    cin>>x;
    int r_pos = binarySearch(singleArray, 0, n*n, x);
    if(r_pos == -1)
        cout<<"Not found"<<endl;
    else
        cout<<"Found at\n\trow: "<<floor(r_pos/n) + 1<<"\n\tcol: "<<r_pos%n + 1<<endl;

        //here formula, row = floor((index)/column number) + 1
        // col = (index%column number) + 1
    return 0;   
}
