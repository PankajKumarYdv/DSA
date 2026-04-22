#include <iostream>
#include <vector>

using namespace std;

class ArrayQuerySystem {
private:
    long long MOD = 1e9 + 7;
public:
    long long solve() {
        int n; cin >> n;
        vector<long long> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        int q; cin >> q;
        long long totalSum = 0;

        while (q--) {
            int type, l, r;
            cin >> type >> l >> r;
            if (type == 1) {
                // Type 1: Replace A[i] with (i-l+1) * A[l]
                long long startValue = A[l];
                for (int i = l; i <= r; i++) {
                    A[i] = (1LL * (i - l + 1) * startValue);
                }
            } else {
                // Type 2: Calculate range sum
                long long currentSum = 0;
                for (int i = l; i <= r; i++) {
                    currentSum = (currentSum + A[i]) % MOD;
                }
                totalSum = (totalSum + currentSum) % MOD;
            }
        }
        return totalSum;
    }
};


int main(){
    ArrayQuerySystem s; 
    s.solve(); 

}