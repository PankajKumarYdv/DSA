/*
#include <bits/stdc++.h> 
using namespace std; 

class Graph{
    public: 
    int v; 
    vector<vector<int>> adj; 
    
    Graph(int v){
        this->v = v; 
        adj.resize(v);
    }
    
    
    // add Edge 
    void addEdge(int u, int v){
        adj[u].push_back(v); 
        adj[v].push_back(u); // remove for directed graph
    }
    
    // 
    vector<int> DFS(){
        vector<int> result; 
        vector<bool> visited(v,false); 
        stack<int> st; 
        
        // for disconnected graph
        for(int i = 0; i < v; i++){
            int node = st.top(); 
            st.pop(); 
            
            if (visited[node]) continue; 
            
            visited[node] = true; 
            result.push_back(node); 
            
            // push neighbour 
            for(int neighbor : adj[node]){
                if(!visited[neighbor]){
                    st.push(neighbor); 
                }
            }
        }
        
        return result; 
    }
}; 


int main(){
    // int vertex, edge; 
    // cout << "Enter Vertex, Edges  (Space separated) :  "; 
    // cin >> vertex >> edge; 
    
    // Graph g(vertex); 
    
    // cout << "Enter Edges : " << endl; 
    // for(int i = 0; i < edge; i++){
        //     int u,v; 
        //     cout << i << " : " ; 
        //     cin >> u >> v; 
        //     g.addEdge(u,v); 
        // }
        
        
        // // Printing 
        // cout << "+-------- DFS -------------+" << endl; 
        // vector <int> result = g.DFS(); 
        // for(auto ele : result){
            //     cout << ele << "->" ; 
            // }
            // cout << "NULL" << endl; 
            
            Graph g(5);
            
            g.addEdge(0,1);
            g.addEdge(0,2);
            g.addEdge(3,4); // disconnected part
            
            vector<int> ans = g.DFS();
            
            
            return 0;
        }
*/


#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;

    // Constructor
    Graph(int V) {
        this->V = V;
        adj.resize(V); // IMPORTANT
    }

    // Add edge (with safety check)
    void addEdge(int u, int v) {
        if (u >= V || v >= V || u < 0 || v < 0) {
            cout << "Invalid edge: " << u << " " << v << endl;
            return;
        }
        adj[u].push_back(v);
        adj[v].push_back(u); // remove for directed graph
    }

    // DFS using stack
    vector<int> DFS() {
        vector<int> result;
        vector<bool> visited(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                st.push(i);

                while (!st.empty()) {
                    int node = st.top();
                    st.pop();

                    if (visited[node]) continue;

                    visited[node] = true;
                    result.push_back(node);

                    // push neighbors (reverse for better order)
                    for (int j = adj[node].size() - 1; j >= 0; j--) {
                        int neighbor = adj[node][j];
                        if (!visited[neighbor]) {
                            st.push(neighbor);
                        }
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    /*
    Graph g(5); // nodes: 0 to 4

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(3,4);

    vector<int> ans = g.DFS();

    cout << "DFS Traversal: ";
    for (int x : ans) {
        cout << x << " ";
    }

    // return 0;
    */

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