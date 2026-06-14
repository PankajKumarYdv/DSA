#include <iostream> 
#include <vector> 
#include <algorithm>

using namespace std; 

class Solution{
    public: 
    int upperBound(vector<int>& vec, int x){
        int low = 0; 
        int high = vec.size() - 1; 
        int ans = vec.size(); 

        while(low <= high){
            int mid = (low + high) / 2; 
            if(vec[mid] > x){
                ans = mid; 
                high = mid -1; 
            }else{
                low = mid + 1; 
            }
        }
        return ans; 
    }
};

int main(){
    Solution method; 
    vector <int> vec = {2,3,6,7,8,8,11,11,11,12}; 

    // upper bound 
    int x; 
    cout << "Enter Element : "; 
    cin >> x; 
    cout << "Upper Bound : " << method.upperBound(vec, x) << endl; 


    // C++ Shortcut 
    cout << "C++ Shortcut Method : "<< upper_bound(vec.begin(), vec.end(), x) - vec.begin() << endl;

}