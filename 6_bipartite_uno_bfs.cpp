#include<iostream>
#include<queue>
#include<vector>
using namespace std;

    

void addedge(vector<int> adj[], int src,int des){
    adj[src].push_back(des);
    adj[des].push_back(src);
}

bool isbipartite(int s, vector<int> adj[], vector<int> col){
    col[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto it: adj[u]){
            if(col[it]==-1){
                col[it] = !col[u];
                q.push(it);

            }
            else if ( col[it] == col[u]){
                return false; 
            }
        }
    }
    return true;
}

int main(){

    int v=7; 
    vector<int> adj[v];
    vector<int> col(v, -1);
    addedge( adj,0,1);
    addedge( adj,1,2);
    addedge( adj,2,3);
    addedge( adj,3,4);
    addedge( adj,4,0);
    addedge( adj,4,5);
    addedge( adj,5,6);

    for(int i=0;i<v ;i++){
        if(col[i] == -1){
            if(!isbipartite(0, adj, col)){
                cout << "not";
                return 0;
            }
        }
    }
    cout << "yes";
    return 0;

}