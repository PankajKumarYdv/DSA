#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;


struct trieNode{
    trieNode* child[26]; 
    bool isEndOfWord; 
};

trieNode* getNode(){
    trieNode* newNode = new trieNode(); 
    newNode->isEndOfWord = false; 
    for(int i = 0; i < 26; i++){
        newNode->child[i] = NULL; 
    }
    return newNode; 
}


class Trie{
    public: 
        trieNode* root; 

        Trie(){
            root = getNode(); 
        }

        // Insert Method 
        void insert(string word){
            trieNode* crawl = root; 
            for(int i = 0; i < word.length(); i++){
                int idx = word[i] - 'a'; 
                if(crawl->child[idx] == NULL){
                    crawl->child[idx] = getNode();
                }
                crawl = crawl->child[idx];
            }
            crawl->isEndOfWord = true; 

        }

        // Search Method 
        bool searchPrefix(string prefix){
            trieNode* crawl = root; 
            for(int i = 0; i < prefix.length(); i++){
                int idx = prefix[i] - 'a'; 
                if(crawl->child[idx] == NULL){
                    return false;  
                }
                crawl = crawl->child[idx];
            }
            return true; 
        }
}; 

class Solution{
    public: 
    int countPrefixSuffixParis(vector<string>& words){
        int n = words.size(); 
        int cnt = 0; 
        for (int  j= 0; j < n; j++){
            Trie prefixTrie; 
            Trie suffixTrie; 

            prefixTrie.insert(words[j]); 
            string reversed = words[j];
            reverse(begin(reversed), end(reversed)); 

            suffixTrie.insert(reversed); 

            for(int i = 0; i < j ; i++){
                if(words[i].length()  > words[j].length()) continue; 

                string rev = words[i]; 
                reverse(begin(rev), end(rev)); 
                if(prefixTrie.searchPrefix(words[i]) == true && suffixTrie.searchPrefix(rev) == true ){
                    cnt ++; 
                }
            }
        }
        return cnt; 
    }
};



int main(){
    cout << "Hello Pankaj" << endl; 
}