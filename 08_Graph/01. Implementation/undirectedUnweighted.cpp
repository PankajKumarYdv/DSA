#include <iostream> 
#include <vector>
using namespace std; 

class Graph{
    public:
    int vertex;
    vector<vector<int>> adj; 

    // Constructor 
    Graph(int n){
        this->vertex = n; // storing n in class variable vertex
        adj.resize(n); 
    }

    // Add Edges 
    void addEdge(int u, int v){
        adj[u].push_back(v); 
        adj[v].push_back(u); // remove this line for directed graph
    }


    // Print Adjacency List 
    void printGraph(){
        for(int i = 0; i < vertex; i++){
            cout << i << "->"; 
            for(int neighbor : adj[i]){
                cout << neighbor << " "; 
            }
            cout << endl; 
        }
    }
}; 


int main(){
    /*
    int vertex, edges;
    cout << "Getting vertex and Edges (space separated) : " << " "; 
    cin >> vertex >> edges; 

    // Adjacent List 
    vector<int> adjList[vertex]; 

    // Getting data 
    cout << "Getting data " << endl; 
    int u,v; 
    for(int i = 0; i < edges; i++){
        cout << i << " : " ; 
        cin >> u >> v; 

        adjList[u].push_back(v); 
        adjList[v].push_back(u); 
    }



    // printing data; 
    cout << "+------------- Printing Data -----------+ " << endl; 
    for(int i = 0; i < vertex; i++){
        cout << i << "-->"; 
        for(int j = 0; j < adjList[j].size(); j++){
            cout << adjList[i][j] << " "; 
        }
        cout << endl; 
    }
        */
    int vertex; 
    cout << "Enter Number of Vertex : "; 
    cin >> vertex; 
    
    Graph g(vertex); 

    int edges; 
    cout << "Enter Number of Edges : "; 
    cin >> edges; 

    for(int i = 0; i < edges; i++){
        cout << i << " : "; 
        int u,v; 
        cin >> u >> v; 

        // Adding 
        g.addEdge(u,v); 
    }
    

    // print data 
    cout << "Printing Graph" << endl; 
    g.printGraph(); 
}