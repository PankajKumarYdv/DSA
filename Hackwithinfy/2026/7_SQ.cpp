#include <vector>
#include <map>
#include <algorithm>
#include <iostream> 

using namespace std;

class RestaurantDishes {
public:
    long long maxDishes(int N, const vector<long long>& Arr) {
        map<long long, int> freq_map;
        for (long long dish : Arr) {
            freq_map[dish]++;
        }
        
        vector<int> F;
        for (auto const& [type, count] : freq_map) {
            F.push_back(count);
        }
        // Sort frequencies descending 
        sort(F.rbegin(), F.rend()); 
        
        long long max_eaten = 0;
        // The maximum sequence of doubling we could physically achieve is ~20
        int limit = min(20, (int)F.size()); 
        
        for (int k = 1; k <= limit; ++k) {
            long long max_x = 1e9;
            for (int i = 0; i < k; ++i) {
                // Ensure the i-th largest frequency can support its place in the chain
                long long allowed_x = F[i] >> (k - 1 - i); 
                max_x = min(max_x, allowed_x);
            }
            if (max_x > 0) {
                // Total is base * (2^0 + 2^1 + ... + 2^(k-1)) = base * (2^k - 1)
                long long eaten = max_x * ((1LL << k) - 1);
                max_eaten = max(max_eaten, eaten);
            }
        }
        return max_eaten;
    }
};