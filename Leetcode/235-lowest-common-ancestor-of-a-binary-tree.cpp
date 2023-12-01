/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    vector<int> findPath(unordered_map<int,int> &parent, int node){
        vector<int>path;
        path.push_back(node);

        while(parent[node] != node){
            path.push_back(parent[node]);
            node = parent[node];
        }
        reverse(path.begin(), path.end());
        return path;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<int,int> parent; // val, parent
        parent[root->val] = root->val;

        stack<TreeNode*> s;
        s.push(root);
        bool isPfound = false, isQfound = false;

        while(!s.empty()){
            TreeNode* curr = s.top(); s.pop();
            if(curr->val == p->val) isPfound = true;
            if(curr->val == q->val) isQfound = true;

            if(isPfound && isQfound){
                break;
            }

            if(curr->left != NULL){
                parent[curr->left->val] = curr->val;
                s.push(curr->left);
            }


            if(curr->right != NULL){
                parent[curr->right->val] = curr->val;
                s.push(curr->right);
            }

        }

        // construct pPath
        vector<int> pPath = findPath(parent, p->val);

        // construct qPath
        vector<int> qPath = findPath(parent, q->val);

        int i=0;
        for(i=0; i<min(pPath.size(), qPath.size()); i++){
            if(pPath[i] != qPath[i]) break;
        }


        return i == 0 ? root : new TreeNode(pPath[i-1]);

    }
};

// read that it's a bst and not any general binary tree


// better solution
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/solutions/64963/3-lines-with-o-1-space-1-liners-alternatives/?source=submission-ac


// best solution for a reason
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // as long as both are in the same subtree you are good

        while(((long long)root->val - (long long)p->val) * ((long long)root->val - (long long)q->val) > 0l){
            root = p->val < root->val ? root->left : root->right;
        }

        return root;
    }
};


// test
