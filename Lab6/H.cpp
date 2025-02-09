#include <bits/stdc++.h>

using namespace std;

void swap(vector<char> & arr, int pos1, int pos2){
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

int partition(vector<char>  &arr, int low, int high){
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

void quickSort(vector<char> & arr, int low, int high){
	if(low < high){
	int pivot = partition(arr, low, high);
	quickSort(arr, low, pivot-1);
	quickSort(arr, pivot+1, high);
	}
}

void print(vector<char> & arr){
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << ' '; 
    }
}

int main(){
    int n;
    char g;
    cin >> n;
    vector <char> arr;
    for (int i = 0; i < n; i++){
        char b;
        cin >> b;
        arr.push_back(b);
    }
    
    quickSort(arr, 0, arr.size() - 1);
    cin >> g;

    for (int i = 0; i < arr.size(); i++){
        if (g - '0' != arr[0] - '0'){
            if(g - '0' < arr[0] - '0' || g - '0' > arr.back() - '0'){
                cout << arr[0];
                break;
            }
            if(g - '0' > arr[0] - '0' && g - '0' < arr.back() - '0'){
                i++;
                cout << arr[i+1];
                break;
            }
            else {
                cout << arr[0];
                break;
            }
        }
        else{
            cout << arr[i + 1];
            break;
        }
    }

    

}