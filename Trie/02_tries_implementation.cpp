/*
    Implementation of Tries Leetcode : 208
*/

#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 


class Trie{
    public: 
    
    // structuring tries node
    struct trieNode{
        bool isEndofWord; 
        trieNode* child[26]; 
    }; 

    // creating node 
    trieNode* getNode(){
        trieNode* newNode = new trieNode(); 
        newNode->isEndofWord = false; 
        for(int i = 0; i < 26; i++){
            newNode->child[i] = NULL; 
        }
        return newNode; 
    }

    // 
    trieNode* root; 
    Trie(){ /* <- constructor 
        Have same name as class name, 
        No return type, 
        Automatically called when object is created.
        */
        root = getNode(); 
    }


    // Insert 
    void insert(string word){
        trieNode* chrowler = root; 
        for(char ch : word){
            int idx = ch-'a'; 
            if(chrowler->child[idx] == NULL){
                chrowler->child[idx] = getNode(); 
            }
            chrowler = chrowler->child[idx]; 
        }
        chrowler->isEndofWord = true; 
    }


    // search 
    bool search(string word){
        trieNode* chrowler = root; 
        for(char ch : word){
            int idx = ch - 'a'; 
            if(chrowler->child[idx] == NULL) return false; 
            chrowler = chrowler->child[idx]; 
        }

        if(chrowler->isEndofWord = true && chrowler != NULL) return true; 
        return false; 
    }


    // start with 
    bool startWith(string word){
        trieNode* chrowler = root; 
        int i = 0; 
        for(; i < word.length(); i++){
            char ch = word[i]; 
            int idx = ch - 'a'; 
            if(chrowler->child[idx] == NULL){
                return false; 
            }
            chrowler = chrowler->child[idx]; 
        }
        if(i==word.length()) return true; 
        return false;
    }
}; 


int main(){
    Trie m; 
    string word = "apple"; 
    
    // insert 
    m.insert(word); 
    
    // search 
    cout << m.search(word) << endl ; // 1
    cout << m.search("pankaj") << endl;  // 0 
    
    // start with

    cout << m.startWith("app") << endl; 
    cout << m.startWith("Kin") << endl; // 0



}