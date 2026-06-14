#include <iostream> 
using namespace std; 

// Parameterized Method 


// Functional Method 
int totalSum(int n){
    if(n==0) return 0; 
    return n + totalSum(n-1); 
}

int main(){
    cout << totalSum(10) << endl; 
}