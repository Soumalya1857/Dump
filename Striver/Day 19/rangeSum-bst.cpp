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
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if(root == NULL) return 0;
        if(root->val < low)
            return rangeSumBST(root->right, low, high);
        
        if(root->val > high)
            return rangeSumBST(root->left,low,high);
        
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right,low,high);
    }
};

// prb: https://leetcode.com/problems/range-sum-of-bst/submissions/
// soln: https://leetcode.com/problems/range-sum-of-bst/solution/

// iterative approach
// dfs with the conditions
class Solution {
    public int rangeSumBST(TreeNode root, int L, int R) {
        int ans = 0;
        Stack<TreeNode> stack = new Stack();
        stack.push(root);
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            if (node != null) {
                if (L <= node.val && node.val <= R)
                    ans += node.val;
                if (L < node.val)
                    stack.push(node.left);
                if (node.val < R)
                    stack.push(node.right);
            }
        }
        return ans;
    }
}