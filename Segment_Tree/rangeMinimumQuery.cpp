#include <iostream> 
#include <vector> 
#include <climits> 
using namespace std; 

class SegmentTree{
    public: 
        int n; 
        vector <int> st; 

    SegmentTree(vector<int>& arr){
        n = arr.size()-1; 
        st.resize(4*n); 
        buildTree(0,0,n, arr); 

    }

    // Building segment tree which store min elements 
    void buildTree(int root, int l, int r, vector <int>& arr){
        if(l == r){
            st[root] = arr[l]; 
            return; 
        }

        int mid = l + (r-l)/2; 
        buildTree(2*root+1, l, mid,  arr); 
        buildTree(2*root+2, mid+1, r, arr); 

        // st[root] = st[2*root+1] + st[2*root+2]; // For Addition
        // st[root] = max(st[2*root+1], st[2*root+2]);  // -> for Maximum 
        st[root] = min(st[2*root+1], st[2*root+2]); // -> For minimum 
    }

/*

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

    */

    // Finding minimum Query 
    int Query(int start, int end, int root, int l, int r, vector<int> st){
        if(l > end || r < start){
            return -1; 
        }

        if(l >= start && r <= end){
            return st[root]; 
        }

        int mid = l + (r-l)/2; 
        // return query(start,end,2*root+1,l,mid) + query(start,end,2*root+2,mid+1,r); // For addition

        // Only for MAX or MIN
        int leftIndex = Query(start, end, 2*root+1, l, mid, st); 
        int rightIndex = Query(start, end, 2*root+2, mid + 1, r, st); 

        if(leftIndex == -1) return rightIndex; 
        if(rightIndex == -1) return leftIndex; 
        
        // return (leftIndex >= rightIndex) ? leftIndex : rightIndex; // for maximum  
        return (leftIndex >= rightIndex) ? rightIndex :leftIndex ;  // for minimum 
    }

    int queryrun(int start, int end, vector <int> arr){
        int n = arr.size()-1; 
        return Query(start, end, 0,0,n,st); 
    }



    // printing Segment tree
    void print(){
        cout << "Segment Tree : " ; 
        for(auto ele : st){
            cout << ele << " "; 
        }
        cout << endl; 
    }
}; 


int main(){
    vector <int> nums = {3,1,2,7,1};
    SegmentTree  m(nums); 
    m.print(); 

    cout << "Maximum : "<< m.queryrun(2,3,nums) << endl; 


    for(int i = 0; i < nums.size(); i++){
        cout << m.queryrun(i,i,nums) << " "; 
    }
    cout << endl;
}
