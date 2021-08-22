void traverse(Node* root, vector<int>&ans){
    if(root == NULL) return;
    
    ans.push_back(root->data);
    traverse(root->left,ans);
    traverse(root->right,ans);
}

//Function to return a list containing the preorder traversal of the tree.
vector <int> preorder(Node* root)
{
  // Your code here
  vector<int>ans;
  traverse(root,ans);
  return ans;
}

// iterative
void traverse(Node* root, vector<int>&ans){
    
    stack<Node*> s;
    s.push(root);
    Node* curr = s.top(); s.pop();
    
    while(!s.empty() || curr)
    {
        while(curr != NULL)
        {
            ans.push_back(curr->data);
            s.push(curr);
            curr = curr->left;
        }
        
        curr = s.top(); s.pop();
        curr =  curr->right;
    }
}

//Function to return a list containing the preorder traversal of the tree.
vector <int> preorder(Node* root)
{
  // Your code here
  vector<int>ans;
  traverse(root,ans);
  return ans;
}