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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode* > s;
        
        TreeNode* curr = root;
        while(!s.empty() || curr != NULL)
        {
            if(curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }
            else // when curr == NULL
            {
                TreeNode* temp = s.top() -> right;
                if(temp == NULL)
                {
                    temp = s.top();
                    s.pop();
                    res.push_back(temp->val);
                    while(temp == s.top()->right  &&  !s.empty())
                    {
                        temp = s.top();
                        s.pop();
                        res.push_back(temp->val);
                    }  
                }
                else // temp != NULL
                {
                    curr = temp;
                }
            }
        }
        
        return res;
        
    }
};

/*
https://leetcode.com/problems/binary-tree-postorder-traversal/
*/