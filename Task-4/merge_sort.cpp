#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1], b[n2];
    for(int i=0;i<n1;i++){
        a[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i] = arr[mid+i+1];
    }

    int i=0,j=0,k=l;
    while(i < n1 && j < n2){
        if(a[i] < b[j]){
            arr[k] = a[i];
            k++, i++;
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

void merge2array(int data1[], int data2[], int final_data[], int x, int y)
{
    int i=0,j=0,k=0;
    while(i<x && j<y){
        if(data1[i] < data2[j]){
            final_data[k] = data1[i];
            k++, i++;
        }
        else{
            final_data[k] = data2[i];
            k++, j++;
        }
    }
    while(i < x){
        final_data[k] = data1[i];
        k++, i++;
    }
    while(j < y){
        final_data[k] = data2[j];
        k++, j++;
    }
}


void display(int data[], int n)
{
    for(int i=0;i<n;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
    return;
}

int main()
{
    int x,y;
    cout<<"How many numbers do you want to enter in 1st array: ";
    cin>>x;
    cout<<"How many numbers do you want to enter in 2nd array: ";
    cin>>y;
    int data1[x],data2[y];
    cout<<"Enter 1st array data: ";
    for(int i=0;i<x;i++){
        cin>>data1[i];
    }
    cout<<"Enter 2nd array data: ";
    for(int i=0;i<y;i++){
        cin>>data2[i];
    }
    display(data1, x);
    display(data2, y);

    int final_data[x+y];
    mergeSort(data1, 0, x-1);
    mergeSort(data2, 0, y-1);

    cout<<"Merge value\n1st data:\n";
    for(auto &q:data1){
        cout<<q<<" ";
    }
    cout<<"\n2nd data:"<<endl;
    for(auto &q:data2){
        cout<<q<<" ";
    }
    cout<<endl;

    merge2array(data1, data2, final_data, x, y);
    cout<<"Sorted Value:\n";
    for(int i=0;i< x+y;i++){
        cout<<final_data[i]<<" ";
    }
    cout<<endl;
    return 0;
}
