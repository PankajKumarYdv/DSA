#include <iostream> 
#include <vector>

using namespace std; 
class Solution{
    public: 

    // ----- Iterative approach ----------------------------
    int binarySearch(vector<int>& vec, int target){
        int low = 0; 
        int high = vec.size()-1;  

        while (low <= high){
            int mid = (low + high)/2; 
            if(vec[mid] == target) return mid; 
            else if (vec[mid] < target){
                low = mid + 1; 
            }else{
                high = mid - 1; 
            }
        }
        return -1; 
    }
    // -----------------------------------------------------

    // ----------------Recursive approach -------------------
    int binarySearchRec(vector<int>& vec , int low, int high, int target){
        if(low > high) return -1; 
        int mid = (low + high)/2; 
        if(vec[mid] == target) return mid; 
        else if (target > vec[mid]) return binarySearchRec(vec, mid+1, high, target); 
        return binarySearchRec(vec, low, high-1, target); 
    }

    // search 
    int search(vector<int>& nums, int target) {
        return binarySearchRec(nums, 0, nums.size() - 1, target);
    }
    // -----------------------------------------------------
};

int main(){    
    Solution method; 
    vector <int> arr = {-1,0,3,5,9,12}; 
    cout << "Result : " << method.search(arr, 5) << endl; 
}