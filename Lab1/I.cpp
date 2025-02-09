#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    deque <int> s_deque, k_deque;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'S'){
            s_deque.push_back(i);
        }
        else{
            k_deque.push_back(i);
        }
    }
    while(!s_deque.empty() and !k_deque.empty()){
        if(s_deque.front() < k_deque.front()){
            k_deque.pop_front();
            s_deque.push_back(s_deque.front() + s.size());
            s_deque.pop_front();
        }
        else{
            s_deque.pop_front();
            k_deque.push_back(k_deque.front() + s.size());
            k_deque.pop_front();
        }
    }
    if(s_deque.empty()){
        cout << "KATSURAGI";
        return 0;
    }
    cout << "SAKAYANAGI";
    return 0;
    
}