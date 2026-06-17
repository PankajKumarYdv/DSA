#include <iostream> 
#include <bits/stdc++.h>
using namespace std; 


void reverseArray(vector<int>& arr, int l, int r){
    if(l >= r) return; 
    swap(arr[l], arr[r]); 
    reverseArray(arr, l+1, r-1); 
}

int main(){
    vector<int> arr = {1,2,3,4,2}; 
    for(auto ele : arr){
        cout << ele << " "; 
    }
    cout << endl;
    
    reverseArray(arr,0,arr.size()-1); 
    for(auto ele : arr){
        cout << ele << " "; 
    }
    cout << endl;
}