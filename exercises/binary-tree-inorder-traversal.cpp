/*
 * https://leetcode.com/problems/binary-tree-inorder-traversal/
 * https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
    
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode *> stack;
        vector<int> output;
        
        TreeNode * current = root;
        
        while(true) {
            
            while(current) {
                stack.push_back(current);
                current = current->left;
            }
            
            if(! stack.empty()) {
                current = stack.back();
                stack.pop_back();
                
                //Print the result
                output.push_back(current->val);
                
                current = current->right;
            }
            else {
                break;
            }
        }
        
        return output;
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
                vector<TreeNode *> stack;
        vector<int> output;
        
        TreeNode * current = root;
        
        while(true) {
            
            while(current) {
                stack.push_back(current);

                // Print the result
                output.push_back(current->val);
                
                current = current->left;
            }
            
            if(! stack.empty()) {
                current = stack.back();
                stack.pop_back();
                current = current->right;
            }
            else {
                break;
            }
        }
        
        return output;
    }
    
    
};
