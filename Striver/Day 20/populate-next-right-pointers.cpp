class Solution {
public:
    
    void helper(Node* root)
    {
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            while(size--) // level order traversal of tree
            {
                Node* curr = q.front(); q.pop();
                if(size == 0) curr->next = NULL; // if size = 0 means we are at the last node of the level--> next will be null
                else
                {
                    curr->next = q.front(); // else the next will be the node we will be exploring next
                }
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }    
    }
    Node* connect(Node* root) {
        if(root == NULL) return root;
        helper(root);
        return root;
        
    }
};
// prb: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

// recursive approach

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        
        if(root->left)
        {
            root->left->next = root->right;
        }
        
        if(root->next && root->right)
        {
            root->right->next = root->next->left;
        }
        
        connect(root->left);
        connect(root->right);
        
        return root;
    }
};
// soln: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/discuss/1406207/C%2B%2B-oror-Faster-than-98-oror-Recursive-solution