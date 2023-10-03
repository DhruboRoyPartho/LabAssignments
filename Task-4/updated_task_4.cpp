//Author: Dhrubo Roy Partho
//Date: 03/10/2023
//Outcome: Merge two array and sort them with merge sort

#include<iostream>
using namespace std;

int merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r -  mid;
    int a[n1], b[n2];
    for(int i=0;i<n1;i++){
        a[i] = arr[l + i];
    }
    for(int i=0;i<n2;i++){
        b[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = l;

    while(i<n1 && j<n2){
        if(a[i] < b[j]){
            arr[k] = a[i];
            i++, k++;
        }
        else{
            arr[k] = b[j];
            k++, j++;
        }
    }

    while(i<n1){
        arr[k] = a[i];
        i++, k++;
    }
    
    while(j<n2){
        arr[k] = b[j];
        j++, k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }

}

void show_data(int arr[], int n)
{
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n1,n2;
    cout<<"Enter 2 array size separate by space: ";
    cin>>n1>>n2;
    int data1[n1], data2[n2], data[n1+n2];

    //You can also take data in one array by sizing n1+n2

    cout<<"Enter 1st Array data by space: ";
    for(int i=0;i<n1;i++){
        cin>>data1[i];
    }
    cout<<"Enter 2nd Array data by space: ";
    for(int i=0;i<n2;i++){
        cin>>data2[i];
    }
    
    //Merging two array
    for(int i=0;i<n1+n2;i++){
        if(i<n1){
            data[i] = data1[i];
        }
        else{
            data[i] = data2[i-n1];
        }
    }

    show_data(data, n1+n2);

    mergeSort(data, 0, n1+n2-1);

    show_data(data, n1+n2);

    return 0;

}
