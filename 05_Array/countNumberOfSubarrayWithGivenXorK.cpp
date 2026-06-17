#include <iostream> 
#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:


    int bruteForceAppoarch(vector<int> nums, int target){
        int count = 0; 
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                int xorCalculate = 0; 
                for(int k = i; k <= j; k++){
                    xorCalculate = xorCalculate ^ nums[k]; 
                }
                if(xorCalculate == target) count++; 
            }
        }

        return count; 
    }


    int betterSolution(vector<int> nums, int target){
        int count = 0; 
        for(int i = 0; i < nums.size(); i++){
            int xorResult = 0; 
            for(int j = i; j < nums.size(); j++){
                xorResult = xorResult ^ nums[j]; 
                if(xorResult == target) count++; 
            }
        }
        return count; 
    }

    int optimalSolution(vector<int> nums, int target){
        int xr = 0; 
        map<int,int> map; 
        map[xr]++; 
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            xr = xr ^ nums[i];
            int x = xr ^ target; 

            cnt += map[x];
            map[xr]++; 
        }
        return cnt; 

    }
};


int main(){
    Solution o; 
    vector <int> nums = {5, 6, 7, 8, 9};
    int k = 6; 
    int result = 6 ^ 2;  
    cout << "Test : " << result << endl; 
    cout << "Brute Force Approach : "<< o.bruteForceAppoarch(nums, k) << endl; 
    cout << "Better Solution : " << o.betterSolution(nums, k) << endl;
    cout << "Optimal Solution : " << o.optimalSolution(nums, k) << endl; 
    

}