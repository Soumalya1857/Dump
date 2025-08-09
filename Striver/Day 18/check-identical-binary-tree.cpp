   
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(r1 == NULL && r2 == NULL) return true;
        else if((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 ==NULL)) return false;
        
        return (r1->data == r2->data) && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
    }
};

// prb: https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
// soln: https://www.geeksforgeeks.org/write-c-code-to-determine-if-two-trees-are-identical/