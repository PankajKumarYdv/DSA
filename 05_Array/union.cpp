#include <iostream> 
#include <vector> 

using namespace std; 
class Solution{
    public: 

    // greeting 
    void hey(){
        cout << "Hello Pankaj"; 
    }

    // void return 
    void elements(vector<int>& num1){
        for (int ele : num1){
            cout << ele; 
        }
    }

    // vector return 
    vector<int> unionArray(vector<int>& num1){
        for (int ele : num1){
            ele = ele +  100; 
        }
        return num1; 
    }

    
};

int main(){
    Solution greeting; 
    greeting.hey(); 
    vector <int> num = {12,3,245,6,567,8989}; 
    greeting.elements(num); 
    
    // updating nums
    num = greeting.unionArray(num); 

    // printing each element 
    for (int ele : num){
        cout << "\n" << ele; 
    }
}