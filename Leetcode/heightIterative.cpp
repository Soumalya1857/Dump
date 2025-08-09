

#include<bits/stdc++.h>
using namespace std;

int treeHeight(node* root)
{
    queue<node*> tree;
    tree.push(root);
    int height = 0;
    while(1)
    {
        int count = tree.size();
        if(count ==0) return height;
        else height++;
        while(count)
        {
            node* no = tree.front();
            tree.pop();
            if(no->left != NULL) tree.push(no->left);
            if(no->right != NULL) tree.push(no->right);

            count--;
        }
    }

}


int treeHeightRecur(node* root, int height)
{
    if(root == NULL) return height;

    return 1 + max(treeHeightRecur(root->left) , treeHeightRecur(root->right));
}

int main()
{
    return 0;
}