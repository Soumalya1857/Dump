void traverse(Node* root, vector<int>&ans)
{
    if(root == NULL) return;
    
    traverse(root->left, ans);
    traverse(root->right, ans);
    ans.push_back(root->data);
}
vector <int> postOrder(Node* root)
{
  // Your code here
  vector<int> ans;
  traverse(root, ans);
  return ans;
}


// iterative
void traverse(Node* root, vector<int>&ans)
{
    // if(root == NULL) return;
    
    // traverse(root->left, ans);
    // traverse(root->right, ans);
    // ans.push_back(root->data);
    
    
    stack<Node*>s1,s2;
    s1.push(root);
    //Node* curr = s1.pop();
    while(!s1.empty() )
    {
        // while(curr != NULL)
        // {
        //     s1.push(curr);
        //     curr = curr->left;
        // }
        
        // curr = s1.top(); s1.pop();
        // ans.push_back(curr->data);
        // s2.push(curr->right);
        
        // doing what we have done in recursion just ther reverse order
        Node* curr = s1.top(); s1.pop();
        if(curr->left) s1.push(curr->left);
        if(curr->right) s1.push(curr->right);
        
        s2.push(curr); // curr curr->right curr->left
        
    }
    
    while(!s2.empty())
    {
        Node* curr = s2.top(); s2.pop();
        ans.push_back(curr->data);
    }
}
vector <int> postOrder(Node* root)
{
  // Your code here
  vector<int> ans;
  traverse(root, ans);
  return ans;
}