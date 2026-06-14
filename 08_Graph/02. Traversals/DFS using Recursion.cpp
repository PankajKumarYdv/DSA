#include <bits/stdc++.h> 
using namespace std; 

class Graph{
    public: 
    int v; 
    vector <vector<int>> adj; 

    // Constructor 
    Graph(int v){
        this->v = v; 
        adj.resize(v); 
    }

    // Add edge 
    void addEdge(int u, int v){
        adj[u].push_back(v); 
        adj[v].push_back(u); // remove for directed graph
    }

    // Helper DFS Function (recursive)
    void dfsHelper(int node, vector<bool>& visited, vector<int>& result){
        visited[node] = true; 
        result.push_back(node); 

        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                dfsHelper(neighbor, visited, result); 
            }
        }
    }


    // DFS (handles Disconnected graph)
    vector<int> DFS(){
        vector<int> result; 
        vector<bool> visited(v,false); 

        for(int i= 0; i < v; i++){
            if(!visited[i]){
                dfsHelper(i,visited,result); 
            }
        }

        return result; 
    }

};

int main(){
    int vertex, edge; 
    cout << "Enter Vertex, Edges  (Space separated) :  "; 
    cin >> vertex >> edge; 

    Graph g(vertex); 

    cout << "Enter Edges : " << endl; 
    for(int i = 0; i < edge; i++){
        int u,v; 
        cout << i << " : " ; 
        cin >> u >> v; 
        g.addEdge(u,v); 
    }


    // Printing 
    cout << "+-------- DFS -------------+" << endl; 
    vector <int> result = g.DFS(); 
    for(auto ele : result){
        cout << ele << "->" ; 
    }
    cout << "NULL" << endl; 
}