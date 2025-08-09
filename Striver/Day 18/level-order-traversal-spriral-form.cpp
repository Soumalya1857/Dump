void traverse(Node* root, vector<int>&ans)
{
    queue<Node*>q;
    vector<int> temp;
    q.push(root);
    bool itr = false; // left to right traverse
    while(!q.empty())
    {
        int size = q.size();
        itr = !itr;
        while(size--)
        {
            Node* curr = q.front();q.pop();
            if(itr)
            {
                temp.push_back(curr->data);
            }
            else
            {
                ans.push_back(curr->data);
            }
            
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        
        if(itr) 
        {
            reverse(temp.begin(),temp.end());
            for(auto x:temp) ans.push_back(x);
            
            temp.clear();
        }
    }
}


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int>ans;
    if(root == NULL) return ans;
    traverse(root,ans);
    return ans;
}

// prb: https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1
// soln: https://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/