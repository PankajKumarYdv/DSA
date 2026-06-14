#include <iostream> 
using namespace std; 

long long factorialUptoN(int n){
    if (n==0) return 1; 
    return n * factorialUptoN(n-1); 
}; 

int main(){
    cout << factorialUptoN(5) << endl; 
}