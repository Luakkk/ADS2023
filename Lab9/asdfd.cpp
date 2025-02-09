#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s[n];
    string d[n];
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    int max = s[0].length();
    for(int i = 0; i < n; ++i){
        if(s[i].length() > max){
            max = s[i].length();
            d[i] = s[i];
        }
    }

    for(int i = 0; i < n; i++){
        cout << d[i] << " ";
    }
}