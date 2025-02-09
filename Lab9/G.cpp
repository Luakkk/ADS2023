#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

vector<int> kmp(string s, string t) {
    s = t + '#' + s;
    vector<int> res;
    vector<int> pi = prefix_function(s);
    for (int i = 0; i < s.size(); i++) {
        if (pi[i] == t.size()) {
            res.push_back(i - 2 * t.size());
        }
    }
    return res;
}

int main(){
    string s;
    cin >> s;
    long long t = (int)s.length();
    long long cnt = 0;
    vector<int> sum = prefix_function(s);
    // for(int i = 0; i < t; i++){
    //     if(sum[i] == 0){
    //         cnt++;
    //     }
    // }
    cout << t - sum[sum.size() - 1];
}