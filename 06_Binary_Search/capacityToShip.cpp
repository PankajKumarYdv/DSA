#include <iostream> 
#include <bits/stdc++.h>
using namespace std; 

class Solution{
    public: 
    // Brute force Approach 

    int shipWithinDays(vector<int>& weights, int days) {
        int minCapacity = *max_element(weights.begin(),weights.end()); 
        int sumOfweights = accumulate(weights.begin(), weights.end(), 0); 

        for(int i = minCapacity; i <= sumOfweights; i++){
            int dayReq = requiredDay(weights, i); 
            if(dayReq <= days){
                return i; 
            }
        }
        return 0; 
    }

    int requiredDay(vector<int>& weights, int cap){
        int day = 1; 
        int load  = 0; 

        for(int i = 0; i < weights.size(); i++){
            if((load + weights[i]) > cap){
                day ++; 
                load = weights[i]; 
            }else{
                load += weights[i];
            }
        }
        return day; 
    }


    // Optimal Solution 
    int daysNeeded(vector<int>& weights, int capacity) {
        int days = 1;
        int currentLoad = 0;
        for (int w : weights) {
            if (currentLoad + w > capacity) {
                days++;
                currentLoad = w;
            } else {
                currentLoad += w;
            }
        }
        return days;
    }


    int optimal(vector<int>& weights, int d) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while (left < right) {
            int mid = left + (right - left) / 2;
            int needed = daysNeeded(weights, mid);
            if (needed <= d) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main(){
    Solution o;
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10}; 
    int days = 5; 

    // 
    cout << "Minimum Capacity : " << o.optimal(weights, days) << endl; 
}