#include<iostream>
#include<list> 
#include<vector>
#include<queue>
using namespace std;

void addedge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool iscycle(int s, int parent, vector<int> adj[], vector<bool> &vis){
    vis[s] = 1;
    for(auto i: adj[s]){
        if(vis[i]==false){
            if(iscycle(i, s, adj, vis)) return true;
        }
        else if(i!=parent) return true;
    }
    return 0;
}

int main(){
    int v; 
    cin >> v;
    if(v==0){
        cout<< "empty"<< endl;
        return 0;

    }
    vector<int> adj[v];
    // for(int i=0;i<v;i++){
    //     int u,v;cin >> u,v;
    //     addedge(adj, u ,j);
    // }
    addedge(adj, 0, 1);
    addedge(adj, 1, 2);
    addedge(adj, 2, 3);
    addedge(adj, 1, 3);
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(iscycle(i, -1, adj , visited)==true ){
                cout << "cycle exist" << endl;
                return 0;
            }
        }  
        
    }
    cout << " no cycle";
    return 0;


}