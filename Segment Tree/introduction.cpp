#include <iostream> 
#include <vector> 
using namespace std;  


class SegmentTree{
    public: 
    vector<int> tree; 
    int n; 

    // Segment Tree 
    SegmentTree(vector<int>& arr){
        n = arr.size(); 
        tree.resize(4*n); 
        build(1,0,n-1, arr); 
    }

    
    void build(int node, int start, int end, vector<int>& arr){
        if(start == end) {
            tree[node] = arr[start]; 
        }
    }

};

int main(){
    
    
}
