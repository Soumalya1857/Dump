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
    
    void solve(TreeNode* root, int len, string direction, int& ans){
        if(root == NULL) return;
        
        if(direction == "L"){
            if(root->left) solve(root->left, 1, "L", ans);
            if(root->right) solve(root->right, len+1, "R", ans);
        }
        else{
            if(root->left) solve(root->left, len+1, "L", ans);
            if(root->right) solve(root->right, 1, "R", ans);
        }
        
        ans = max(ans, len);

    
    int longestZigZag(TreeNode* root) {
        int ans = INT_MIN;
        solve(root,0,"L",ans);
        solve(root,0, "R",ans);
        
        return ans;
    }
};
// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree