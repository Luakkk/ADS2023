#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[100000];
bool used[100000];

int main(){
    int n;
    cin >> n;
    int a[n][n];
    int weight = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            graph[i].push_back({j, a[i][j]});
            graph[j].push_back({i, a[i][j]});
        }
    }
    
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >q;
    q.push({0, 1});

    while(!q.empty()){
        pair<int,int> p = q.top();
        q.pop();
        int v = p.second;
        int mst = p.first;
        
        if(used[v]){
            continue;
        }
        weight += mst;
        used[v] = true;
        

        for(pair<int, int> ind : graph[v]){
            int u = ind.first, length = ind.second;
            if(!used[u]){
                q.push({length, u});
            }
        }
    }
    cout << weight << endl;
    return 0;
}