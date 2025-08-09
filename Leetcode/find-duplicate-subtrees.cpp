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
    
    
    string dfs(TreeNode* root, vector<TreeNode*>& ans, unordered_map<string, int> &store, char child){
        
        string res = "";
        if(root == NULL) return res+child;
         
        
        string left = dfs(root->left, ans, store, 'l'); res+= left; // left
        string mid  = to_string(root->val); res += mid;// root
        string right = dfs(root-> right, ans, store, 'r'); res += right;// right
        
        
        if(store[res] > 0 && store[res] < 2){
            store[res]++;
            ans.push_back(root);
            cout << res << " left: " << left << " mid: " << mid << " right: " << right << endl;
        }
        else store[res]++;
        return res;
        
        
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // dfs
        // for every node we will be storing a string that contain inorder traversal of the node
        
        // prob: need to distinguise which is left and which is right 
        // palindroms can make problem......... x0x + 0 + x === x + 0 + x0x
        // so make it l + 0 + l 0 r
        // still not sure will be entirely okay..although test cases passed
        
        
        unordered_map<string, int> store;
        vector<TreeNode*> res;
        
        dfs(root,res, store,'l');
        
        return res;
    }
};

// prob: https://leetcode.com/problems/find-duplicate-subtrees/submissions/
