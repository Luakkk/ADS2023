#include <bits/stdc++.h>

using namespace std; 

vector<int>graph[410]; 
vector<int>graph1[410]; 
int arr[505][505]; 

int main(){ 
    int n;
    int m; 
    cin >> n >> m; 
    for(int i = 0; i < m;i++){ 
        int a;
        int b; 
        cin >> a >> b; 
        a--; 
        b--; 
        graph[a].push_back(b); 
        graph[b].push_back(a); 
        arr[a][b] = 1; 
        arr[b][a] = 1; 
    } 
    for (int i = 0; i < n; i ++){ 
        for (int j = 0; j < n; j ++){ 
            if (arr[i][j] == 0 && i != j){ 
                graph1[i].push_back(j); 
            } 
        } 
    } 
    queue <int> q1; 
    vector <int> d1(n+1); 
    vector <bool> used(n+1); 
    q1.push(0); 
    used[0] = true; 
    while(!q1.empty()){ 
        int v = q1.front(); 
        q1.pop(); 
        for(int i=0;i<graph[v].size();i++){ 
            int to = graph[v][i]; 
            if(!used[to]){ 
                used[to] = true; 
                q1.push(to); 
                d1[to] = d1[v]+1; 
            } 
        } 
    } 
    queue<int>q2; 
    vector<int>d2(n+1); 
    vector<bool>used2(n+1); 
    q2.push(0); 
    used2[0] = true; 
    while(!q2.empty()){ 
        int v = q2.front(); 
        q2.pop(); 
        for(int i=0;i<graph1[v].size();i++){ 
            int to = graph1[v][i]; 
            if(!used2[to]){ 
                used2[to] = true; 
                q2.push(to); 
                d2[to] = d2[v]+1; 
            } 
        } 
    } 
    if (!used[n-1] || !used2[n-1]){ 
        cout << -1; 
    } 
    else { 
        cout << max(d1[n-1], d2[n-1]); 
    } 
}