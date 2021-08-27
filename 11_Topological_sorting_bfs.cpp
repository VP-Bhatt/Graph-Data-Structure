#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addedge(vector<int> adj[],int src, int des){
    adj[src].push_back(des);
}

vector<int> kahn(vector<int> adj[],int v){
    queue<int> q;
    vector<int> indegree(v,0);
    for(int i=0;i<v;i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(auto it: adj[u]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return topo;
}

int main(){
    int v = 6;
    vector<int> adj[v];
    addedge(adj,4,0);
    addedge(adj,5,0);
    addedge(adj,4,1);
    addedge(adj,5,2);
    addedge(adj,2,3);
    addedge(adj,3,1);
    vector<int> ans;
    ans = kahn(adj,v);
        
    for(int i =0;i<ans.size();i++){
        
        cout << ans[i] << " ";

    }

}