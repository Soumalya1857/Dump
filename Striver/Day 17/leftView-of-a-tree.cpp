 void print(Node* root, vector<int>&ans)
 {
     if(root == NULL) return;
     queue<Node*> q;
     q.push(root);
     while(!q.empty())
     {
         int size = q.size();
         int track = size;
         while(size--)
         {
             Node* curr = q.front();q.pop();
             if(size == track-1) ans.push_back(curr->data);
             
             if(curr->left != NULL) q.push(curr->left);
             if(curr->right != NULL) q.push(curr->right);
         }
     }
     
     //return ans;
 }
//soln: https://www.geeksforgeeks.org/print-left-view-binary-tree/


//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   print(root, ans);
   return ans;
}

// recursive
void leftViewUtil(struct Node *root,
                int level, int *max_level)
{
    // Base Case
    if (root == NULL) return;
 
    // If this is the first Node of its level
    if (*max_level < level)
    {
        cout << root->data << " ";
        *max_level = level;
    }
 
    // Recur for left subtree first,
    // then right subtree
      leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
     
}
 
// A wrapper over leftViewUtil()
void leftView(struct Node *root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}