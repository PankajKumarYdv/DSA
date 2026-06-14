#include <iostream> 
#include <stack>
using namespace std; 

int main(){
    stack<int> s; 
    
    // Pushing elements 
    s.push(23); 
    // 23
    s.push(32); 
    // 32->23
    s.push(62); 
    // 62->32->23
    s.push(89); 
    // 89->62->32->23
    
    stack<int> temp = s; 
    while(!temp.empty()){
        cout << temp.top() << " "; 
        temp.pop(); 
    }
    cout << endl; 
    
    // POPing 
    s.pop(); // 62->32->23
    s.pop(); // 32->23
    s.pop(); // 23

}