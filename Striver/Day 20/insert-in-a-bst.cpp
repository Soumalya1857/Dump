
//Function to insert a node in a BST.
Node* insert(Node* root, int key)
{   
    
    // Your code here
    if(key > root->data)
    {
        if(root->right == NULL)
        {
            root->right = new Node(key);
            return root->right;
        }
        
        else insert(root->right, key);
    }
    
    else if(root->data == key) return NULL;
    else 
    {
        if(root->left == NULL)
        {
            root->left = new Node(key);
            return root->left;
        }
        
        else insert(root->left,key);
    }
}

// https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1
// insert in a binary search tree
// https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/



// better recursive solution
BST* BST ::Insert(BST* root, int value)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }
 
    // Insert data.
    if (value > root->data)
    {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process right nodes.
        root->right = Insert(root->right, value);
    }
    else
    {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process left nodes.
        root->left = Insert(root->left, value);
    }
 
    // Return 'root' node, after insertion.
    return root;
}
 