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
    TreeNode* solve(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int,int> &mp){
        if(preStart > preEnd || inStart > inEnd){
            return NULL;
        }

        // root is always preOrder[preStart]

        TreeNode *root = new TreeNode(preorder[preStart]);

        int rootIndexInorder = mp[preorder[preStart]];
        int leftSubtreeLen = rootIndexInorder - inStart;

        root->left = solve(preorder, preStart+1, preStart+leftSubtreeLen, inorder, inStart, rootIndexInorder-1, mp);
        root->right = solve(preorder, preStart+leftSubtreeLen+1, preEnd, inorder, rootIndexInorder+1, inEnd, mp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int, int> mp; // node, index

        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return solve(preorder,0,preorder.size()-1, inorder, 0, inorder.size()-1, mp);
    }
};

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// https://www.youtube.com/watch?v=aZNaLrVebKQ&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=106&pp=iAQB