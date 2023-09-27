#include<bits/stdc++.h>
using namespace std;

//Merge Sort
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

int main()
{
    int x,y;
    cout<<"Enter row and column number by space: ";
    cin>>x>>y;
    int data[x][y];
    int singleArray[y];
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cin>>data[i][j];
        }
    }
    cout<<"Your data\n";
    for(int i=0;i<x;i++){
        int l = 0;
        for(int j=0;j<y;j++){
            cout<<data[i][j]<<" ";
            singleArray[l] = data[i][j];
            l++;
        }
        mergeSort(singleArray, 0, l-1);
        for(l=0;l<y;l++){
            data[i][l] = singleArray[l];
        }
        cout<<endl;
    }

    cout<<"Row Sorted data:"<<endl;
    //display
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
