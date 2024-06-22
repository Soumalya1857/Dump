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

private:
    int returnMaxSum(TreeNode* node, int &maxSum){
        if(node == NULL){
            return 0;
        }

        int leftTreeSum = returnMaxSum(node->left, maxSum);
        int rightTreeSum = returnMaxSum(node->right, maxSum);

        maxSum = max(maxSum, node->val + max(leftTreeSum,0) + max(rightTreeSum,0));

        return max(node->val + max(leftTreeSum, max(rightTreeSum,0)), 0);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;

        returnMaxSum(root, maxSum);

        return maxSum;
    }
};

// https://leetcode.com/problems/binary-tree-maximum-path-sum/