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
class Solution {
public:
    
    bool solve(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right==NULL) return true;
        
        if(left && right) return left->val == right->val && solve(left->right, right->left) && solve(left->left, right->right);
        
        else return false;
    }
 
    bool isSymmetric(TreeNode* root) {
        
        if(root == NULL) return true;
        return solve(root->left, root->right);
        
    }
    
    // prb: https://leetcode.com/problems/symmetric-tree/submissions/
    // soln: https://leetcode.com/problems/symmetric-tree/discuss/1422549/Java-2-lines-of-code
};


// iterative
//Iterative (With Queue)
//Time: O(N), Traversing all nodes once.
//Space: O(N), Additional space required for the search queue. Worst case, insert all nodes in queue.

public boolean isSymmetric(TreeNode root) {

Queue<TreeNode> q = new LinkedList<>();
q.add(root);                            //Add root node of same tree to the Q twice
q.add(root);

while (!q.isEmpty()) {
    TreeNode t1 = q.poll();             //Remove the first node & the second node OR left & right nodes
    TreeNode t2 = q.poll();
	
    if (t1 == null && t2 == null) 
		continue;                       //Both are null, so symmetric & Continue further down the tree
    if (t1 == null || t2 == null) 
		return false;                   //Only one of them is null, so, not symmetric, return False
    if (t1.val != t2.val) 
		return false;                   //If values of current left-node and right-node  are not equal, return False
	
    q.add(t1.left);                     //Add to Q left-node's left subtree, right-node's right subtree, for next iteration to check for symmetry
    q.add(t2.right);
    q.add(t1.right);                    //Add to Q left-node's right subtree, right-node's left subtree 
    q.add(t2.left);
}
return true;
}