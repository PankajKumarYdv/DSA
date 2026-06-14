#include <iostream> 
#include <vector>
using namespace std; 

class SegmentTree{
    public: 

    // building Segment Tree Method
    void buildSegmentTree(int i, int l, int r, vector<int>& st, int arr[]){
        if(l == r){
            st[i] = arr[l];
            return;
        }

        int mid = l + (r-l)/2; 
        buildSegmentTree(2*i+1, l, mid, st, arr); 
        buildSegmentTree(2*i+2, mid+1, r, st, arr); 
        st[i] = st[2*i+1] + st[2*i+2]; 
    }



    // Range Sum Method
    int Query(int start, int end, int i, int l, int r, vector<int>& st){
        if(l > end || r < start){
            // out of range 
            return 0; 
        }
        if(l >= start && r <= end){
            return st[i];
        }

        int mid = l+(r-l)/2; 
        return Query(start, end,2*i+1, l, mid, st) + Query(start, end, 2*i+2, mid+1, r, st);
    }




    // Calling Function
    vector<int> querySum(int n, int arr[], int q, int queries[]){
        vector<int> st(4*n); 

        buildSegmentTree(0, 0, n-1,st, arr); 

        vector<int> result; 

        for(int i = 0; i < 2*q; i+=2){
            int start = queries[i] - 1; 
            int end = queries[i+1] -1; 

            result.push_back(Query(start, end, 0,0, n-1, st)); 
        }

        return result; 
    }
}; 

int main(){
    SegmentTree method;

    int nums[] = {1,2,3,4};  // Data
    int n = 4; // size of nums 
    int queries[] = {1,2,3,4};      // range indexing starting from 1 
    int q = 2;     // Number of Queries


    // 
    vector<int> res = method.querySum(n, nums, q, queries); 

    // Result
    for(auto ele : res){
        cout << ele << endl; 
    }
    return 0; 
}