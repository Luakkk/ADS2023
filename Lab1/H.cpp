#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
    deque <int> d;
	for(int i = 1; i <= n; i++){
		if(n % i == 0){
            d.push_back(i);
		}
	}

    if(d.size() == 2){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
	return 0;
}