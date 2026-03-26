#include <iostream> 
#include <vector> 
using namespace std; 

class SegmentTree{
    public: 
    // Building segment tree which store min elements 
    void buildSegmentTree(int i, int l, int r, int st, int arr[]){
        if(l == r){
            st[i] = arr[l]; 
            return; 
        }

        int mid = l + (r-l)/2; 
        buildSegmentTree(2*i+1, l, mid, st, arr); 
        buildSegmentTree(2*i+2, mid+1, r, st, arr); 

        st[i] = min(st[2*i+1], st[2*i+2]); 
    }


    // Main caller function
    int *constructST(int arr[], int n){
        int *st = new int[4*n]; 
        buildSegmentTree(0,0,n-1,st, arr); 
        return st; 
    }


    // Finding min
    int Query(int start, int end, int i, int l, int r, int st[]){
        if(l > end || r < start){
            return INT_MAX; 
        }

        if(l >= start && r <= end){
            return st[i]; 
        }

        int mid = l + (r-l)/2; 
        return Query(start, end, 2*i+1, l, mid, st) + Query(start, end, 2*i+2, mid + 1, r, st); 
    }

    // Faltu method
    int RMQ(int st[], int n, int a, int b){
        return Query(a,b,0,0,n-1,st);
    }
}; 