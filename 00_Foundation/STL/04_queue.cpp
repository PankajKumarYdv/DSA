#include <iostream> 
#include <queue> 
using namespace std; 
int main(){
    queue<int> q; 

    // PUSH
    q.push(10); 
    // 10
    q.push(20);
    // 10->20
    q.push(22);
    // 10->20->22
    q.push(24);
    // 10->20->22->24
    q.push(25);
    // 10->20->22->24->25
    q.push(26);
    // 10->20->22->24->25->26
    q.push(21);
    // 10->20->22->24->25->26->21

    // Getting all element 
    queue<int> temp = q; 
    while(!temp.empty()){
        cout << temp.front() << " "; 
        temp.pop(); 
    }
    cout << endl; 



    // POP
    q.pop(); 
    // 20->22->24->25->26->21
    q.pop(); 
    // 22->24->25->26->21
    q.pop();
    // 24->25->26->21
    q.pop(); 
    // 25->26->21
    q.pop(); 
    // 26->21
    q.pop(); 
    // 21
    
    
}