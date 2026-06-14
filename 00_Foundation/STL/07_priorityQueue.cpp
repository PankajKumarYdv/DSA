#include <iostream> 
#include <queue> 
using namespace std; 

int main(){
    priority_queue <int> pq; 

    // PUSHING 
    pq.push(32);
    // 32
    pq.push(43); 
    // 43->32
    pq.push(56); 
    // 56->43->32
    pq.push(54); 
    // 56->54->43->32

    // Getting top value 
    cout << "Top Value : " << pq.top() << endl; // Return max element {56}

    // Getting all value
    priority_queue <int> temp = pq; 
    while(!temp.empty()){
        cout << temp.top() << " "; 
        temp.pop(); 
    }
    cout << endl; 

    // POP 
    pq.pop(); 
    // 54->43->32
    pq.pop(); 
    // 43->32
    pq.pop();
    // 32 
}