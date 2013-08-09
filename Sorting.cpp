#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdarg>
#include <queue>
#include <boost\tokenizer.hpp>
using namespace std;

int InsSort(int arr[], int len){
	for ( int i = 0; i < len ; i++){
		int bck = i;
		while ( bck > 0 && arr[bck-1] > arr[bck]){
			int temp = arr[bck];
			arr[bck] = arr[bck-1];
			arr[bck-1] = temp;
			bck--;
		}
	}
}
void selSort(int arr[], int len){
	for( int i = 0; i < len ; i++){
		int small = arr[i];
		int smallIndex = -1;
		for( int j = i+1; j< len ; j++){
			if( arr[j] < small){
				small = arr[j];
				smallIndex = j;
			}
		}
		if( smallIndex != -1){
			arr[smallIndex] = arr[i];
			arr[i] = small;
		}
	}
}
int Partition( int arr[], int stIndex, int endIndex){
	if( stIndex == endIndex) return stIndex;
	
	// not so random pivot selection
	int pivIndex = stIndex + (endIndex - stIndex)/2;
	
	// swapping pivot to end Index
	int pivot = arr[pivIndex];
	arr[pivIndex] = arr[endIndex];
	arr[endIndex] = pivot;
	// iterating by seperator and forward
	int sep = stIndex;
	for( int fwd = stIndex + 1; fwd < endIndex ; fwd ++){
		if(arr[fwd] < pivot ){
			int temp = arr[sep];
			arr[sep] = arr[fwd];
			arr[fwd] = temp;
			sep++;
		}
	}
	// placing pivot on seperator
	arr[endIndex] = arr[sep];
	arr[sep] = [pivot];
	
	return sep;
}
void QuickSort(int arr[], int stIndex, int endIndex){
	if( stIndex >= endIndex ) return;

	int Index = Partition(arr, stIndex, endIndex);
	QuickSort(arr, stIndex, Index - 1);
	QuickSort(arr, Index +1, endIndex);
	
}

int main(){
	int arr[5] = {5,4,2,3,1};
	cout<<"\n";
	//cout<<"\n the counter is :"<<InsSort(arr, 5);
	QuickSort(arr, 0 , 4);
	for(int i = 0 ; i < 5 ; i++){
		std::cout<<arr[i];
	}
	cout<<"\n enter any number";
	int y;
	cin>>y;
	return 1;
}
