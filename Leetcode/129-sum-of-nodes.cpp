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
    bool isLeaf(TreeNode* curr){
        return curr->left == NULL && curr->right == NULL;
    }
    int sumNumbers(TreeNode* root) {
        // 
        stack<pair<TreeNode*, vector<int>>> s;
        vector<int> path;
        int ans = 0;
        s.push({root,path});

        while(!s.empty()){
            pair<TreeNode*, vector<int>> curr = s.top();
            s.pop();

            if(isLeaf(curr.first)){
                int num = 0;
                for(int digit : curr.second){
                    num = num * 10 + digit;
                }
                num = num*10 + curr.first->val;
                //cout << "num: " << num << endl;
                ans += num;
                continue;
            }

            if(curr.first -> left != NULL){
                vector<int>temp(curr.second);
                temp.push_back(curr.first->val);
                s.push({curr.first->left, temp});
            }

            if(curr.first -> right != NULL){
                vector<int>temp(curr.second);
                temp.push_back(curr.first->val);
                s.push({curr.first->right, temp});
            }

        }

        return ans;
    }
};

// https://leetcode.com/problems/sum-root-to-leaf-numbers/

// better solution
public int sumNumbers(TreeNode root) {
	return sum(root, 0);
}

public int sum(TreeNode n, int s){
	if (n == null) return 0; // return s will not work here as for a leaf node it will return 2S in total
	if (n.right == null && n.left == null) return s*10 + n.val;
	return sum(n.left, s*10 + n.val) + sum(n.right, s*10 + n.val);
}

//https://leetcode.com/problems/sum-root-to-leaf-numbers/solutions/41363/short-java-solution-recursion/