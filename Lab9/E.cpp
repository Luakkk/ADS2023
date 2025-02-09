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
    int g;
    int n;
    int s1;
    int s2;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s >> g;
        vector<int> res = prefix_function(s);
        s1 = s.size() * g;
        s2 = res[res.size() - 1] * g;
        cout << (s1 - s2) + res[res.size() - 1] << "\n";
    }
}