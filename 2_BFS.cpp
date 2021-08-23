#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int numVertices;
    list<int>* adjlists; // pointer to list storing nodes of graph structure
    bool *visited; // pointer to bool which is 0 for not visited node in bfs and 1 for visited node in bfs
    vector<int> ans;
    public:
    Graph(int vertices);                // constructor
    void addEdge(int src, int dst);     // function to add edges in the graph
    void BFS(int startvertex);          // breadth first search
    void print();
};
Graph::Graph(int vertices){
    numVertices = vertices;                 // numVertices is defined in private access modifier
    adjlists = new list<int> [vertices];    // adjlists is also defined in private access modifier
    
}

void Graph::addEdge(int src, int dst){      //adding edges in the graph 
    adjlists[src].push_back(dst);
    adjlists[dst].push_back(src);           // remove this line for Directed graph src --> dst
}

void Graph::BFS(int startvertex){

    // Things needed for breadth first search
    // number of nodes
    // start vertex
    // pointer to list or list itself which holding all vertices

    visited = new bool[numVertices];
    for(int i=0;i<numVertices;i++){
        visited[i] = false;
    }

    list<int> q;
    visited[startvertex] = true;
    q.push_back(startvertex);

    list<int>::iterator i;
    while(!q.empty()){
        int currvertex = q.front();
        ans.push_back(currvertex);
        q.pop_front();

        for(i = adjlists[currvertex].begin(); i != adjlists[currvertex].end(); i++){
            int adjvertex = *i;
            if(!visited[adjvertex]){
                visited[adjvertex] = true;
                q.push_back(adjvertex);
            }
        }
    }


}

void Graph::print(){
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
      Graph g(4); // total no. of nodes
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  g.BFS(2);
  g.print();
  return 0;

}