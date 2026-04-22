#include <vector>
#include <algorithm>
#include <iostream> 
using namespace std;

class LexicographicalSwap {
    vector<pair<int, int>> tree;

    void build(int node, int start, int end, const vector<int>& A) {
        if (start == end) {
            // Store value and negated index so minimum takes highest index on ties
            tree[node] = {A[start], -start};
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid, A);
            build(2 * node + 1, mid + 1, end, A);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    pair<int, int> query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return {2e9, 1}; // Outside bounds
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return min(query(2 * node, start, mid, l, r),
                   query(2 * node + 1, mid + 1, end, l, r));
    }

public:
    vector<int> smallestArray(int N, int K, vector<int> A) {
        tree.assign(4 * N, {0, 0});
        build(1, 0, N - 1, A);
        
        for (int i = 0; i < N - 1; ++i) {
            int r = min(N - 1, i + K);
            if (i + 1 > r) continue;
            
            pair<int, int> q = query(1, 0, N - 1, i + 1, r);
            if (q.first < A[i]) {
                swap(A[i], A[-q.second]); // Apply single best swap
                break;
            }
        }
        return A;
    }
};

int main(){
    LexicographicalSwap ls; 
    int N; 
    cin >> N; 

    vector<int> ele;
    for(int i = 0; i < N; i++){
        int x; 
        cin >> x; 
        ele.push_back(x);
    }
    int K;
    cin >> K; 

    vector <int> result = ls.smallestArray(N,K,ele); 
    for(auto e : result){
        cout << e << " "; 
    }
    cout << endl; 
}