#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
 
struct Edge {
    int src, dest, weight;
};
 
struct compare
{
    bool operator() (Edge const &a, Edge const &b) const {
        return a.weight > b.weight;
    }
};
 
class DisjointSet
{
    unordered_map<int, int> parent;
 
public:
    void makeSet(int n)
    {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
 
    int Find(int k)
    {
        if (parent[k] == k) {
            return k;
        }
 
        return Find(parent[k]);
    }

    void Union(int a, int b)
    {
        int x = Find(a);
        int y = Find(b);
 
        parent[x] = y;
    }
};
 

vector<Edge> runKruskalAlgorithm(vector<Edge> edges, int n)       
{
    vector<Edge> MST;
    DisjointSet ds;
    ds.makeSet(n);
    sort(edges.begin(), edges.end(), compare());
 
    while (MST.size() != n - 1)
    {
        Edge next_edge = edges.back();
        edges.pop_back();
 
        int x = ds.Find(next_edge.src);
        int y = ds.Find(next_edge.dest);

        if (x != y)
        {
            MST.push_back(next_edge);
            ds.Union(x, y);
        }
    }
    return MST;
}
 
int main()
{   
    int a;
    int b;
    cin >> a;
    vector<Edge> edges;
    vector<int> cost;
    for(int i = 0; i < a; i++){
        cin >> b;
        cost.push_back(b);
    }

    for(int i = 0; i < a; i++){
        for(int j = 1; j < a; j++){
            if(i != j)
                edges.push_back({i, j, cost[i] + cost[j]});
        }
    }
    vector<Edge> e = runKruskalAlgorithm(edges, a);
    int sum = 0;
    for (Edge &edge: e)
    {
        sum = sum + edge.weight;
    }
    cout << sum;
    return 0;
}
