#include <iostream>
#include <deque>
using namespace std;
int main(){
int n;  cin >> n;
string s;
cin >> s;
deque <int> d1;
deque <int> d2;
for(int i = 0; i < s.size(); i++)
{
    if(s[i] == 'S'){
        d1.push_back(i);
    }
    if(s[i] == 'K'){
        d2.push_back(i);
    }
    }
    while(!d1.empty() && !d2.empty()){
        if(d1.front() < d2.front()){
            d1.push_back(d1.front() + s.size());
            d1.pop_front();
            d2.pop_front();
            continue;
        }
        else{
        d2.push_back(d2.front() + s.size());
        d2.pop_front();
        d1.pop_front();
        }
        }
        if(!d1.empty()){
            cout << "SAKAYANAGI";
        }
        if(!d2.empty()){
        cout << "KATSURAGI";
        }
    return 0;
    }

