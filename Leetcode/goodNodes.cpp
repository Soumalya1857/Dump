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
    int goodNodes(TreeNode* root) {
        
        
        int count = 0;
        stack<pair<TreeNode*, int>> s; // treenode & maxValue of the path
        s.push({root,INT_MIN});
        
        while(!s.empty())
        {
            auto top = s.top(); s.pop();
            TreeNode* curr = top.first;
            int maxVal = top.second;
            if(curr->val >= maxVal)
            {
                count++;
                maxVal = curr->val;
                //cout << "val: " << curr->val << "\n";
            }
            
            if(curr->left != NULL) s.push({curr->left,maxVal});
            if(curr->right != NULL) s.push({curr->right, maxVal});
        }
        
        return count;
    }
};

/*
https://leetcode.com/problems/count-good-nodes-in-binary-tree/submissions/
*/