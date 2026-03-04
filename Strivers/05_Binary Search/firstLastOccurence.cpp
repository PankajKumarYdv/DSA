#include <iostream> 
#include <vector>
using namespace std; 

class Solution{
    public: 
    vector<int> firstLastOccurence(vector <int>& vec, int x){
        vector <int> ans = {-1,-1}; 
        int low = 0; 
        int high = vec.size()-1; 

        while(low <= high){
            int mid = (low + high)/2; 
            if(vec[mid] >= x){
                ans[0] = mid;
                high = mid - 1; 
            }else{
                low = mid + 1; 
            }
        }

        // 
        low = 0; 
        high = vec.size()-1;
        while(low <= high){
            int mid = (low + high) /2; 
            if(vec[mid] <= x){
                ans[1] = mid; 
                low = mid + 1; 
            }else{
                high = mid - 1;
            }
        }

        return ans; 
    }
}; 

int main(){
    // object 
    Solution method; 

    // data 
    // vector <int> nums = {2,4,6,8,8,8,11,13}; 
    vector <int> nums = {1,3, 5, 5, 5, 5, 67, 123,125};
    vector <int> ans = method.firstLastOccurence(nums, 5); 

    cout << "First Occurence : " << ans[0] << "    Last Occurence : " << ans[1] << endl; 
    
}