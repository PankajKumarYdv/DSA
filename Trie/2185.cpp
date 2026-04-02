#include <iostream> 
#include <vector> 
using namespace std;

class Leetcode{
    public: 
    struct trieNode{
        trieNode* child[26]; 
    };

    // Node 
    trieNode* getNode(){
        trieNode* newNode = new trieNode(); 
        for(int i = 0 ; i < 26; i++){
            newNode->child[i] = NULL; 
        }
        return newNode; 
    }

    trieNode* root;

    Leetcode(){
        root = getNode();
    }

    // Logic 
    void insert(string words){
        trieNode* crawl = root; 
        for(char ch : words){
            int indx = ch - 'a'; 
            if(crawl->child[indx] == NULL){
                crawl->child[indx] = getNode(); 
            }
            crawl = crawl->child[indx]; 
        }
    }

    bool search(string words, int prefixLength){
        trieNode* crawl = root; 
        for(int i = 0; i < prefixLength; i++){
            int indx = words[i]-'a'; 
            if(crawl->child[indx] == NULL){
                return false; 
            }
            crawl = crawl->child[indx]; 
        }
        return true; 
    }

    int prefixCount(vector<string>& words, string pref) {
        // inserting 
        insert(pref); 

        // 
        int cnt = 0; 
        for(auto word : words){
            if(search(word, pref.size())) cnt++; 
            else continue; 
        }
        return cnt; 
    }

}; 

int main(){
    Leetcode k; 
    vector <string> words = {"pay", "attention", "practice", "attend"}; 

    cout << k.prefixCount(words, "at"); 
}