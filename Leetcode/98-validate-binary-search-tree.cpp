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
    bool inorder(TreeNode* root, vector<int> &traversal){
        if(root == NULL) return true;

        bool isBST = true;
        if(root->left != NULL){
            if(root->left->val < root->val){
                isBST = true;
            } else isBST = false;
        }

        if(root->right != NULL){
            if(root->right->val > root->val){
                isBST = true;
            } else isBST = false;
        }

        bool left = inorder(root->left, traversal);
        traversal.push_back(root->val);
        bool right = inorder(root->right, traversal);

        return isBST && left && right; // this is good enough for me
    }
    bool isValidBST(TreeNode* root) {
        // if(root == NULL)
        //     return true;

        // bool isBST = true;
        // if(root->left != NULL){
        //     if(root->left->val < root->val){
        //         isBST = true;
        //     } else isBST = false;
        // }

        // if(root->right != NULL){
        //     if(root->right->val > root->val){
        //         isBST = true;
        //     } else isBST = false;
        // }

        // return isBST && isValidBST(root->left) && isValidBST(root->right);



        // logic: inorder traversal is sorted
        vector<int> traversal1;
        bool check = inorder(root, traversal1);
        if(!check) return false;

        vector<int> traversal2(traversal1);
        sort(traversal2.begin(), traversal2.end());

        for(int i=0; i<traversal1.size(); i++){
            if(traversal1[i] != traversal2[i]){
                return false;
            }

            if(i!=0){
                if(traversal2[i] == traversal2[i-1]){
                    return false;
                }
            }
        }

        return true;
    }
};

// another good solution

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
    void inorder(TreeNode* root,vector<int> &v){
        if(root==NULL)
            return;

        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);

    }
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);

        for(int i=1;i<v.size();i++){
            if(v[i]<=v[i-1])
                return false;
        }
        return true;
    }
};

// https://leetcode.com/problems/validate-binary-search-tree/description/?source=submission-noac


// good solution where
// // boundary method
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
    // boundary method
    struct Node {
        TreeNode* node;
        long long leftBound;
        long long rightBound;

        Node(TreeNode* root) : node(root), leftBound((long long)INT_MIN-100), rightBound((long long)INT_MAX+100){}
        Node(TreeNode* root, long long left, long long right): node(root), leftBound(left), rightBound(right){}
    };

    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;

        stack<Node> s;
        Node node(root);
        s.push(node);

        while(!s.empty()){
            Node curr = s.top(); s.pop();

            if(curr.node->val > curr.leftBound && curr.node->val < curr.rightBound){

                if(curr.node->left != NULL){
                    Node temp(curr.node->left, curr.leftBound, curr.node->val);
                    s.push(temp);
                }

                if(curr.node->right != NULL){
                    Node temp(curr.node->right, curr.node->val, curr.rightBound);
                    s.push(temp);
                }

            } else{
                return false;
            }
        }

        return true;
    }
};

// solution: https://www.youtube.com/watch?v=s6ATEkipzow


// =========================================


bool isBST(TreeNode* root){
    if(root == NULL){
        return true;
    }


    bool isBST = true;

    if(root->left != NULL){
        isBST = root->left->val < root->val;
    }

    if(root->right != NULL){
        isBST = root->right-> val > root->val;
    }


    return isBST && isBST(root->left) && isBST(root->right);

}