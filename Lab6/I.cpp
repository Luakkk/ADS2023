#include <bits/stdc++.h>

using namespace std;

void swap(string & arr, int pos1, int pos2){
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

int partition(string &arr, int low, int high){
	int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap (arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(string & arr, int low, int high){
	if(low < high){
	int pivot = partition(arr, low, high);
	quickSort(arr, low, pivot-1);
	quickSort(arr, pivot+1, high);
	}
}



int main(){
    string n ;
    cin >> n;
	quickSort(n, 0 , n.size() - 1);
	cout << n;
	
   

}