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