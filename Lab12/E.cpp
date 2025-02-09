#include <bits/stdc++.h>

using namespace std;

vector<int>graph[410];
vector<int>graph1[410];
int arr[505][505];


struct Edge {
    int a, b, weight;
};

int n, m, v;
vector<Edge> e;
const int INF = 1e9;
bool cycle = false;
void solve() {
    vector<int> d (n, INF);
    d[v] = 0;
    vector<int> p (n, -1);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (int j = 0; j < n * n; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].weight) {
                    d[e[j].b] = max (-INF, d[e[j].a] + e[j].weight);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
    }

    if (x == -1)
        cycle = false;
    else {
        int y = x;
        for (int i=0; i<n; ++i)
            y = p[y];

        vector<int> path;
        for (int cur=y; ; cur=p[cur]) {
            path.push_back (cur);
            if (cur == y && path.size() > 1)  break;
        }
        reverse (path.begin(), path.end());

        cout << "YES" << endl;
        cout << path.size() << endl;
        for (size_t i=0; i<path.size(); ++i)
            cout << path[i] + 1 << ' ';
        cout << endl;
        cycle = true;
    }
}

int main(){
    cin >> n;
    vector<int> d(n, INF);
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            Edge cur;
            cin >> cur.weight;
            cur.a = i; cur.b = j;
            e.push_back(cur);
        }
    }

    for (int i = 0; i < n; i ++){
        v = i;
        solve();
        if (cycle) break;
    }
    if (!cycle) cout << "NO" << endl;
}