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
    int val = 0;
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL) return root;
        solve(root);

        return root;
    }

    void solve(TreeNode* curr){
        if(curr == NULL) return;

        solve(curr->right);
        curr->val += val;
        val = curr->val;
        solve(curr->left);
    }
};

// solve(curr->right, orderNode);







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
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL) return root;
        vector<TreeNode*> orderNode;
        solve(root, orderNode);

        int suffix = 0;

        suffix = orderNode[orderNode.size()-1]->val;

        for(int i=orderNode.size()-2; i>=0; i--){
            suffix += orderNode[i]->val;
            orderNode[i]->val = suffix;
        }

        return root;
    }

    void solve(TreeNode* curr, vector<TreeNode*>&orderNode){
        if(curr == NULL) return;

        solve(curr->left, orderNode);
        orderNode.push_back(curr);
        solve(curr->right, orderNode);
    }
};

// https://leetcode.com/problems/convert-bst-to-greater-tree/submissions/1116896415/