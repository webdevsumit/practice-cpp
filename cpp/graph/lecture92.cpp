#include<unordered_map>
#include<list>
#include<queue>

// bool checkCycle(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj){
//     visited[node] = true;
//     dfsVisited[node] = true;
    
//     for(auto neighbour: adj[node]){
//         if(!visited[neighbour]){
//             bool cycleDetected = checkCycle(neighbour, visited, dfsVisited, adj);
//             if(cycleDetected) return true;
//         }else if(dfsVisited[neighbour]){
//             return true;
//         }
//     }
//     dfsVisited[node] = false;
//     return false;
// }

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    // Create adjacency list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;
        adj[u].push_back(v);
    }
    
//     unordered_map<int, bool> visited;
//     unordered_map<int, bool> dfsVisited;
    
//     // call dfs for all components
//     for(int i=1; i<=n; i++){
//         if(!visited[i]){
//             bool cycleFound = checkCycle(i, visited, dfsVisited, adj);
//             if(cycleFound) return true;
//         }
//     }
//     return false;
    
    
    
//     *************USING KAHN'S ALGORITHM 'STARTED'*************
    
    // find all indegrees
    vector<int> indegree(n);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    
    // 0 degree walo ko push karo
    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    // Do BFS
    int cnt = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        // ans store
        cnt++;
         
        // neighbour indegree updation...
        for(auto neibhbour: adj[front]){
            indegree[neibhbour]--;
            if(indegree[neibhbour] == 0){
                q.push(neibhbour);
            }
        }
    }
    
    if(cnt == n) return false;
    else return true;
    
//     *************USING KAHN'S ALGORITHM 'ENDED'*************
}