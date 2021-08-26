

int ceil(Node* root, int key)
{
    if(root->data == key) return  root->data;
    
    if(root->data < key) // ceil is in the right subtree
    {
        return  ceil(root->right, key);
    }

    if(root->data > key) // ceil MIGHT BE in the left...but root->data is also a good contender for this
    {
        return min(root->data. ceil(root->left,key)));
    }
}


// gfg approach
int Ceil(node* root, int input)
{
    // Base case
    if (root == NULL)
        return -1;
 
    // We found equal key
    if (root->key == input)
        return root->key;
 
    // If root's key is smaller, ceil must be in right subtree
    if (root->key < input)
        return Ceil(root->right, input);
 
    // Else, either left subtree or root has the ceil value
    int ceil = Ceil(root->left, input);
    return (ceil >= input) ? ceil : root->key;
}