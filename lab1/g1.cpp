#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ok(vector<int>v, int f, int x){
    int cnt = 0;
    for(int i = 0; i<v.size(); i++){
        if(v[i]%x == 0){
            cnt += v[i]/x;
        }
        else{
            cnt += v[i]/x + 1;
        }
    }
    return cnt <= f;
    
}
int main(){
    int n,f; cin >> n >> f;
    vector<int> v;
    while(n--){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());

    int l = 1;
    int r = v[v.size()-1];
    while(r - l> 1){
        int m = (l + r)/2;
        if(ok(v,f,m)){
            r = m;
        }
        else{
            l = m;
        }
    }
    if(r == 0){
        r= 1;
    }
    cout << r;
}