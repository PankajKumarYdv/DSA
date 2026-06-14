#include <iostream> 
#include <vector> 

using namespace std; 

// class
class Solution{
    public: 
    void setZeroes(vector<vector<int>>& matrix){
        // Creating temp matrix; 
        int row = matrix.size(); 
        int col = matrix[0].size(); 
        vector <vector<int>> tempMatrix(row, vector<int>(col,1));
        
        // changing 
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == 0){
                    for(int k = 0; k < col; k++) {
                        tempMatrix[k][j] = 0;
                    }
                    for(int k = 0; k < row; k++){
                        tempMatrix[i][k] = 0; 
                    }
                }
            }
        }
        matrix = tempMatrix ;
        // Printing 
        for(int i = 0 ; i < matrix.size(); i++){
        for(int j = 0 ; j < matrix[0].size(); j++){
            cout << matrix[i][j] << " "; 
        }
        cout << endl; 
    }

    }
}; 

int main(){
    Solution solution; 
    vector <vector<int>> matrix = {
        {1,1,1,1},
        {1,0,0,1},
        {1,1,0,1},
        {1,1,1,1}
    };

    solution.setZeroes(matrix); 
}