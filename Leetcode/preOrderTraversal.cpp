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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> s;
        
        TreeNode* curr = root;
//         s.push(curr);
//         ans.push(curr->val);
        
        while(!s.empty() || curr != NULL)
        {
            while(curr != NULL)
            {
                s.push(curr);
                ans.push_back(curr->val);
                curr = curr->left;
            }
            
            curr = s.top();
            s.pop();
            curr = curr->right;
        }
        return ans;
        
    }
};



/*
// easiest solution(intuitive)

vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        
        stack<TreeNode*> stk;
        vector<int> rs;
        
        stk.push(root);
        
        while (!stk.empty()) {
            auto cur = stk.top();
            stk.pop();
            rs.push_back(cur->val);
            
            if (cur->right)
                stk.push(cur->right);// right first because its stack 
                                    // after backtracking things get reversed
            
            if (cur->left)
                stk.push(cur->left);
        }
        
        return rs;
    }

*/

/*
https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/
*/