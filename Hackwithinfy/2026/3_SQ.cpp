#include <bits/stdc++.h>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int minDays(vector<long long>& L) {
        int N = L.size();
        if (N <= 1) return 0;
        
        long long max_diff = 0;
        long long prev = L[0];
        
        for (int i = 1; i < N; ++i) {
            long long target = prev - 1; // Must be strictly smaller
            long long actual = min(L[i], target);
            long long diff = L[i] - actual;
            
            if (diff > max_diff) {
                max_diff = diff;
            }
            prev = actual;
        }
        
        if (max_diff == 0) return 0;
        
        int days = 0;
        while (max_diff > 0) {
            days++;
            max_diff >>= 1; // Shift right to count bits needed
        }
        
        return days;
    }
};

int main() {
    int N;
    cin >> N;

    vector<long long> L(N);
    for (int i = 0; i < N; i++) cin >> L[i];

    Solution obj;
    cout << obj.minDays(L);
}