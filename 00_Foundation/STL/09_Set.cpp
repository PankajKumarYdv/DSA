#include <iostream> 
#include <set> 
#include <unordered_set>
using namespace std; 

int main(){
    set<int>  s; 
    unordered_set<int> uos; 
    s.insert(32);
    s.insert(43); 
    s.insert(32); 

    // traversal 
    set<int>::iterator it = s.begin(); 
    while(it != s.end()){
        cout << *it << " "; 
        it++; 
    }
    cout << endl; 

    // 
}