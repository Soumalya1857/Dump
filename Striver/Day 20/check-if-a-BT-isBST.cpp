class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    
    int isBSTUtil(Node* node, int min, int max)
    {
        /* an empty tree is BST */
        if (node==NULL)
            return 1;
                 
        /* false if this node violates
        the min/max constraint */
        if (node->data < min || node->data > max)
            return 0;
         
        /* otherwise check the subtrees recursively,
        tightening the min or max constraint */
        return
            isBSTUtil(node->left, min, node->data-1) && // Allow only distinct values
            isBSTUtil(node->right, node->data+1, max); // Allow only distinct values
    }


    bool isBST(Node* root) 
    {
        // bool left = false;
        // bool right = false;
        // // Your code here
        // if(root == NULL) return true;
        
        // if(root->left)
        // {
        //      if (root->left->data < root->data) left = isBST(root->left);
        //      else return false;
        // }
        // else left = true;
        
        // if(root->right)
        // {
        //     if(root->right->data > root->data) right = isBST(root->right);
        //     else return false;
        // }
        // else right = true;
        
        
        // return left && right;
        
        return isBSTUtil(root,INT_MIN,INT_MAX);
    }
};

// soln: https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/