#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void addedge(vector<int> adj[], int src, int des){
    adj[src].push_back(des);
}

void dfs(vector<int> adj[], int s, vector<int> &vis, stack<int> &st){
    vis[s] = 1;
    for(auto it : adj[s]){
        if(!vis[it]){
            dfs(adj, it, vis, st);
        }
    }
    st.push(s);
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
    vector<int> vis(v,0);
    stack<int> s;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(adj,i,vis,s);
        }
    }
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}