#include <iostream> 
#include <vector> 
using namespace std; 

class SegmentTree{
    public: 
    int n; 
    vector <int> st; 

    SegmentTree(vector<int> arr){
        int n = arr.size()-1; 
        st.resize(n*4); 
        buildTree(0,0,n,arr);
    }

    void buildTree(int root, int l, int r, vector <int> arr){
        if(l==r){
            st[root] = l;  
            return; 
        }

        int mid = l + (r-l)/2; 

        buildTree(2*root+1, l, mid, arr); 
        buildTree(2*root+2,mid+1,r,arr); 

        int leftMaxIndex = st[2*root+1]; 
        int rightMaxIndex = st[2*root+2]; 

        if(arr[leftMaxIndex] >= arr[rightMaxIndex]) st[root] = leftMaxIndex; 
        else st[root] = rightMaxIndex; 
    }


    // Query 
    int query(int start, int end, int root, int l, int r){
        if(l > end || r < start) return -1; 
        if(l >= start && r <= end) return st[root]; 

        int mid = l+(r-l)/2; 
        
        int leftMaxIndex = query(start, end, 2*root+1, l, mid); 
        int rightMaxIndex = query(start,end, 2*root+2, mid+1, r); 

        if(leftMaxIndex == -1 ) return rightMaxIndex; 
        if(leftMaxIndex == -1 ) return leftMaxIndex; 

        return (leftMaxIndex >= rightMaxIndex) ? leftMaxIndex : rightMaxIndex; // for maximum 
    }


    int queryrun(int start, int end, vector <int> arr){
        int n = arr.size()-1; 
        return query(start, end, 0,0,n); 
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

    int a = 0; 
    int b = nums.size()-1; 
    cout << "Maximum Index ("<< a <<" "<<  b <<  ") : "<< m.queryrun(a,b,nums) << " \"" << nums[m.queryrun(a,b,nums)] << "\""<< endl; 


    for(int i = 0; i < nums.size(); i++){
        cout << m.queryrun(i,i,nums) << " "; 
    }
    cout << endl;
}