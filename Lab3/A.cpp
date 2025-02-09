#include <iostream>
using namespace std;

int binary_search(int x, int a[], int size){
    int left = 0, right = size;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(a[mid] == x){
            return mid;
        }
        else if(a[mid] > x){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    if(a[left] != x){
        return -1;
    }
    return left;
}

int main(){
    int t;
    cin >> t;
    int a[t];

    for(int i = 0; i < t; i++){
        cin >> a[i];
    }

    int n, m;
    cin >> n >> m;
    int matrix[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }


    for(int i = 0; i < t; i++){
        //find a[i]
        int left = 0, right = n;
        while(right - left > 1){
            int mid = left + (right - left) / 2;
            if(mid % 2 == 1){
                if(matrix[mid][m-1] >= a[i]){
                    left = mid;
                }
                else{
                    right = mid;
                }
            }
            else{
                if(matrix[mid][0] >= a[i]){
                    left = mid;
                }
                else{
                    right = mid;
                }
            }
        }


        if(left % 2 == 1){
            if(binary_search(a[i], matrix[left], m) == -1){
                cout << -1 << endl;
            }
            else{
                cout << left << ' ' <<  binary_search(a[i], matrix[left], m) << endl;
            }
        }

        else{
            int left1 = 0, right1 = m, cnt = 0;
            int mid1 = left1 + (right1 - left1)/2;
            while(left1 <= right1){
                if(matrix[left][mid1] == a[i]){
                    cout << left << ' ' << mid1 << endl;
                    cnt++;
                    break;
                }
                else if(matrix[left][mid1] > a[i]){
                    left1 = mid1 + 1;
                }
                else{
                    right1 = mid1 - 1;
                }
                mid1 = left1 + (right1 - left1)/2;
            }
            if(cnt == 0){
               
                if(matrix[left][left1] != a[i] or matrix[left][right1] != a[i]){
                    cout << -1 << endl;
                }
                else{
                    cout << left << ' ' << left1 << endl;
                } 
            }
        }
    }

    

}