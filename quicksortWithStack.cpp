#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int startIndex, int endIndex)
{
	int pivot = arr[endIndex];
	int pivotIndex = startIndex;
	for(int i=startIndex;i<endIndex;i++){
		if(arr[i] <= pivot){
			swap(arr[i], arr[pivotIndex]);
			pivotIndex++;
		}
	}
	swap(arr[pivotIndex], arr[endIndex]);

	return pivotIndex;
}

void quickSort(int arr[], int l, int r)
{
	stack<pair<int, int>> s;

	int startIdx = l;
	int endIdx = r-1;

	s.push({startIdx, endIdx});

	while(!s.empty()){
		startIdx = s.top().first;
		endIdx = s.top().second;
		s.pop();

		int pivot = partition(arr, startIdx, endIdx);

		if(pivot - 1 > startIdx){
			s.push({startIdx, pivot - 1});
		}

		if(pivot + 1 < endIdx){
			s.push({pivot+1, endIdx});
		}
	}

}


int main()
{
	int data[] = {8,1,0,7,3,6};
	int len = sizeof(data)/sizeof(data[0]);
	quickSort(data, 0, len);
	for(int i=0;i<len;i++){
		cout<<data[i]<<" ";
	}
	cout<<endl;
	return 0;
}
