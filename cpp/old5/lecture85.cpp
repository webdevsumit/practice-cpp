#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template <typename T>
class graph {
    public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction){
        // direction == 0 -> undirected graph
        // direction == 1 -> directed graph

        // create an edge from u to v
        adj[u].push_back(v);

        if(direction == 0) adj[v].push_back(u);

    }

    void printAdjList(){
        for(auto i:adj){
            cout<< i.first << " -> ";
            for(auto j: i.second){
                cout<< j << ", ";
            }
            cout<<endl;
        }
    }


};

int main(){

    int n;
    cout<< "Enter the number of nodes :";
    cin>> n;

    int m;
    cout<< "Enter the number of edges :";
    cin>> m;

    graph<int> g;

    // 0 1
    // 1 2
    // 2 3
    // 3 1
    // 3 4

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        // creating undirected graph
        g.addEdge(u, v, 0);
    }

    // printing the graph
    g.printAdjList();

    return 0;
}