#include <iostream> 
#include <list> 
using namespace std; 

int main(){
    list <int> l; 

    l.push_front(32); 
    l.push_front(26); 
    l.push_front(43); 
    l.push_front(13); 
    l.push_front(53); 
    l.push_front(43); 
    l.push_front(13); 
    l.push_front(22); 

    cout << "For Each method : " ; 
    for(auto ele : l){
        cout << ele << " "; 
    }

    
    for(auto ele = l.begin(); ele != l.end(); ++ele){
        cout << *ele << " "; 
    }
    cout << endl; 

    cout << "Size of List : " << l.size() << endl; 
    cout << "Is Empty " << l.empty() << endl; 

    cout << "Front : " << l.front() << endl; 
    cout << "Back " << l.back() << endl; 

    l.push_front(32); 
    l.push_back(34); 

    for(auto ele = l.begin(); ele != l.end(); ++ele){
        cout << *ele << " "; 
    }
    cout << endl;

    // pop 
    l.pop_front(); 
    l.pop_back(); 

    for(auto ele = l.begin(); ele != l.end(); ++ele){
        cout << *ele << " "; 
    }
    cout << endl; 


    // Insert 
    auto pos = l.begin(); 
    advance(pos, 3);
    l.insert(pos,34); 

    for(auto ele = l.begin(); ele != l.end(); ++ele){
        cout << *ele << " "; 
    }
    cout << endl; 


}