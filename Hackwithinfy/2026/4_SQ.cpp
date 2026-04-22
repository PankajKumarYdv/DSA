#include <bits/stdc++.h>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int minChanges(vector<int>& arr) {
        int N = arr.size(); 
        unordered_map<long long, int> freq;
        int max_freq = 0;
        
        for (int i = 0; i < N; ++i) {
            long long offset = min(i, N - 1 - i);
            long long required_base = arr[i] - offset;
            
            freq[required_base]++;
            if (freq[required_base] > max_freq) {
                max_freq = freq[required_base];
            }
        }
        
        // Number of elements to change is total minus elements we keep unchanged
        return N - max_freq;
    }
};

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    Solution obj;
    cout << obj.minChanges(arr);
}