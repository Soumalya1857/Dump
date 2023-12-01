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

        TreeNode* ans;
        if(root == NULL) return ans;
        
        stack<pair<TreeNode*, vector<TreeNode*>>> s;
        s.push({root, vector<TreeNode*>{root}});

        vector<TreeNode*> pPath, qPath;
        bool isPFound = false, isQFound = false;

        while(!s.empty()){

            pair<TreeNode*, vector<TreeNode*>> currPair = s.top();
            TreeNode* curr = s.top().first;
            int currVal = curr->val;
            s.pop();
            if(currVal == p->val) {
                pPath = currPair.second;
                isPFound = true;
                //cout << "PFound: " << p->val << endl;
            }
            if(currVal == q->val) {
                qPath = currPair.second;
                isQFound = true;
                //cout << "QFound: " << q->val << endl;
            }

            

            if(isPFound && isQFound) break;

            if(curr->left != NULL){
                vector<TreeNode*> temp (currPair.second);
                temp.push_back(curr->left);
                s.push({curr->left, temp});
            }

             if(curr->right != NULL){
                vector<TreeNode*> temp (currPair.second);
                temp.push_back(curr->right);
                s.push({curr->right, temp});
            }

        }


        int minSize = min(pPath.size(), qPath.size());
        
        for(int i=0; i<minSize; i++){
            if(pPath[i]->val == qPath[i]->val){
                ans = pPath[i];
            } else {
                break;
            }
        }

        return ans;
    }
};

// this is mle



// better approach is here
\
