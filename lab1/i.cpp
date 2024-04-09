#include <iostream>
#include <deque>

using namespace std;
int main(){
int n;   cin >> n;
string strg;
cin >> strg;
deque <int> d;
deque <int> d2;
for(int i = 0; i < strg.size(); i++)
{
    if(strg[i] == 'S'){
        d.push_back(i);
    }
    if(strg[i] == 'K'){
        d.push_back(i);
    }
    }
    while(!d.empty() && !d2.empty()){
        if(d.front() < d2.front()){
            d.push_back(d.front() + strg.size());
            d.pop_front();
            d2.pop_front();
            continue;
        }
        else{
        d2.push_back(d2.front() + strg.size());
        d2.pop_front();
        d.pop_front();
        }
        }
        if(!d.empty()){
            cout << "SAKAYANAGI";
            return 0 ;
        }
        if(!d2.empty()){
        cout << "KATSURAGI";
        return 0;
        
        }

    }

