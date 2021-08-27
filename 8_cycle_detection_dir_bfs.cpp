#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addedge(vector<int> adj[],int src, int des){
    adj[src].push_back(des);
}

bool iscycle(vector<int> adj[],int v){
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
    int count =0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        count++;
        for(auto it: adj[u]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    if(count == v){
        return true;
    }
    return false;
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
    if(iscycle(adj , v)){
        cout << "true" << endl;
        return 0;
    }
    cout << "false";
    return 0;

}