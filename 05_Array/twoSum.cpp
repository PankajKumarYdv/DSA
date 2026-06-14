#include <iostream> 
#include <vector> 
#include <map>
using namespace std; 

class Leetcod{
    public:

    // bruteForce
    vector<int> twoSum(vector<int>& v, int target){
        for(int i = 0; i < v.size()-1; i++) {
            for (int j = i+1 ; j < v.size(); j++){
                if(v[i] + v[j] == target){
                    cout << "Exist at " << i << " " << j; 
                    return {i,j}; 
                }
            }
        }
        return {0,0}; 
    }

    // Hash Map
    vector<int> hashMapTwoSum(vector<int>& v, int target){
        map <int,int> record; 
        for(int i = 0; i < v.size(); i++){
            if(record.count(target-v[i]) == 0){
                record.insert({v[i],i}); 
            }else{
                return {record.at(target-v[i]), i};
            }
        }
        return {0,0}; 
    }

};

int main(){
    vector <int> arr = {2,7,11,15}; 
    int target = 9;
    // Object 
    Leetcod method; 
    vector <int> result = method.hashMapTwoSum(arr, target); 
    cout << "Result : " << result[0] << " " << result[1]; 

}
