class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }
    
    pair<int,int> dfs(TreeNode* root, int& ans)
    {
        if(root->right == NULL && root->left == NULL) return make_pair(max(root->val,1),min(root->val,1));
        if(root == NULL) return make_pair(1,1);
        
        auto left = dfs(root->left, ans);
        auto right = dfs(root->right, ans);
        
        int leftMax = left.first;
        int rightMax = right.first;
        int leftMin = left.second;
        int rightMin = right.second;
        
        int  curr; pair<int,int> t;
        
        if(root->val > 0)
        {
            int temp1 = leftMax*rightMax;
            int temp2 = leftMin * rightMin;
            
            curr = max(temp1, temp2) * root->val;
            
            int left = max(max(leftMax,rightMax) * root->val, 1);
            int right = min(min(leftMin, rightMin) * root->val, 1);
            
            t = make_pair(left, right);
        }
        else if(root->val < 0)
        {
            int temp1 = leftMin * rightMax;
            int temp2 = leftMax * rightMin;
            
            curr = min(temp1 , temp2)*root->val;
            
            int left = max(min(leftMin, rightMin) * root->val , 1);
            int right = min(max(rightMax, leftMax)* root->val, 1);
            
            t = make_pair(left, right);
        }
        
        ans = max(ans, curr);
        return t;
        
    }
};