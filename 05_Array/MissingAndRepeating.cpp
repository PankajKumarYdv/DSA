#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bruteforce(vector<int> &nums) // TC : N^2 SC : 1
    {
        // code here
        vector<int> result = {-1, -1};
        for (int i = 1; i <= nums.size(); i++)
        {
            int cnt = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] == i)
                    cnt++;
            }

            if (cnt > 1)
                result[0] = i;
            if (cnt == 0)
                result[1] = i;
            if (result[1] != -1 && result[0] != -1)
                break;
        }

        return result;
    }

    vector<int> better(vector<int> &nums){
        map<int, int> map;
        vector<int> result = {-1, -1};
        for (int i = 1; i <= nums.size(); i++){
            map.insert({i, 0});
        }

        for (int i = 0; i < nums.size(); i++){
            map[nums[i]] += 1;
        }

        for (int i = 1; i <= nums.size(); i++){
            if (map[i] == 2)    result[0] = i;
            if (map[i] == 0)    result[1] = i;
        }

        return result;
    }

    vector<int> optimalWithMath(vector<int> &nums){ // TC : O(n) SC: O(1);
        long long n = nums.size(); 
        long long SN = (n*(n+1)) / 2; 
        long long S2N = (n * (n+1) * (2*n+1)) / 6; 
        long long S = 0, S2 = 0; 

        for(int i = 0; i < n; i++){
            S += nums[i];
            S2 += (long long)nums[i] * (long long)nums[i]; 
        }

        long long val1 = S - SN; 
        long long val2 = S2 - S2N; 
        val2 = val2 / val1; 
        long long x = (val1+val2)/2; 
        long long y = x -val1; 
        return {(int)x, (int)y}; 
    }
};

int main()
{
    Solution o;

    vector<int> nums = {2, 2};

    // Brute Force
    vector<int> result = o.bruteforce(nums);
    cout << "Brute Force -> Repeating : " << result[0] << " Missing : " << result[1] << endl;

    //
    result = o.better(nums);
    cout << "Better -> Repeating : " << result[0] << " Missing : " << result[1] << endl;

    // Optimal Method using Math 
    result = o.better(nums);
    cout << "Optimal Method using Math  -> Repeating : " << result[0] << " Missing : " << result[1] << endl;

    // Optimal Method using XOR 

}   