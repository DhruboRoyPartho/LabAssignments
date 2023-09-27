#include<bits/stdc++.h>
using namespace std;

#define ARR_SIZE 100       //Defining array size for declare array
int data[ARR_SIZE][ARR_SIZE], singleArray[ARR_SIZE*ARR_SIZE+1];

//Merge Sort area begin
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
//Merge SOrt area end

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
    //sort(singleArray, singleArray+(n*n));

    mergeSort(singleArray, 0, (n*n)-1);

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
