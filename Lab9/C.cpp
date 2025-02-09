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
    string t;
    cin >> t >> s;
    string s1;
    s1 = s;
    s = s1 + s;
    vector<int> res = kmp(s,t);
    if(res.size() == 1){
        cout << res[0];
    }
    else{
        cout << -1;
    }

}