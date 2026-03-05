class Solution {
public:
    int first(vector<int>& nums, int x){
        int low = 0; 
        int high = nums.size() -1; 
        int firstAns = -1; 

        while(low <= high){
            int mid = (low + high)/2; 
            if(nums[mid] == x){
                firstAns = mid; 
                high = mid -1; 
            }else if(nums[mid] <= x){
                low = mid + 1;
            }else{
                high = mid - 1; 
            }
        }

        return firstAns; 
    }

    // last 
    int last(vector<int>& vec, int x){
        int low = 0; 
        int high = vec.size() -1; 
        int lastAns = -1; 

        while(low <= high){
            int mid = (low + high)/2; 
            if(vec[mid] == x){
                lastAns = mid; 
                low = mid + 1; 
            }else if(vec[mid] < x){
                low = mid + 1; 
            }else{
                high = mid -1; 
            }
        }

        return lastAns; 
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int a = first(nums, target); 
        if(a == -1) return {-1,-1}; 
        int b = last(nums,target); 
        return {a,b};
    }
};