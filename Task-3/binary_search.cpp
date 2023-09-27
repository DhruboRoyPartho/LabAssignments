#include<iostream>
using namespace std;

int binary_search(int data[], int n, int value)
{
    int l = 0, r = n, mid;
    while(l<=r){
        mid = (l+r)/2;
        if(data[mid] == value) return mid;
        if(data[mid] > value){
            r = mid-1;
        }
        else if(data[mid] < value){
            l = mid+1;
        }
    }
    return -1;
}

void bubble_sort(int data[], int n)
{
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(data[j] > data[j+1])
                swap(data[j], data[j+1]);
        }
    }
    return;
}

int main()
{
    // int data[] = {9, 10, 13, 8, 1, 0, 2, 3,7, 2};
    // int len = sizeof(data)/sizeof(data[0]);
    cout<<"How many number do you want to enter: ";
    int len;
    cin>>len;
    int data[len];
    for(int i=0;i<len;i++){
        cin>>data[i];
    }
    cout<<"You have entered:\n";
    for(auto &q:data){
        cout<<q<<" ";
    }
    cout<<endl;

    bubble_sort(data, len);
    cout<<"Sorted Value:"<<endl;
    for(auto &q:data){
        cout<<q<<" ";
    }
    cout<<endl;
    int val;
    cout<<"What do you want to search: ";
    cin>>val;
    cout<<"Index is: "<<binary_search(data, len, val)<<endl;
    return 0;
}
