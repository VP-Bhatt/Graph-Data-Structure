#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int numvertices;
    list<int> *adjlists;
    bool *visited;
    vector<int> ans;
    public:
    Graph(int vertices);
    void addEdge(int src , int des);
    void dfs(int startvertex);
    void print();
    
};
Graph::Graph(int vertices){
    numvertices = vertices;
    adjlists = new list<int>[numvertices];
    visited = new bool[numvertices];
}
void Graph::addEdge(int src,int des){
    adjlists[src].push_back(des);
}

void Graph::dfs(int vertex){
    visited[vertex] = true;
    list<int> adjList = adjlists[vertex];
    ans.push_back(vertex);

    list<int>::iterator it;

    for(it = adjList.begin(); it != adjList.end();it++){
        if(!visited[*it]){
            dfs(*it);
        }
    }
}
void Graph::print(){
    for(int i=0;i<ans.size();i++){
        cout << ans[i]<<" ";
    }
    cout << endl;
}

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.dfs(0);
    g.print();
    return 0;
}