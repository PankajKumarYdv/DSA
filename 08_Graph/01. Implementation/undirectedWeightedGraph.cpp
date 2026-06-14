#include <iostream> 
#include <bits/stdc++.h> 
using namespace std; 

class Graph{
    public: 
    int vertex; 
    vector <vector<pair<int,int>>> adj; 

    Graph(int vertex){
        this->vertex = vertex; 
        adj.resize(vertex); 
    }

    // Add Edges 
    void addEdge(int u, int v, int weight){
        adj[u].push_back({v,weight}); 
        adj[v].push_back({u,weight}); // remove for directed graph
    }

    // Print Graph
    void printGraph(){
        for(int i = 0; i < vertex; i++){
            cout << i << " -> ";
            for(auto it : adj[i]){
                cout << "(" << it.first << "," << it.second << ") ";
            }
            cout << endl; 
        }
    }

};


int main(){
    /*
    int vertex, edge; 
    cin >> vertex >> edge; 

    vector<vector<int>> adjMat(vertex , vector<int>(vertex, 0)); 

    int u,v,weight; 

    for(int i = 0; i < edge; i++){
        cin >> u >> v >> weight; 
        adjMat[u][v] = weight; 
        adjMat[v][u] = weight; 
    }

    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < edge; j++){
            cout << adjMat[i][j];
        }
        cout << endl; 
    }

    return 0; 
    */

    /*
        Undirected Weighted Graph 
    

    int vertex; 
    int edges; 
    cout << "Getting vertex and edges (space separated) : "; 
    cin >> vertex >> edges; 

    vector<vector<pair<int,int>>> adj(vertex); 

    for(int i = 0; i < edges; i++){
        int u;
        int v;
        int weight; 

        adj[u].push_back({v,weight}); 
        adj[v].push_back({u, weight}); 
    }


    // print 
    for(int i = 0; i < vertex; i++){
        cout << i << "->"; 
        for(auto it : adj[i]){
            cout << "(" << it.first << it.second << ")" ; 
        }

        cout << endl; 
    }
        */
    int vertex; 
    cout << "Enter Vertex : " ; 
    cin >> vertex; 
    Graph g(vertex); 

    int edges; 
    cout << "Total Edges : "; 
    cin >> edges; 

    cout << "Getting data (u,v,w) " << endl; 
    for(int i = 0; i < edges; i++){
        int u,v,w; 
        cout << i <<  " : "; 
        cin >> u >> v >> w;
        g.addEdge(u,v,w); 
    }


    // Printing those data
    cout << "+---------Graph-------------+" << endl; 
    g.printGraph(); 

    

}