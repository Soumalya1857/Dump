class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    
    int height(Node* root)
    {
        if(root == NULL) return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        return 1 + max(left,right);
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(root == NULL) return true;
        int left = height(root->left);
        int right = height(root->right);
        
        return abs(left-right)<=1 && isBalanced(root->left) && isBalanced(root->right) ? true : false;
    }
};
// prb: https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
// soln: https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/
