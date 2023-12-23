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
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;

        while(!q.empty()){
            int size = q.size();
            bool first = true;
            while(size--){
                TreeNode* curr = q.front();
                q.pop();

                if(first){
                    res = curr->val;
                    first = false;
                }

                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
            }
        }

        return res;
    }
};

// https://leetcode.com/problems/find-bottom-left-tree-value/