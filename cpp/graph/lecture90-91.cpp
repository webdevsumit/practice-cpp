#include <bits/stdc++.h> 
#include <unordered_map>
#include <list>
#include <stack>

// void topoSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj){
//     visited[node] = 1;
//     for(auto neighbour: adj[node]){
//         if(!visited[neighbour]){
//             topoSort(neighbour, visited, s, adj);
//         }
//     }
//     s.push(node);
// }

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    // Create adj List
    unordered_map<int, list<int>> adj;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    
    //
    // ***********USING DFS "STARTED"***********
    //
    
    // Call the dfs...
//     vector<bool> visited(v);
//     stack<int> s;
//     for(int i=0; i<v; i++){
//         if(!visited[i]){
//             topoSort(i, visited, s, adj);
//         }
//     }
    
//     vector<int> ans;
//     while(!s.empty()){
//         ans.push_back(s.top());
//         s.pop();
//     }
    
//     return ans;
    
    //
    // ***********USING DFS "ENDED"***********
    //
    
    //
    // ***********USING BFS / KAHN'S ALGORITHM "STARTED"***********
    //
    
    // find all indegrees
    vector<int> indegree(v);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    
    // 0 degree walo ko push karo
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    // Do BFS
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        // ans store
        ans.push_back(front);
        
        // neighbour indegree updation...
        for(auto n: adj[front]){
            indegree[n]--;
            if(indegree[n] == 0){
                q.push(n);
            }
        }
    }
    
    return ans;
    
    //
    // ***********USING BFS KAHN'S ALGORITHM "STARTED"***********
    //
}