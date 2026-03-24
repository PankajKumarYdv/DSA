#include <iostream> 
#include <vector> 
using namespace std;

int main(){
    // Creating 2D vector/array
    vector <vector<int>>  arr(5,vector<int>(4,0)); 
    /*
        vector<vector<int>> ==> vector k andr vector hai
        row = 5 
        column = 4
        initial assigned value = 0 
    */

    int totalRows = arr.size(); 
    int totalColumns = arr[0].size(); 
    int totalElements = totalRows * totalColumns; 

    cout << "Row : " << totalRows << " Column : " << totalColumns << endl; 
    cout << "Total Elements : " << totalElements << endl; 

    // +-----------------------------------------------------------------------------+

    // Jagged Array 

    vector <vector<int>> jaggedArray(5); // Row = 5; 

    jaggedArray[0] = vector<int> (4); 
    jaggedArray[1] = vector<int> (2); 
    jaggedArray[2] = vector<int> (5); 
    jaggedArray[3] = vector<int> (3); 

    // Row 
    int totalRow = jaggedArray.size(); 

    // Column 
    int totalColumn = 0; 
    for (int i = 0; i < jaggedArray.size(); i++){
        totalColumn += jaggedArray[i].size(); 
    }
    
    // Element 
    int totalElement = totalRow * totalColumn; 
    cout << "---------------------------" << "\n\nJagged Array" << endl; 
    cout << "Row : " << totalRow << endl;
    cout << "Column : " << totalColumn << endl; 
    cout << "Element : " << totalElement << endl; 


    // TIME 1:18:40 

    return 0; 
}