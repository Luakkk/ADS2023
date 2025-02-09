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



int main(){
   int n;
   int s;
   vector<int> arr;
   vector<int> v;
   cin >> n;
   cin >> s;
   for (int i = 0; i < n; i++){
        int b;
        cin >> b;
        arr.push_back(b);
   }

   for (int i = 0; i < s; i++){
        int b;
        cin >> b;
        v.push_back(b);
   }
   
   quickSort(arr, 0, arr.size() - 1);
   quickSort(v, 0, v.size() - 1);

   vector<int> mat(arr.size() + v.size());
   vector<int>::iterator it;

   it = set_intersection(arr.begin(), arr.end(), v.begin(), v.end(), mat.begin());
    
   for (int i = 0; i < mat.size(); i++){
        if(mat[i] != 0){
            cout << mat[i] << " ";  
        }
        else{
            break;
        }
   }
   

}
