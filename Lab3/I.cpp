#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int x;
    cin >> x;
    
    int left = 0, right = n;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(a[mid] == x){
            cout << "Yes";
            return 0;
        }
        else if(a[mid] > x){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    if(a[left] == x){
        cout << "Yes";
        return 0;
    }
    cout << "No";
    return 0;
}