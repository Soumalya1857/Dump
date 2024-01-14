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
        stack<pair<TreeNode*, int>> s; // node, maxVal till that node

        s.push({root, root->val});
        int good = 0;
        while(!s.empty()){
            pair<TreeNode*, int> curr = s.top(); s.pop();

            if(curr.second <= curr.first->val){
                good++;
                curr.second = curr.first->val;
            }

            if(curr.first->left != NULL) s.push({curr.first->left, curr.second});
            if(curr.first->right != NULL) s.push({curr.first->right, curr.second});
        }

        return good;
    }
};

// https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/

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
    int solve(TreeNode *root,int curmax){
        if(root==NULL){
            return 0;
        }

        if(root->val>=curmax){
            return 1+solve(root->left,root->val)+solve(root->right,root->val);
        }else{
            return solve(root->left,curmax)+solve(root->right,curmax);
        }

    }

    int goodNodes(TreeNode* root) {
        int ans=solve(root,INT_MIN);
        return ans;
    }
};

// recursive solution babu