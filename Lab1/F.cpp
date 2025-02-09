#include <bits/stdc++.h>
using namespace std;

bool a[10000];
deque <int> primes;

void find_primes(int n){
    for(int i = 2; i <= n; i++){
        a[i] = true;
    }

    for(int i = 2; i <= n; i++){
        if(a[i] == true){
            primes.push_back(i);

            for(int j = i * i; j <= n; j+=i){
                a[j] = false;
            }
        }
    }
}


int main(){
    int n;
    cin >> n;
    find_primes(10000);
    for(int i = 0; i < n - 1; i++){
        primes.pop_front();
    }
    cout << primes.front();
}