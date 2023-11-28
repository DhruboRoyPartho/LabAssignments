#include<iostream>
using namespace std;

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l-1;

    for(int j = l; j < r;j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

void quickSort(int arr[], int l, int r)
{
    if(l<r){
        int pi = partition(arr,l,r);

        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}

int main()
{
    int data[] = {4,1,7,9,10,5};
    int len = sizeof(data)/sizeof(data[0]);
    quickSort(data, 0, len-1);
    for(int i=0;i<len;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
    return 0;
}