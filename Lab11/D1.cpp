#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define INF 9999999

// number of vertices in grapj

// create a 2d array of size 5x5
//for adjacency matrix to represent graph
bool isValidEdge(int u, int v, vector<bool> inMST)
{
   if (u == v)
       return false;
   if (inMST[u] == false && inMST[v] == false)
        return false;
   else if (inMST[u] == true && inMST[v] == true)
        return false;
   return true;
}

int main() {
    int v;
    cin >> v;
    int cost[v][v];
    for(int i = 1; i <= v; i++){
      for(int j = 1; j <= v; j++){
        cin >> cost[i][j];
      }
    }
    vector<bool> inMST(v, false);
 
    // Include first vertex in MST
    inMST[0] = true;
 
    // Keep adding edges while number of included
    // edges does not become V-1.
    int edge_count = 0, mincost = 0;
    while (edge_count < v - 1) {
 
        // Find minimum weight valid edge. 
        int min = INF, a = -1, b = -1;
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {              
                if (cost[i][j] < min) {
                    if (isValidEdge(i, j, inMST)) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a != -1 && b != -1) {
            printf("Edge %d:(%d, %d) cost: %d ",
                         edge_count++, a, b, min);
            mincost = mincost + min;
            inMST[b] = inMST[a] = true;
        }
    }
    printf(" Minimum cost= %d ", mincost);
}