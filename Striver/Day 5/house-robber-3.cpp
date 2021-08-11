
// problem: https://leetcode.com/problems/house-robber-iii/
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

// initial solution
// represent the tree as a array
// adjacent is i -> 2i && 2i+1 nodes
// apply house robber 1 logic

class Solution {
public:
    
    int countNodes(TreeNode* root)
    {
        int count = 0;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* curr = s.top();
            s.pop();
            count++;
            if(curr->left != NULL) s.push(curr->left);
            if(curr->right != NULL) s.push(curr->right);
        }
        
        return count;
    }
    
    void populateTree(TreeNode* root, vector<int>& tree)
    {
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        tree[1] = 1;
        while(!q.empty())
        {
            pair<TreeNode*,int> curr = q.front();
            q.pop();
            TreeNode* currNode = curr.first;
            int nodeNumber = curr.second;
            tree[nodeNumber] = currNode->val;
            
            if(currNode->left != NULL) q.push({currNode->left, 2*nodeNumber});
            if(currNode->right != NULL) q.push({currNode->right, 2*nodeNumber+1});
        }
    }
    int rob(TreeNode* root) {
        
        // we can express the tree as an array
        // then we can apply dp easily
        int nodeCount = countNodes(root);
        vector<int>dp(nodeCount+1,0);
        vector<int> tree(nodeCount+1,-1);
        
        // populate tree vector with the values
        
        populateTree(root, tree);
        
        
        dp[1] = tree[1];
        for(int i=2;i<=nodeCount;i++)
        {
            if(i/2 != i/4) dp[i] = max(dp[i], max(dp[i/2], dp[i/4] + tree[i]));
            else dp[i] = max(dp[i], max(tree[i], tree[i/2]));
        }
        
        return dp[nodeCount];
    }
};



// recursive memorization technique
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
    unordered_map<TreeNode*, int> mp; // contains max value of get by robbing a node
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        if(mp.count(root)) return mp[root];
        mp[root] = max(robRoot(root), notRobRoot(root));
        return mp[root];
    }
    int robRoot(TreeNode* root)
    {
        if(root == NULL) return 0;
        return root->val + notRobRoot(root->left) + notRobRoot(root->right);
    }
    
    int notRobRoot(TreeNode* root)
    {
        if(root == NULL) return 0;
        return rob(root->left) + rob(root->right);
    }
    
};
// soln: https://leetcode.com/problems/house-robber-iii/discuss/1388436/87-Faster-oror-Very-Easy-to-understand-Explained

// class Solution {
public:
    map<TreeNode*, int> m; //to store the max value for a particular node
    
    int rob(TreeNode* root) {
        if(root == nullptr)
            return 0;
        if(m.find(root) != m.end())
            return m[root];
        
        int l = 0, r = 0, curr;
        if(root->left != nullptr)
            l = rob(root->left->left) + rob(root->left->right);
        if(root->right != nullptr)
            r = rob(root->right->left) + rob(root->right->right);

        //for a particular node, the maximum achieved value can be either when we exclude itself taking its right
		//and left children's values or by taking it and ignoring its right and left children but taking their children 
        curr = max(l + r + root->val, rob(root->left) + rob(root->right));
        m[root] = curr;
        return curr;
    }
};
// https://leetcode.com/problems/house-robber-iii/discuss/1349210/C%2B%2B-easy-solution-using-DP-explained-with-comments