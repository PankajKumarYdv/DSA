#include <iostream> 
using namespace std; 

void ascendingOrder(int n){
    if(n == 0) return; 
    ascendingOrder(n-1); 
    cout << n << endl; 
}

void descendingOrder(int n){
    if(n == 0) return; 
    cout << n << endl; 
    descendingOrder(n-1);
}


int main(){
    ascendingOrder(50); 
    descendingOrder(69); 
}