// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
        
//         queue<TreeNode*> q;
//         q.push(root);
//         int maxi = -1;
//         while(!q.empty())
//         {
//             int count = 0;
//             int size = q.size();
//             while(size--)
//             {
//                 TreeNode* curr = q.front();q.pop();
//                 if(curr!= NULL)
//                 {
//                     if(curr->left!=NULL || curr->right != NULL){
//                     q.push(curr->left);
//                     q.push(curr->right);
//                     }
//                 }
//             }
//             count = q.size();
//             maxi = max(maxi,count);
//         }
        
//         return maxi;
//     }
// };

// not the best solution 
// doesn't include the bamboo case


########################################################################

// this is not a valid approach
        // so we basically need to assign number according to the array representation
        // of an array. then find the max difference b/t those numbers
        
        
int widthOfBinaryTree(TreeNode* root) {        
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int maxi = -1;
        while(!q.empty())
        {
            pair<TreeNode*, int> top;
            int index = INT_MAX;
            int size = q.size();
            while(size--)
            {
                 top = q.front(); q.pop();
                 if(index == INT_MAX)
                     index = top.second;
                
                 if((top.first)->left != NULL) 
                     q.push(make_pair((top.first)->left, 2*(top.second-index)));
                 if((top.first)->right != NULL) 
                     q.push(make_pair((top.first)->right, 2*(top.second-index)+1));
                 
            }
            
            maxi = max(maxi, (top.second-index));
            
        }
        return maxi+1;
        
    }