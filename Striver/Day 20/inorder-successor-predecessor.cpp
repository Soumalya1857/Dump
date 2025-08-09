
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
// {
//     // Your code goes here
//     vector<Node*> ans;
//     solve(root, ans);
    
//     for(int i=0;i<ans.size();i++)
//     {
//         if(ans[i]->key == key)
//         {
//             if(i!=0) pre = ans[i-1];
//             if(i!=ans.size()-1) suc = ans[i+1];
//         }
//     }

//     if(prev == NULL) cout<< "-1";
//     else cout << prev->key;
    
//     cout << " ";
    
//     if(suc == NULL) cout << "-1";
//     else cout << suc->key;
// }

{ 
    if(!root) return;
    else if(key == root->key){
        
        if(root->right)
        {
            suc=root->right; 
            while(suc->left)suc=suc->left;
        }
        
        if(root->left)
        {
            pre=root->left; 
            while(pre->right)pre=pre->right;
        }
    }
    else if(key<root->key){
        suc=root; 
        findPreSuc(root->left,pre,suc,key);
    }
    else{
        pre=root; 
        findPreSuc(root->right,pre,suc,key);
    }
}

// soln: https://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/