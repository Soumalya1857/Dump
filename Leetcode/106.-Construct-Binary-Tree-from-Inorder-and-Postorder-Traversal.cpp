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
    TreeNode* solve(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int,int> &mp){
        if(postStart > postEnd || inStart > inEnd){
            return NULL;
        }

        // root = postEnd

        TreeNode *root = new TreeNode(postorder[postEnd]);
        int rootIndexIn = mp[postorder[postEnd]];

        int lenLeftSubTree = rootIndexIn-inStart;

        root->left = solve(postorder, postStart, postStart+lenLeftSubTree-1, inorder, inStart, rootIndexIn-1, mp);
        root->right = solve(postorder,postStart+lenLeftSubTree, postEnd-1, inorder, rootIndexIn+1, inEnd, mp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;

        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return solve(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mp);
    }
};

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submissions/1313249399/
// https://www.youtube.com/watch?v=LgLRTaEMRVc&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=107&pp=iAQB