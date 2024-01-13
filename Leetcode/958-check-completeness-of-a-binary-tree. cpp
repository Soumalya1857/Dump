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
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL) return true;

        queue<TreeNode*> q;
        q.push(root);
        bool nullCheck = false;

        while(!q.empty()){
            TreeNode *curr = q.front(); q.pop();
            if(nullCheck && curr!= NULL) return false;

            if(curr == NULL) nullCheck = true;

            if(curr!=NULL) q.push(curr->left);
            if(curr!=NULL) q.push(curr->right);
        }

        return true;
    }
};

// https://leetcode.com/problems/check-completeness-of-a-binary-tree/
// concept of heap
// child would be at index 2i+1 or 2i+2

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
    int countNodes(TreeNode*root){
        if(!root)return 0;
        int a = countNodes(root->left);
        int b= countNodes(root->right);

        return a+b+1;
    }

    bool isCBT(TreeNode*root,int i,int n){
        if(!root)return true;

        if(i>n)return false;

        // preorder traversal
        bool a = isCBT(root->left,2*i,n);
        bool b = isCBT(root->right,2*i+1,n);

        return a&&b;
    }
    bool isCompleteTree(TreeNode* root) {

        // method-02
        // the recursive solution

        int n = countNodes(root);
        int i=1;
        return isCBT(root,i,n);
    }
};