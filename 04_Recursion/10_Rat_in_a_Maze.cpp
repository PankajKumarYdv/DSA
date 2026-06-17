#include <iostream> 
#include <string> 
#include <bits/stdc++.h> 
using namespace std; 

class Solution{
    public: 
    vector<string> result; 

    bool isSafe(int i, int j, int n){
        return i >= 0 && i < n && j >= 0 && j < n; 
    }


    void solve(int i, int j, vector<vector<int>> &maze, int n, string &path){
        if(!isSafe(i,j,n) || maze[i][j] == 0){
            return; 
        }

        if(i == n-1 && j == n-1){
            result.push_back(path); 
            return; 
        }

        // Marking as visited 
        maze[i][j] = 0; 
        
        /*  Recursion Call {DLRU -> lexicographically increasing order} */ 

        // Down
        path.push_back('D'); 
        solve(i+1, j, maze,n,path); 
        path.pop_back(); 

        // Left
        path.push_back('L'); 
        solve(i, j-1, maze,n,path); 
        path.pop_back(); 
        
        // Right
        path.push_back('R'); 
        solve(i, j+1, maze,n,path); 
        path.pop_back(); 

        // Up
        path.push_back('U'); 
        solve(i-1, j, maze,n,path); 
        path.pop_back(); 


        // marking as unvisited 
        maze[i][j] = 1;
    }

    vector<string> findPath(vector<vector<int>> &maze, int n){
        string path = ""; 
        solve(0,0,maze,n, path); 
        return result; 
    }
};


int main(){
    Solution o; 

    vector<vector<int>> maze =  {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    // vector<vector<int>> maze = {{1,1,0,0,1},{1,1,1,1,0},{1,1,1,0,1},{0,0,1,0,0},{1,1,1,1,1}}; 
    vector<string> ans = o.findPath(maze, maze.size());

    for(string path : ans){
        cout << path << endl; 
    }
}


