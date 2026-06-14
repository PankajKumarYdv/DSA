#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

class Solution{
    public: 
    int bruteforce(vector<int>& arr, int k) {
        for(auto ele : arr){    // TC : O(N) SC : O(1); 
            if(ele <= k) k++; 
            else break; 
        }
        return k; 
    }


    // Optimal 
    int Optimal(vector<int>& vec, int k) {
         int low = 0, high = vec.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int missing = vec[mid] - (mid + 1);

            if (missing < k) {
                low = mid + 1;  
            } else {
                high = mid - 1; 
            }
        }
        return k + high + 1;
    }
};

int main(){
    Solution o; 
    vector <int> nums = {2,3,4,7,11}; 
    int k = 5; 
    cout <<  k << "th Number is : " << o.findKthPositive(nums,k) << endl; 
}