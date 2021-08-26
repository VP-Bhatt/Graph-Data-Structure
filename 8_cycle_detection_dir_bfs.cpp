#include<iostream>
#include<vector>
using namespace std;

void addedge(vector<int> adj[] ,int src , int des ){
    adj[src].push_back(des);
}

int main(){
    int v = 6;
    vector<int> adj[v+1];
    addedge(adj,1,2);
    addedge(adj,2,3);
    addedge(adj,3,4);
    addedge(adj,4,5);
    addedge(adj,5,6);
    vector<int> vis(v+1,0);
    vector<int> dfsvis(v+1,0);

    for(int i=1;i<v+1;i++){
        if(vis[i]==0){
            if(iscycle(adj,vis,dfsvis,i)){
                cout << "cycle" ;
               return 1; 
            }
        }
    }
    cout << "cycle not found";
    return 0;


}