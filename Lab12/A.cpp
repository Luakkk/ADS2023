#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n;
	int d[n][n];
	set<int> skip; 
	for (int i = 0; i < n; i++) {
		skip.insert(i);
		for (int j = 0; j < n; j++) {
			cin >> d[i][j];
		}
	}
	
	for (int q = 0; q < n; q++) {
		cin >> x;
		x--;
		skip.erase(x); 
		int res = 0;
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				if (skip.find(i) != skip.end()){
                    continue; 
                } 
				for (int j = 0; j < n; j++) {
					if (skip.find(j) != skip.end()) {
                        continue;
                    } 
					if (d[i][j] > d[i][k] + d[k][j]) {
						d[i][j] = d[i][k] + d[k][j];
					}
				}
			}
		}
		for (int i = 0; i < n; i++) { 
			if (skip.find(i) != skip.end()) {
                continue;
            }
			for (int j = 0; j < n; j++) {
				if (skip.find(j) != skip.end()){
                    continue;
                } 
				res = max(res, d[i][j]); 
			}
		}
		cout << res << "\n";
	}
    return 0;
}