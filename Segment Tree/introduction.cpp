#include <iostream> 
#include <vector> 
using namespace std;  


class SegmentTree{
    public: 
        int n; 
        vector<int> st; 

    // Segment Tree 
    SegmentTree(vector<int>& arr){
        n = arr.size(); 
        st.resize(4*n); 
        buildTree(0,0,n-1, arr); 
    }

    
    void buildTree(int root, int l, int r, vector<int>& arr){

        // base case 
        if(l == r) {
            st[root] = arr[l]; 
            return; 
        }

        int mid = l+(r-l)/2; 
        buildTree(2*root+1,l,mid,arr); 
        buildTree(2*root+2,mid+1,r,arr); 

        st[root] = st[2*root+1] + st[2*root+2]; 
    }

    // querying sum
    int query(int start, int end,int root,int l, int r  ){
        // out of bound
        if(l>end || r < start){
            return 0; 
        }

        // l,r is entirely inside range 
        if(l >= start && r <= end){
            return st[root]; 
        }

        int mid = l+(r-l)/2; 
        return query(start,end,2*root+1,l,mid) + query(start,end,2*root+2,mid+1,r); 
    }

    int queryProcessing(int start, int end, vector<int> arr){
        int n = arr.size()-1; 
        return query(start, end, 0,0,n); 
    }

    // update 
    void updateSegmentTree(int index, int value, int root, int l, int r){
        if(l==r){
            st[root] = value; 
            return; 
        }

        // 
        int mid = l+(r-l)/2; 
        if(index <= mid){
            updateSegmentTree(index,value, 2*root+1, l, mid); 
        }else{
            updateSegmentTree(index,value,2*root+2, mid+1, r); 
        }
    }

    void updateQuery(int index, int value, vector<int> nums){
        int n = nums.size()-1; 
        updateSegmentTree(index,value,0, 0,n); 
    }

    // printing 
    void print(){
        for(auto ele : st){
            cout << ele << endl; 
        }
    }

    // 

};

int main(){
    vector <int> nums = {3,1,2,7,1}; 

    SegmentTree m(nums); 
    
    cout << "Segment Tree Created" << endl; 

    // Range sum
    cout << "Range Sum : " << m.queryProcessing(1,1,nums) << endl; 

    // All vector 
    cout << "Range Sum : " ; 
    for(int i = 0; i < nums.size(); i++){
        cout << m.queryProcessing(i,i,nums) << " ";
    }
    cout << endl; 


    // updating values 
    m.updateQuery(1,12,nums); 


    // viewing Segment Tree
    // m.print(); 

    // 

    cout << "Range Sum : " << m.queryProcessing(1,1,nums) << endl; 
    cout << "Range Sum : " ; 
    for(int i = 0; i < nums.size(); i++){
        cout << m.queryProcessing(i,i,nums) << " ";
    }
    cout << endl; 

    // update 
    m.updateQuery(5,12,nums); 
    cout << "Range Sum : " ; 
    for(int i = 0; i < nums.size(); i++){
        cout << m.queryProcessing(i,i,nums) << " ";
    }
    cout << endl; 
 


    
}
