#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> bruteforce(vector<vector<int>> &nums)
    { // N log n + O(2N)
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Nlog(n)
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            int start = nums[i][0];
            int end = nums[i][1];
            if (!ans.empty() && end <= ans.back()[1])
            {
                continue;
            }

            for (int j = i + 1; j < n; j++)
            {
                if (nums[j][0] <= end)
                {
                    end = max(end, nums[j][1]);
                }
                else
                {
                    break;
                }
            }
        }

        return ans;
    }

    vector<vector<int>> optimal(vector<vector<int>> &nums)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            if (ans.empty() || arr[i][0] > ans.back()[1])
            {
                ans.push_back(arr[i]);
            }
            else
            {
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }
        return ans;
    }

    void sorted(vector<vector<int>> &nums)
    {
        sort(nums.begin(), nums.end());
        for (auto num : nums)
        {
            cout << num[0] << " : " << num[1] << endl;
        }
    }
};

int main()
{
    Solution o;
    vector<vector<int>> nums = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}};
    vector<vector<int>> result = o.sorted(nums);
    // o.sorted(nums);
}