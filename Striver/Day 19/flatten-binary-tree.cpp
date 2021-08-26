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
    
    void solve(TreeNode* root){
           if(root == NULL) return;
        
//         if(root->left) 
//         {
//             TreeNode* right = root->right;
//             flatten(root->left);
//             root->right = root->left;
//             root->left
//         }
        
        flatten(root->left);
        flatten(root->right);
        
        if(root->left)
        {
            TreeNode* temp = root->right;
            TreeNode* leftHead = root->left;

            root->right = root->left;
            root->left = NULL;
            while(leftHead!=NULL && leftHead->right != NULL)
            {
                leftHead = leftHead->right;
            }

            leftHead->right = temp;
        }
        
    }
    void flatten(TreeNode* root) {
        
        solve(root);
    }
};

// flatten a binary tree
// prb: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/