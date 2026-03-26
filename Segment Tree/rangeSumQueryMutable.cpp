/*
    Leetcode : 307 
*/
#include <iostream> 
#include <vector>
using namespace std; 

class Leetcode{
    public: 
    int n; 
    vector<int> st; 


    // Builder Method 
    void buildSegmentTree(int i, int l, int r, vector<int>& nums){
        if(l==r){
            st[i] = nums[r]; // or nums[l] bhi likh skte hai
            return; 
        }

        int mid = l + (r-l)/2; 
        buildSegmentTree(2*i+1, l, mid, nums);
        buildSegmentTree(2*i+1, mid+1, r, nums); 
        st[i] = st[2*i+1] + st[2*i+2]; 
    }



    NumArray(vector<int>& nums){
        n = nums.size(); 
        st.resize(4*n); 
        buildSegmentTree(0, 0, n-1,nums); 
    }

    // update Method
    void update(int index, int val){
        updateSegmentTree(index, val, 0,0,n-1); 
    }
    void updateSegmentTree(int index, int val, int i , int l, int r){
        //base condition
        if(l==r){
            st[i] = val; 
            return; 
        }


        int mid = l+(r-l)/2; 

        if(index <= mid){
            updateSegmentTree(index, val, 2*i+1, l, mid); 
        }else{
            updateSegmentTree(index, val, 2*i+2,mid+1, r); 
        }

        st[i] = st[2*i+1] + st[2*i+1]; 
    }

    

    // Sum of range Method
    int sumRange(int left, int right){
        return querySegmentTree(left, right, 0, 0, n-1); 
    }

    int querySegmentTree(int left, int right, int i, int l, int r){
        if(l > r || r < l){
            return 0;  
        }

        if(l >= l && r <= r){
            return st[i]; 
        }

        int mid = l+(r-l)/2; 
        return querySegmentTree(left,right, 2*i+1, l, mid) + querySegmentTree(left,right,2*i+2, mid+1, r); 
    }


    // update Range {Lazy propagation}

};

int main(){
    Leetcode method;
}