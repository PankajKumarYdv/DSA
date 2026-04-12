#include <bits/stdc++.h>
using namespace std; 

class Graph{
    public: 
    int v; 
    vector<vector<int>> adj; 

    // Constructor 
    Graph(int v){
        this->v = v; 
        adj.resize(v); 
    }

    // Add edges 
    void addEdge(int u, int v){
        adj[u].push_back(v); 
        adj[v].push_back(u); // Remove for directed graph
    }

    // BFS 
    vector<int> BFS(){
        // int v = adj.size(); 

        vector<int> result; 
        vector <bool> visited(v,false); 
        queue<int> q; 

        // Loop for disconnected Component 
        for(int i = 0; i < v; i++){
            if(!visited[i]){
                q.push(i); 
                visited[i] = true; 

                while(!q.empty()){
                    int node = q.front(); 
                    q.pop(); 

                    result.push_back(node); 

                    for(int neighbor : adj[node]){
                        if(!visited[neighbor]){
                            q.push(neighbor); 
                            visited[neighbor] = true; 
                        }
                    }
                }
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
    cout << "+--------BFS-------------+" << endl; 
    vector <int> result = g.BFS(); 
    for(auto ele : result){
        cout << ele << "->" ; 
    }
    cout << "NULL" << endl; 


}