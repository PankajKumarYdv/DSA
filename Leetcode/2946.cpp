/*
    2946. Matrix Similarity After Cyclic Shifts
*/

#include <iostream> 
#include <vector> 
using namespace std; 

class Leetcode{
    public: 
        bool areSimilar(vector<vector<int>>& matrix, int k){
            vector<vector<int>> newMatrix = matrix; 
            
            for(int i = 0; i < k; i++){

                if(i%2==0){
                    int start = newMatrix[0][0]; 
                    for(int j = 0; j < newMatrix[i].size()-1; j++){
                        newMatrix[i][j] = newMatrix[i][j+1];
                    }
                    newMatrix[i][newMatrix[i].size()-1] = start; 
                    
                }else{
                    int end = newMatrix[i][newMatrix[i].size()-1];
                    for(int j = newMatrix[i].size()-1; j>0; j--){
                        newMatrix[i][j] = newMatrix[i][j-1];
                    }
                    newMatrix[0][0] = end; 
                }
            }


            

            for(int i = 0; i < matrix.size(); i++){
                for(int j = 0; j < matrix[0].size(); j++){
                    cout << matrix[i][j] << " "; 
                }
                cout << endl; 
            }

            cout << endl; 
            cout << endl; 
            cout << endl; 
            cout << endl; 


            for(int i = 0; i < newMatrix.size(); i++){
                for(int j = 0; j < newMatrix[0].size(); j++){
                    cout << newMatrix[i][j] << " "; 
                }
                cout << endl; 
            }

            return false; 
        }
            
}; 

int main(){
    Leetcode k; 
    // vector<vector<int>> matrix(4,vector<int>(4));
    vector<vector<int>>  matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // for(int i = 0; i < matrix.size(); i++){
    //     for(int j = 0; j < matrix[0].size(); j++){
    //         matrix[i][j] = 32*65; 
    //     }
    // }


    // printing the values 
    k.areSimilar(matrix,4); 
    // for(int i = 0; i < matrix.size(); i++){
    //     for(int j = 0; j < matrix[0].size(); j++){
    //         cout << matrix[i][j] << " "; 
    //     }
    //     cout << endl; 
    // }
}