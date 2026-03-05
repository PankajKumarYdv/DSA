#include <iostream> 
#include <vector>
using namespace std; 

class Solution{
    public: 
    // lower Bound 
    int lowerBound(vector <int>& vec, int x){
        int low = 0; 
        int high = vec.size()-1; 
        int ans = vec.size();
        while (low <= high){
            int mid = (low + high)/2; 
            if(vec[mid] >= x){
                ans = mid; 
                high = mid -1; 
            }else{
                low = mid + 1; 
            }
        }

        return ans; 
    }

    // upper Bound
    int upperBound(vector <int>& vec, int x){
        int low = 0; 
        int high = vec.size()-1;
        int ans = vec.size(); 

        while(low <= high){
            int mid = (low + high)/2; 
            if(vec[mid] > x){
                ans = mid; 
                high = mid -1; 
            }else{
                low = mid + 1; 
            }
        }

        return ans; 
    }
    vector<int> firstLastOccurence(vector <int>& vec, int x){
        int lb = lowerBound(vec,x); 
        if(lb == vec.size() || vec[lb] != x) return {-1,-1}; 
        return {lb, upperBound(vec,x)-1}; 
    }
}; 

int main(){
    // object 
    Solution method; 

    // data 
    vector <int> nums = {2,4,6,8,8,8,11,13}; 
    // vector <int> nums = {1,3, 5, 5, 5, 5, 67, 123,125};
    vector <int> ans = method.firstLastOccurence(nums, 14); 

    cout << "First Occurence : " << ans[0] << "    Last Occurence : " << ans[1] << endl; 
    
}