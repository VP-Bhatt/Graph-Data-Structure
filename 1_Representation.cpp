#include<iostream>
#include<vector> 

using namespace std;

int main(){
    int n,m; // n-> no. of nodes in a graph, m->no. of edges in a graph 
    cin >> n >> m;
    //If graph is not weighted
    vector<int> adj[n+1]; // Declaration of adjacency matrix
    for(int i=0;i<m;i++){
        int u,v;       // edges between node u and v
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);    // Remove this code line if graph is directed: as it resembles the reverse direction.
    }
    //If graph is weighted 
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v,w;             // w is weight of edge between node u and v
        cin >> u >> v >> w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); // Remove this code line if graph is directed: as it resembles the reverse direction.
    }  
    return 0;
}