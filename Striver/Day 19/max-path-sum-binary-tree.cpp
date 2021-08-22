class Solution {
public:
    
    int sum(TreeNode* root, int &ans)
    {
        if(root == NULL) return 0;
        
        int left = sum(root->left,ans);
        int right = sum(root->right,ans);  
        
        int currMax = root->val + max(left,0) + max(right,0);
        ans = max(ans, currMax);
        
        return max(left,max(right,0)) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        
        int ans=INT_MIN;
        sum(root,ans);
        return ans;
    }
    
    // prb: https://leetcode.com/problems/binary-tree-maximum-path-sum/
    // soln: https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/
};