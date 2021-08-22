class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    
    // kind of equal to max path in binary tree
    
    
    // child should return the parent max(left,right)+1 to maintain a path
    // also child need to calculate the max path considering it as a root and maintain the max result in a global variable
    int  maxPath(Node* root, int &ans)
    {
        if(root == NULL) return 0;
        
        int left = maxPath(root->left, ans);
        int right = maxPath(root->right, ans);
        
        int currMax = 1+left+right;
        ans = max(ans,currMax);
        
        return 1 + max(left,right);
    }
    int diameter(Node* root) {
        // Your code here
        int ans = INT_MIN;
        maxPath(root,ans);
        return ans;
    }
};

// prb: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
// soln : https://www.geeksforgeeks.org/diameter-of-a-binary-tree/