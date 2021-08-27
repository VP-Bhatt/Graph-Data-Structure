#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addedge(vector<int> adj[],int src, int des){
    adj[src].push_back(des);
}

void dist(vector<int> adj[],int v,int src){
    vector<int> dis(v,INT_MAX);
    dis[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto it: adj[u]){
            if(dis[u]+1 < dis[it]){
                dis[it] = dis[u]+1;
                q.push(it);
            }

        }
    }
    for(int i=0;i<v;i++){
        cout << dis[i] << " ";
    }
}

int main(){
    int v = 6;
    vector<int> adj[v];
    addedge(adj,0,4);
    addedge(adj,0,5);
    addedge(adj,4,1);
    addedge(adj,5,2);
    addedge(adj,2,3);
    addedge(adj,3,1);
    dist(adj,v,0);
    return 0;
}