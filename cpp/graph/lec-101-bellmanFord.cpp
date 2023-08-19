#include <iostream>
#include<vector>
using namespace std;

// Bellman Ford Algo...
// Finding the shortest path in graph with -ve weights ....
// n-1 loops
// then 1 loop to check the cycle...

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    
    // distance
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;
    
    for(int i=1; i<=n; i++){
        // traverse on edge list
        for(int j=0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            
            if(dist[u] != 1e9 && ((dist[u] + w) < dist[v])){
                dist[v] = dist[u] + w;
            }
        }
    }
   
    // check -ve cycle
   bool flag = false;
    
    for(int j=0; j<m; j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];
        
        if(dist[u] != 1e9 && ((dist[u] + w) < dist[v])){
            flag = true;
        }
    }

    if(flag == false) return dist[dest];
    return -1;
}

int main() {
    return 0;
}