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
    
    bool isPresent(TreeNode* root, int k){
        while(root != NULL){
            
            if(k == root->val) return true;
            else if(k > root->val) root = root->right;
            else root = root->left;
        }
        
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        
        TreeNode* newRoot = root;
        
        stack<TreeNode*> s;
        s.push(newRoot);
        
        while(!s.empty()){
            
            TreeNode* curr = s.top(); s.pop();
            int target = k-curr->val;
            
            
            if(isPresent(root, target) && (2 * curr->val != k)) return true;
            
            if(curr->left) s.push(curr->left);
            if(curr->right) s.push(curr->right);
        }
        
        return false;
    }
};

//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// inorder traversal and then 2 pointer method

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
    
    void inorder(TreeNode* root, vector<int>& store){
        if(root == NULL) return;
        
        inorder(root->left, store);
        store.push_back(root->val);
        inorder(root->right, store);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> store;
        inorder(root,store);
        
        int low = 0, high = store.size() - 1;
        while(low < high){
            
            int sum = store[low] + store[high];
            if( sum == k) return true;
            
            if(sum > k) high--;
            else low++;
        }
        
        return false;
    }
};

// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/submissions/
