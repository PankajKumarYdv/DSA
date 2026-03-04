#include <iostream> 
#include <vector> 
using namespace std; 

// Class 
class Solution{
    public: 
    int lowerBound(vector<int>& vec, int target){
        int low = 0; 
        int high = vec.size()-1;
        int ans = vec.size();  

        // logic 
        while(low <= high){
            int mid = (low+high)/2; 
            if(vec[mid] >= target){
                ans = mid; 
                high = mid -1; 
            }else{
                low = mid + 1;
            }
        }

        return ans; 
    }
}; 

// main 
int main(){
    // object 
    Solution method; 
    vector <int> vec = {1,2,3,3,5,8,8,10,10,11}; 
    // vector <int> vec = {3,5,8,15,19};
    cout << "Index of : " << method.lowerBound(vec,4) << endl;

    // C++ Shortcut
    cout << "Lower Bound Index : " << lower_bound(vec.begin(), vec.end(), 9) - vec.begin() << endl; 
}