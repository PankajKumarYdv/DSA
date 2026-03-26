// Maximum Xor of two number in an array

#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 

class Leetcode{
    public: 



    // XOR ON Array
    vector<int> xorOperation(vector<int>& nums){
        vector<int> result; 
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                result.push_back(nums[i] xor nums[j]); 
            }
        }
        return result; 
    }
}; 

int main(){
    Leetcode m; 

    vector<int> nums = {3,10,5,25,2,8}; 
    vector <int> xorResult = m.xorOperation(nums); 
    for(auto num : xorResult){
        cout << num << " "; 
    }

}