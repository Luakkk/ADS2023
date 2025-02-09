#include <bits/stdc++.h>

using namespace std; 
 
const int N = 1e4;
const int inf = 1e9;


int x[N], y[N];
int p[N];

int get(int v) {
    if(v == p[v]) {
        return v;
    }
    return p[v] = get(p[v]);
}

bool merge(int a, int b) {
    a = get(a);
    b = get(b);
    if(a == b){
        return 0;
    } 
    if(rand()%2) {
        swap(a, b);
    }
    p[b] = a;
    return 1;
}

void solve(int tc) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> x[i] >> y[i];
    }
    int l = 0, r = inf, ans;
    while(l <= r) {
    int md = l+r >> 1;
    for(int i = 1; i <= n; i ++) {
        p[i] = i;
    }
    for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= n; j ++) {
        if(abs(x[i]-x[j])+abs(y[i]-y[j]) <= md) merge(i , j);
    }
    }
    if(get(1) == get(n)) {
        ans = md;
        r = md - 1;
    }
    else {
        l = md + 1;
    }
    }
    cout << ans;
}

int main() {
    int t = 1 , c = 0;
    while(t --) {
        solve(++c);
    }
  
}
