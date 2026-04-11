#include <iostream> 
#include <vector> 
#include <queue>
using namespace std; 

class Solution{
    public: 

    /* 
            DFS Method 
    */

    bool DetectCycle(int node, vector<int> adj[], vector<bool>& path, vector<bool>& visited ){
        visited[node] = 1; 
        path[node] = 1; 

        for(int j = 0; j < adj[node].size(); j++){
            // if neighbour node is already present in path 
            // cycle is present 
            if(path[adj[node][j]]) return 1; 

            if(!visited[adj[node][j]] && DetectCycle(adj[node][j], adj, path,visited)) return 1; 
        }

        path[node] = 0; 
        return 0;  
    }


    bool isCycle(int v, vector <int> adj[]){


        vector <bool> path(v,0); 
        vector <bool> visited(v,0);

        for(int i = 0; i < v; i++){
            if(!visited[i] && DetectCycle(0,adj,path,visited))
            return 1; 
        } 
    }


    /*
        BFS Method 
    */

    bool isCycle(int v, vector<int> adj[]){
        
        vector<int> InDeg(v,0);

        for(int i = 0; i < v; i++){
            for(int j = 0; j < adj[i].size(); j++){
                InDeg[adj[i][j]]++; 
            }
        }

        queue<int> q; 

        for(int i = 0; i < v; i++){
            if(!InDeg[i]); q.push(i);
        }
        int count = 0;

        while(!q.empty()){
            int node = q.front(); 
            q.pop(); 
            count++; 

            for(int j = 0; j < adj[node].size(); j++){
                InDeg[adj[node][j]]--; 
                if(!InDeg[adj[node][j]])
                q.push(adj[node][j]); 
            }
        }
        return count != v; 
    }
};