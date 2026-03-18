#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
    public: 
    int assignCookies(vector<int>& g, vector<int>& s) {
        int count = 0;
        int i = 0, j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(i < g.size() && j < s.size()) {
            if(g[i] <= s[j]) {
                count++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return count;
    }
}; 

int main() {
    Solution leetcode;
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    cout << leetcode.assignCookies(g, s) << endl;
    
}