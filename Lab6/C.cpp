#include <bits/stdc++.h>

using namespace std;

void swap(vector<int>& arr, int pos1, int pos2){
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

int partition(vector <int> &arr, int low, int high){
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

void quickSort(vector <int> & arr, int low, int high){
	if(low < high){
	int pivot = partition(arr, low, high);
	quickSort(arr, low, pivot-1);
	quickSort(arr, pivot+1, high);
	}
}

void print(vector <int> &arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << ' ';
    }
}

int main(){
    int n;
    vector<int> arr;
    vector<int> arr1;
    cin >> n;
    for (int i = 0; i < n; i++){
        int b;
        cin >> b;
        arr.push_back(b);
    }
    int diff = INT_MAX;
    quickSort(arr, 0, arr.size() - 1);
    for(int i = 0; i < arr.size(); i++){
        if (abs(arr[i + 1] - arr[i]) <= diff){
            diff = abs(arr[i] - arr[i + 1]);
        }
    }

    for (int i = 0; i < arr.size(); i++){
        if(abs(arr[i + 1] - arr[i])  == diff){
            if(i + 1 < arr.size()){
                arr1.push_back(arr[i]);
                arr1.push_back(arr[i + 1]);
            }
        }
    }
    print(arr1);
}