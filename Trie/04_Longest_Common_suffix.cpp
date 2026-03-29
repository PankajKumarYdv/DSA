/*
    Leetcode : 3043
*/

#include <iostream> 
#include <vector> 
#include <string>

using namespace std; 

class Leetcode{
    public: 
    
    struct trieNode{
        trieNode* child[10]; 
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode(); 
        for(int i = 0; i < 10; i++){
            newNode->child[i] = NULL; 
        }
        return newNode; 
    }

    trieNode* root; 
    Leetcode(){
        root = getNode(); 
    }


    // insert 
    void insert(string number){
        trieNode* crowl = root; 

        for(char ch : number){
            int index = ch - '0'; // Getting index 
            if(crowl->child[index] == NULL){
                crowl->child[index] = getNode(); 
            }
            crowl = crowl->child[index]; 
        }
         
    }

    // searching 
    bool search(string number){
        trieNode* crowl = root; 
        int n = number.size()-1; 
        for(int i = 0;i<=n;i++){
            int index = number[i] - '0'; 
            if(crowl->child[index] == NULL) return false; 
            crowl = crowl->child[index]; 
        }
        return true; 
    }



    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int result = 0; 

        for(int ele : arr2){
            string s = std::to_string(ele);  // // Converting number to string; 
            insert(s); 
        }

        for(int ele : arr1){
            string s = std::to_string(ele); 
            if(search(s)) result++;
        }

        return result; 
    }
};

int main(){
    Leetcode m; 
    vector<int> arr1 = {1,10,100}; 
    vector<int> arr2 = {1000}; 
    // m.insert(arr2[0]); 
    cout << m.longestCommonPrefix(arr1, arr2) << endl; 
}