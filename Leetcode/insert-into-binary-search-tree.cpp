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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        if(val < root->val && root->left != NULL) insertIntoBST(root->left, val);
        else if(val < root->val && root->left == NULL) {root->left = new TreeNode(val); return root;}
        if(val > root->val && root->right != NULL) insertIntoBST(root->right, val);
        else if(val > root->val && root->right == NULL) {root->right = new TreeNode(val); return root;}
        return root;
    }
};

// https://leetcode.com/problems/insert-into-a-binary-search-tree/