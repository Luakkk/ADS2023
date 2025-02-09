#include <iostream>
#include <vector>
using namespace std;

vector<int> prefixFunction(string s) {
    vector<int> pi(s.size());
    pi[0] = 0;
    for (int i = 1; i < s.size(); i++) {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i]) {
            j = pi[j - 1];
        }
        if (s[j] == s[i]) {
            pi[i] = j + 1;
        } else {
            pi[i] = 0;
        }
    }

    return pi;
}
 
int kmp(string s, string t){
    int a = s.length();
    int b = t.length();
    int cnt = 1;
    bool ok = false;
    for (int i = 0; i < a; i++){
        int j = i;
        int k = 0;
        while(k < b && s[j] == t[k]){
            if(k == b - 1){
                ok = true;
                break;
            }
            j = (j + 1) % a;
            if(j == 0){
                cnt++;
            }
            k++;
        }
        if (ok == true){
            return cnt; 
        }
    }
    return -1;

}


// Driver program to test above function
int main()
{
    string s;
    string t;
    cin >> s >> t;
    cout << kmp(s,t);
}