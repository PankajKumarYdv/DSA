#include<iostream> 
#include<bits/stdc++.h> 

// #include<vector> 
// #include<unordered_map> 

using namespace std; 

class info{
    public: 
    int minimumChange(vector<int> nums){
        unordered_map <int, int> mp; 
        int half = nums.size()/2; 
        for(int i = 0; i < half; i++){
            mp[mp[i]-i]++; 
            mp[mp[nums.size()-1-i]-1]++; 
        }
        

    }
};

int main(){
    vector <int> nums = {1,2,3,2,1}; 
    info m; 
    cout << "Minimum Change : " << m.minimumChange(nums) << endl; 
}