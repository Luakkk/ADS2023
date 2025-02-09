#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);

    int p;
    cin >> p;
    for(int i = 0; i < p; i++){
        int x;
        cin >> x;
        int startindex = -1,  endindex = -1;

        int left = 0, right = n-1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(a[mid] == x){
                startindex = mid;
                right = mid - 1;
            }
            else if(a[mid] > x){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        left = 0, right = n-1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(a[mid] == x){
                endindex = mid;
                left = mid + 1;
            }
            else if(a[mid] > x){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        if(endindex == -1 ){
            endindex = right;
        }
        int ans = 0;
        for(int i = 0; i < endindex+1; i++){
            ans += a[i];
        }
        cout << endindex + 1 << ' ' << ans << endl;  
    }
}