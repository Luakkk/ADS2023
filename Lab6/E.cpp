#include<bits/stdc++.h>

using namespace std;

int partition(vector<vector<int>> &v, int low, int high, int col){
    int pivot = v[high][col];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(v[j][col] > pivot){
            i++;
            swap(v[i][col], v[j][col]);
        }
    }
    swap(v[i + 1][col], v[high][col]);
    return i + 1;
}

void quickSort(vector<vector<int>> &v, int low, int high, int col){
    if(low < high){
        int pi = partition(v, low, high, col);
        quickSort(v, low, pi - 1, col);
        quickSort(v, pi + 1, high, col);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;
    for(int i = 0; i < n; i++){
        vector<int> row(m);
        for(auto &j : row) cin >> j;
        v.push_back(row);
    }
    
    for(int i = 0; i < m; i++){
        quickSort(v, 0, n-1, i);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    
}