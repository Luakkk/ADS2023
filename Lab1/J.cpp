#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    deque <int> d;
    int x;
    getline(cin, s);
    if(s[0] == '+' or s[0] == '-'){
        x = stoi(s.substr(2, s.size() - 2));
    }

    while(s[0] != '!'){
        if(s[0] == '+'){
            d.push_front(x);
        }
        else if(s[0] == '-'){
            d.push_back(x);
        }
        else if(s[0] == '*'){
            if(d.size() == 0){
                cout << "error" << endl;
            }
            else if(d.size() != 0){
                cout << d.front() + d.back() << endl;
                d.pop_front();
                if(d.size() != 0){
                    d.pop_back();
                }
            }
        }
        getline(cin, s);
        if(s[0] == '+' or s[0] == '-'){
            x = stoi(s.substr(2, s.size() - 2));
        } 
    }
}