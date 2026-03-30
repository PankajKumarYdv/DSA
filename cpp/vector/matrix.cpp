#include <iostream> 
#include <vector>  

using namespace std; 

int main(){
    vector<vector<int>> matrix(5,vector <int>(4)); 

    int m = matrix.size(); // 5 
    int n = matrix[0].size();  // 4
    int mxn = m*n; 
    
    cout << "m : " << m << " n : " << n << " Total Element : " << mxn << endl; 


    // Matrix is 
    for(int i = 0; i < 5; i++){
        for(int j = 0; i < 4; j++){
            matrix[i][j] = i*j; 
        }
    }
    // matrix[0][2] = 56; 
    cout << matrix[0][2] ; 

     
}