#include <iostream>
using namespace std;

int count(int a[], int size, long long mid){
    int cnt = 0;
    long long temp_sum = 0;

    for(int i = 0; i < size; i++){
        if(temp_sum + a[i] > mid){
            cnt++;
            temp_sum = a[i];
        }
        else if(temp_sum + a[i] == mid){
            if(i != size - 1){
                cnt++;
            }
            temp_sum = 0;
        }
        else{
            temp_sum += a[i];
        }
    }
    return cnt;

}

long long count2(int a[], int size, long long mid){
    long long temp_sum = 0;
    long long max_sum = -1;
    for(int i = 0; i < size; i++){
        if(temp_sum + a[i] > mid){
            if(temp_sum > max_sum){
                max_sum = temp_sum;
            }
            temp_sum = a[i];
        }
        else if(temp_sum + a[i] == mid){
            if(temp_sum + a[i] > max_sum){
                max_sum = temp_sum + a[i];
            }
            temp_sum = 0;
        }
        else{
            temp_sum += a[i];
        }
    }
    return max_sum;
}
int main(){
    int n, k;
    cin >> n >> k;
    int a[n];

    long long left = 1, right = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        right += a[i];
    }

    while(left < right){
        long long mid = left + (right - left) / 2;
        int t = count(a, n, mid);

        if(t > k-1){
            left = mid + 1;
        }

        else if(t <= k-1){
            right = mid;
        }
    }

    cout << count2(a, n, left);
}
