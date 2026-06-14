#include <iostream> 
#include <vector> 
using namespace std; 

void subSequence(int ind, vector<int>& ds, vector<int>& arr, int n){
    if(ind == n){
        for(auto it : ds){
            cout << it << " "; 
        }
        if(ds.size() == 0){
            cout << "{ }"; 
        }

        cout << endl; 
        return ; 
    }

    subSequence(ind + 1, ds, arr, n);
    ds.push_back(arr[ind]); 
    subSequence(ind + 1, ds, arr, n);
    ds.pop_back(); 
}


int main(){
    vector<int> arr = {3,1,2}; 
    vector<int> ds = {}; 
    subSequence(0,ds,arr, arr.size()); 
}