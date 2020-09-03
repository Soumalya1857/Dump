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
    int findBottomLeftValue(TreeNode* root) {
        
        vector<pair<int,int>>leaf;// val, height
        
        TreeNode* copy = root;
        int height = 0;
        int maxHeight = -1;
        
        queue<TreeNode*> q;
        q.push(copy);
        while(!q.empty())
        {
            int size = q.size();
            height++;
            while(size--)
            {
                TreeNode* curr = q.front();q.pop();
                if(curr->left == NULL && curr->right == NULL)
                {
                     leaf.push_back({curr->val,height});
                     maxHeight = max(height, maxHeight);
                }
                   
                
                else
                {
                    if(curr->left != NULL) q.push(curr->left);
                    if(curr->right != NULL) q.push(curr->right);
                }
            }
        }
        
        for(auto le : leaf)
        {
            if(le.second == maxHeight)
            {
                height = le.first;
                break;
            }
        }
        
        return height;
    }
};

/*
https://leetcode.com/problems/find-bottom-left-tree-value/submissions/
*/