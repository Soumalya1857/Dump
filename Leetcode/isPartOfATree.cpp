/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
    
//     bool isIdentical(TreeNode* t1, TreeNode* t2)
//     {
//         if(t1 == NULL && t2 == NULL ) return true;
//         if(t1 == NULL || t2 == NULL) return false;
        
//         else return (t1->val == t2-> val 
//                     && isIdentical(t1->left,t2->left)
//                     && isIdentical(t1->right, t2->right)
//                     );
//     }
//     bool isSubtree(TreeNode* s, TreeNode* t) {
        
//         if(s == NULL) return false;
//         else return (isIdentical(s,t)
//                     || isSubtree(s->left, t)
//                     || isSubtree(s->right, t)
//                     ) ;   
//     }
// };


class Solution {
public:
    bool helper(TreeNode *s, TreeNode *t) {
        if (!t && !s) return true;
        if ((t && !s) || (!t && s) || t->val != s->val) return false;
        return helper(s->left, t->left) & helper(s->right, t->right);
    }
    void inOrderTrav(TreeNode *s, TreeNode* t, bool &ret) {
        if (ret) return;
        if (helper(s,t)) ret = true;
        if (s->left) inOrderTrav(s->left, t, ret);
        if (s->right) inOrderTrav(s->right, t, ret);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool ret = false;
        inOrderTrav(s, t, ret);
        return ret;
    }
};

// better solution



/*
https://leetcode.com/problems/subtree-of-another-tree/
sol - https://leetcode.com/problems/subtree-of-another-tree/solution/

*/