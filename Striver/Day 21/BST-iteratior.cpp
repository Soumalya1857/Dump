// main idea is the iterative inorder approach but split this into 2 different function
class BSTIterator {
public:
    
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        
        TreeNode* curr = root;
       
        while(curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
    }
    
    int next() {
        
        TreeNode* curr = s.top(); s.pop();
        int ans = curr->val;
        curr = curr->right;
        while(curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        return ans;
    }
    
    bool hasNext() {
        
        return !s.empty();
    }
};
// prb: https://leetcode.com/problems/binary-search-tree-iterator/submissions/