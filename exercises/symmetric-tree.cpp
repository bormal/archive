// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
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
    bool helper(TreeNode* l, TreeNode* r) {
        if(! l && ! r) return true;
        if( (! r && l) || (r && !l) ) return false;
        if(l->val != r->val) return false;
        return helper(l->left, r->right) && helper(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        // cout << "0\n";
        if(! root) return true;
        return helper(root->left, root->right);
    }
};
