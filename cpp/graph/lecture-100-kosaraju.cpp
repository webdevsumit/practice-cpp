#include<iostream>
#include<unordered_map>
#include<stack>
#include<list>

using namespace std;

void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, unordered_map<int, list<int>> &adj){
    vis[node] = true;
    for(auto nbr: adj[node]){
        if(!vis[nbr]){
            dfs(nbr, vis, st, adj);
        }
    }
    // Topo logic
    st.push(node);
}


void dfs2(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj){
    vis[node] = true;
    for(auto nbr: adj[node]){
        if(!vis[nbr]){
            dfs2(nbr, vis, adj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges){
    // Create adjacency list
	unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    
    // Topological sort
    stack<int> st;
    unordered_map<int, bool> vis;
    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(i, vis, st, adj);
        }
    }
    
    // Creating a transpose graph
    unordered_map<int, list<int>> trans;
    for(int i=0; i<v; i++){
        vis[i] = false;
        for(auto nbr: adj[i]){
            trans[nbr].push_back(i);
        }
    }
    
    // dfs using above topo sort
    int count = 0;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        if(!vis[top]) {
            count++;
            dfs2(top, vis, trans);
        }
    }
    
    return count;
}