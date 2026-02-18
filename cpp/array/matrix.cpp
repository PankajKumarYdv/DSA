#include <iostream> 
#include <vector> 
using namespace std; 

int main(){
    // Creating matrix 
    vector <vector<int>> matrix = {
        {1,1,1,9},
        {1,0,1,6},
        {1,1,1,3}
    }; 
    

    // Matrix with default value 
    int row = 3; 
    int col = 3; 
    vector <vector<int>> defaultMatrix(row, vector<int>(col,1)); 

    // printing matrix 
    for(int i = 0 ; i < matrix.size(); i++){
        for(int j = 0 ; j < matrix[0].size(); j++){
            cout << matrix[i][j] << " "; 
        }
        cout << endl; 
    }
    
    // Getting size of matrix 
    cout << "Number of row : " << matrix.size() << endl; 
    cout << "Number of Column : " << matrix[0].size(); 
    
}