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
        // need to do it iteratively bro
        
        vector<int> ans;
        if(root == NULL) {/*ans.push_back(0);*/return ans;}
        stack<TreeNode*> s;
        TreeNode* top = root;
        //s.push(top);
        while(!s.empty() || top != NULL)
        {
            while(top != NULL)
            {
                s.push(top);
                top = top->left;
            }
            
            top = s.top();
            s.pop();
            ans.push_back(top->val);
            top = top->right; 
        }
        
        return ans;
    }
};

/*
https://leetcode.com/problems/binary-tree-inorder-traversal/
*/