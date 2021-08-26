#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

void addedge(vector<int> adj[],int u,int v ){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool iscycle(vector<int> adj[],int  s,int v, vector<bool> &visited){
    vector<int> parent(v,-1);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto it: adj[u]){
            if(!visited[it]){
                q.push(it);
                visited[it] = true;
                parent[it] = u;
            }
            else if(parent[u]!=it){
                return true;
            }
        }
    }
    return false;

}

int main(){
    int numvertices=4;
    // cin >> numvertices;
    vector<int> adj[numvertices];
    // for(int i=0;i<numvertices;i++){
    //     int u,v;
    //     cin >> u >> v ;
    //     addedge(adj , u, v);
    // }
    addedge(adj, 0, 1);
    addedge(adj, 1, 2);
    addedge(adj, 2, 3);
    addedge(adj, 1, 3);
    int startvertex=0;
    // cin >> startvertex;
    vector<bool> visited(numvertices , false);

    for(int i=0;i<numvertices;i++){
        if(!visited[i] && iscycle(adj,startvertex,numvertices,visited)){
            cout << "true";
            return true;
        }
        cout << "false";
        return false;
    }
    return 0;                                     
}