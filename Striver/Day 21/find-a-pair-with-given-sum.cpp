
class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    void count(Node* root, unordered_map<int,int>&um)
    {
        if(root == NULL) return;
        
        um[root->data]++;
        
        count(root->left, um);
        count(root->right, um);
    }
    int isPairPresent(struct Node *root, int target)
    {
        //add code here.
        unordered_map<int,int> um;
        count(root, um);
        int ans = 0;
        
        // traverse
        stack<Node*> s;
        s.push(root);
        while(!s.empty())
        {
            Node* curr = s.top();s.pop();
            um[curr->data]--;
            
            if(um[target-curr->data] != 0) {ans++; break;}
            
            um[curr->data]++;
            
            if(curr->left) s.push(curr->left);
            if(curr->right) s.push(curr->right);
        }
        
        return ans>0? 1 : 0;
    }
};

// space optimized soln: A space optimized solution is discussed in previous post. (https://www.geeksforgeeks.org/find-if-there-is-a-triplet-in-bst-that-adds-to-0/)
//The idea was to first in-place convert BST to Doubly Linked List (DLL), then find pair in sorted DLL in O(n) time. 
//This solution takes O(n) time and O(Logn) extra space, but it modifies the given BST.

// efficient soln
// idea is to traverse the inorder traversal of the tree
// 
class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target)
    {
    //add code here.
    
        // maintain a stack where we will put the smallest number => left most number
        stack<Node*> s1;
        // maintain a stack where we will put max number =-> right most number
        stack<Node*> s2;
        
        // kind of two pointer approach but a bit better approach
        // two pointer on inorder traversal
        
        bool done1 = false;
        int val1 = 0;
        Node* curr1 = root;
        
        
        bool done2 = false;
        int val2 = 0;
        Node* curr2 = root;
        
        
        
        while(1)
        {
            while(done1 == false)
            {
                if(curr1 != NULL)
                {
                    s1.push(curr1);
                    curr1 = curr1->left;
                }
                else
                {
                    if(s1.empty()) done1 = true;
                    else {
                        curr1 = s1.top(); s1.pop();
                        val1 = curr1->data;
                        curr1 = curr1->right;
                        done1 = true;
                    }
                }
            }
            
            
            while(done2 == false)
            {
                if(curr2 != NULL)
                {
                    s2.push(curr2);
                    curr2 = curr2->right;
                }
                else
                {
                    if(s2.empty()) done2 = true;
                    else{
                        curr2 = s2.top();s2.pop();
                        val2 = curr2->data;
                        curr2 = curr2->left;
                        done2 = true;
                    }
                }
            }
            
            if((val1 != val2) && (val1 + val2) == target)
            {
                return 1;
            }
            
            else if((val1+val2) < target)
            {
                done1 = false;
            }
            
            else if((val1+val2)>target) done2 = false;
            
            if(val1>=val2) return 0;
        }
    }
};
// prb: https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1
// soln: https://www.geeksforgeeks.org/find-a-pair-with-given-sum-in-bst/