#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    long long a[n], b[n];
    long long count = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        count += a[i];
        b[i] = count;
    }
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        int left = 0, right = n, cnt = 0;
        while(left < right){
            int mid = (left + right) / 2;
            if(b[mid] == x){
                cout << mid + 1 << endl;
                cnt++;
                break;
            }
            else if(b[mid] > x){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        if(cnt == 0){
            cout << left + 1 << endl;
        }

    }

}