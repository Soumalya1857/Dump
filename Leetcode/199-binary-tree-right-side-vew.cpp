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
        queue<TreeNode*> q;
        vector<int> ans;
        if(root == NULL) return ans;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* curr = q.front(); q.pop();
                if(size == 0) ans.push_back(curr->val); 

                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr-> right);
            }
        }

        return ans;
    }

};

// https://leetcode.com/problems/binary-tree-right-side-view/submissions/1110176509/