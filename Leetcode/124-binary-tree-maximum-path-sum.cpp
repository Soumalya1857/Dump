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

private:
    int returnMaxSum(TreeNode* node, int &maxSum){
        if(node == NULL){
            return 0;
        }

        int leftTreeSum = returnMaxSum(node->left, maxSum);
        int rightTreeSum = returnMaxSum(node->right, maxSum);

        maxSum = max(maxSum, node->val + max(leftTreeSum,0) + max(rightTreeSum,0));

        return max(node->val + max(leftTreeSum, max(rightTreeSum,0)), 0);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;

        returnMaxSum(root, maxSum);

        return maxSum;
    }
};

// https://leetcode.com/problems/binary-tree-maximum-path-sum/

// java

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int solve(TreeNode root, AtomicInteger res){
        if(root == null) return 0;

        int left = solve(root.left, res);
        int right = solve(root.right, res);

        int val = root.val + Math.max(left,0) + Math.max(right,0);
        res.set(Math.max(res.get(), val));

        return root.val + Math.max(0, Math.max(left, right));
        
    }

    public int maxPathSum(TreeNode root) {
        AtomicInteger res = new AtomicInteger();
        res.set(Integer.MIN_VALUE);

        int val = solve(root, res);

        return Math.max(val, res.get());
    }
}

// https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/1576110805/