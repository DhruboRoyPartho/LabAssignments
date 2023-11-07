#include<iostream>
using namespace std;

void selection_sort(int data[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++) {
 
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
 
        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
    return;
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

void insertion_sort(int data[], int n)
{
    int temp;
    for(int i=1;i<n;i++){
        temp = data[i];
        for(int j = i-1;j>=0;j--){
            if(data[j] > temp){
                data[j+1] = data[j];
                data[j] = temp;
            }
        }
    }
    return;
}

int main()
{
    //int data[] = {10, 12, 13, 9, 2, 1, 0, 5, 7};
    //int len = sizeof(data)/sizeof(data[0]);
    //selection_sort(data, len);
    //bubble_sort(data, len);
    //insertion_sort(data, len);
    int len;
    cout<<"How many Number do you want to enter: "<<endl;
    cin>>len;
    int data[len+1];
    for(int i=0;i<len;i++){
        cin>>data[i];
    }
    int selection;
    cout<<"Which algorithm you choose to sort: \n\t1. Selection Sort\n\t2. Bubble Sort\n\t3. Insertion Sort"<<endl;
    cin>>selection;
    switch(selection){
    case 1:
        cout<<"Selection Sort:"<<endl;
        selection_sort(data, len);
        break;
    case 2:
        cout<<"Bubble Sort:"<<endl;
        bubble_sort(data, len);
        break;
    case 3:
        cout<<"Insertion Sort:"<<endl;
        insertion_sort(data, len);
        break;
    default:
        cout<<"You have choosen a wrong selection number."<<endl;
        break;
    }
    for(int i=0;i<len;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}
