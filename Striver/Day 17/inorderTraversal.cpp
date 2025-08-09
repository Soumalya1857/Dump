class Solution {
  public:
    
    void traverse(Node* root, vector<int>&ans)
    {
        // iterative approach
        stack<Node*>s;
        s.push(root);
        Node* curr = s.top(); s.pop();
        while(!s.empty() || curr!=NULL)
        {
            while(curr!=NULL)
            {
                s.push(curr);
                curr=curr->left;
            }
            
            curr = s.top();
            s.pop();
            ans.push_back(curr->data);
            curr = curr->right;
        }
    }
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int>ans;
        traverse(root,ans);
        return ans;
    }
};