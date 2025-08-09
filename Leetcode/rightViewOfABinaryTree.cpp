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
    vector<int> rightSideView(TreeNode* root) {
        
        // level order traversal and print the last node
        
        vector<int> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                if(size == 0)
                {
                    TreeNode* temp = q.front();
                    q.pop();
                    ans.push_back(temp->val);
                    if(temp->left != NULL) q.push(temp->left);
                    if(temp->right != NULL) q.push(temp->right);
                }
                else
                {
                    TreeNode* temp = q.front();
                    q.pop();
                    if(temp->left != NULL) q.push(temp->left);
                    if(temp->right != NULL) q.push(temp->right);
                }
            }
        }
        
        return ans;
        
    }
};

/*
https://leetcode.com/problems/binary-tree-right-side-view/
*/