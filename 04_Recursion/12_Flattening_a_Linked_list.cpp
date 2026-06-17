#include <iostream> 
#include <bits/stdc++.h>
using namespace std; 


class Solution {
  public:
    
    Node* mergeTwoSortedList(Node* l1, Node* l2){
        if(!l2) return l1; 
        if(!l1) return l2; 
        
        Node* result; 
        
        if(l1->data < l2->data){
            result = l1; 
            result->bottom = mergeTwoSortedList(result->bottom, l2); 
        }else{
            result = l2; 
            result->bottom = mergeTwoSortedList(l1, result->bottom); 
        }
        return result; 
    }
    
  
    Node *flatten(Node *root) {
        // Base condition 
        if(root == NULL){
            return NULL; 
        }
        
        
        Node* root2 = flatten(root->next); 
        return mergeTwoSortedList(root, root2); 
    }
};