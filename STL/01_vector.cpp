#include <iostream> 
#include <vector> 
using namespace std; 


int main(){
    // with value 
    vector <int> keys = {12,87,35,47,43,98,16,35,48,35,32};

    vector <int> nums(15,0); 

    // For each 
    for(int i = 1; i < nums.size(); i++){
        // cout << i << " " << nums[i] << endl; 
    }

    // begin()
    cout << *keys.begin() << endl;  

    // end()
    cout << "Begin" << endl; 
    for(auto it = keys.begin(); it != keys.end(); ++it){
        cout << *it << " " << endl; 
    }


    // Size 
    cout << "Size of vector : " << keys.size() << endl; 

    // capacity 
    cout << "Capacity : " << keys.capacity() << endl; 


    // swap 
    vector <int> first = {23,34,54,56,32}; 
    vector <int> second = {34,54,65}; 

    first.swap(second); 
    cout << "First vector : "; 

    for(int ele : first){
        cout << ele << " "; 
    }
    cout << endl; 

    cout << "Second vector : "; 
    for (int ele : second){
        cout << ele << " "; 
    }
    cout << endl; 

    // swapping element
    vector <int> num = {45,98,33,15,24,45}; 
    swap(num[1], num[3]); 
    for(auto ele : num){
        cout << ele << " "; 
    }
    cout << endl; 
}