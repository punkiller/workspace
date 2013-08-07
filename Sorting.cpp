#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdarg>
#include <queue>
#include <boost\tokenizer.hpp>
using namespace std;

class Lnode{
public:
	int data;
	Lnode* next;
	Lnode( int n){
		data =n;
		next = NULL;
	}
};

class Tnode{
public :
	int data;
	Tnode *left;
	Tnode *right;
	Tnode(int x=0){
		data = x;
		left = NULL;
		right = NULL;
	}
};
void printL( Lnode * head){
	cout<<"\n->";
	while( head!= NULL){
		cout<<head->data<<"--";
		head= head->next;
	}
	return;
}

void printTreeIn(Tnode * root){
	if( root == NULL)
		return ;
	cout<<root->data;
	printTreeIn(root->left);
	printTreeIn(root->right);
	return ;
}
int FindSucc( Tnode * root, int target){
	if( root->data == NULL ) return 0;
	if( root->data < target );
	//search for target
	// if left child of parent
		//leftest of the right child of target
		//else
		// parent
	//else
		//leftest of right child of target
}
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
int Partition( int arr[], int stIndex, int pivIndex, int endIndex){
	if( stIndex == endIndex) return stIndex;
	int pivot = arr[pivIndex];
	int sep = stIndex;
	int fwd = stIndex+1;
	arr[pivIndex] = arr[stIndex];
	arr[stIndex] = pivot;
	for( int fwd = stIndex + 1; fwd <= endIndex ; fwd ++){
		if(arr[fwd] < pivot ){
			arr
		}
	}
}
void QuickSort(int arr[], int stIndex, int endIndex){
	if( stIndex >= endIndex ) return;
	int pivIndex = stIndex + (endIndex - stIndex)/2;
	
	int Index = Partition(arr, stIndex, pivIndex, endIndex);
	QuickSort(arr, stIndex, Index - 1);
	QuickSort(arr, Index +1, endIndex);
	
}

int main(){
	/*Lnode* head = new Lnode(0);
	Lnode * itr = head;
	for(int i = 1; i <5 ; i++){
		itr->next = new Lnode(i);
		itr= itr->next;
	}*/
	
	Tnode * root = new Tnode(4);
	root->left = new Tnode(1);
	root->right = new Tnode(2);
	root->left->left = new Tnode(3);	
	root->left->right = new Tnode(5);
	root->right->left = new Tnode(7);
	root->right->right = new Tnode(9);


	/*
	printL(head);
	cout<<"\n";
	*/
	printTreeIn(root);
	//cout<<"\n";
	//printLevel(root);
	int arr[5] = {5,4,2,3,1};
	cout<<"\n";
	cout<<"\n the counter is :"<<InsSort(arr, 5);
	for(int i = 0 ; i < 5 ; i++){
		std::cout<<arr[i];
	}
	//printBoundary(root);
	cout<<"\n enter any number + enter to terminate prog";
	int y;
	cin>>y;
	return 1;
}
int InsSort(int arr[], int num){
    int k = 1;
    int counter = 0;
    while(k < num){
        int j = k-1;
        for ( ;j>=0; j--){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                counter++;
            }
        }
        k++;
    }
    return counter ;
}