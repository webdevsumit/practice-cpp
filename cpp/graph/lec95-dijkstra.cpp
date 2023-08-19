#include <iostream> 
#include<stack>
#include<unordered_map>
#include <list>
#include<set>
#include<vector>
using namespace std;

// Shortest path of every single node from the source....
// Here "distance" means distance from the source... 
// Doesn't work on graph with -ve wieghts...

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create adj
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
        
    }
    
    vector<int> dist(vertices);
    for(int i=0; i<vertices; i++){
        dist[i] = INT_MAX;
    }
    
    // first = distance
    // second = node
    // set will be sorted according to the distance....
    set<pair<int, int>> st;
    dist[source] = 0;
    st.insert(make_pair(0, source));
    
    while(!st.empty()){
        auto top = *(st.begin());
        
        int nodeDistance = top.first;
        int topNode = top.second;
        
        st.erase(st.begin());
        
        for(auto neighbour: adj[topNode]){
            // neighbour.first is a node
            if(nodeDistance + neighbour.second < dist[neighbour.first]){

                // try to find old record for the same neighbour node
                // neighbour.first is a node
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                // erase old record if exists
                if(record != st.end()) st.erase(record);
                
                // update distance
                // neighbour.first is a node
                // neighbour.second is the weight of the node
                dist[neighbour.first] = nodeDistance + neighbour.second;
                
                // insert record
                // dist[neighbour.first] evaluated above...
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}


int main(){
    return 0;
}