#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void addedge(vector<int> adj[],int src, int des){
    adj[src].push_back(des);
    adj[des].push_back(src);
}
bool isbipartite(vector<int> adj[],vector<int> col,int s){
    if(col[s]==-1) col[s] =1;
    for(auto it : adj[s]){
        if(col[it] == -1){
            col[it] = 1 - col[s];
            if(!isbipartite(adj, col, it)){
                return false;
            }
        }
        else if(col[it] == col[s]){
            return false;
        }
    }
    return true;
}

int main(){
    int v = 7;
    vector<int> adj[v];
    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,2,3);
    addedge(adj,3,4);
    addedge(adj,4,5);
    addedge(adj,5,0);
    addedge(adj,4,6);

    vector<int> col(v,-1);
    for(int i=0;i<v;i++){
        if(col[i]== -1){
            if(!isbipartite( adj, col, i)){
                cout << "Non - bipartite" ;
                return 0;
            }
        }
    }
    cout << " Bipartite " ;
    return 0;

}