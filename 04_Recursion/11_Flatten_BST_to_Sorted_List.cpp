#include <iostream> 
#include <bits/stdc++.h> 
using namespace std; 

class Node {
	public:
	int data;
	Node *left;
	Node *right;
	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

class Solution {
	public:
	Node *flattenBST(Node *root) {
		// Base Condition
		if (root == NULL)
			return NULL;
		
		Node* head = flattenBST(root->left); // Trust
		root->left = NULL;
		
		if (head != NULL) {
			Node* temp = head;
			while (temp != NULL && temp->right != NULL) {
				temp = temp->right;
			}
			temp->right = root;
		}else{
		    head = root; 
		}
		
		root->right = flattenBST(root->right); // Trust
		
		return head;
	}
};


int main(){
    // BST = 5, 3, 7, 2, 4, 6, 8
}