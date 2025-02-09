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
        cout << arr[i]; 
    }
}

void vowels( vector <char> & v, vector <char> & s){
    for (int i = 0; i < v.size(); i++){
        if(v[i] == 'a' || v[i] == 'e' || v[i] == 'i'
            || v[i ]== 'o' || v[i] == 'u') {
                s.push_back(v[i]);
            }
    }

}

int main(){
    int n;
    cin >> n;
    vector<char> arr;
    for (int i = 0; i < n; i++){
        char b;
        cin >> b;
        arr.push_back(b);
    }
    int cnt;
    vector<char> vow;
    vowels(arr, vow);
    quickSort(vow, 0, vow.size() - 1);

    // for(int i = 0; i < arr.size(); i++){
    //     while(i != arr.size()){
    //         if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i'
    //         || arr[i]== 'o' || arr[i] == 'u'){
    //             arr.erase(i);
    //         }
    //     }
// }
    for (auto i = arr.begin(); i != arr.end(); ++i) {
        if (*i == 'a' || *i == 'e' || *i == 'i'
            || *i == 'o' || *i == 'u') {
            arr.erase(i);
            i--;
        }
    }
    quickSort(arr, 0, arr.size() - 1);
    print(vow);
    print(arr);
   
     
}