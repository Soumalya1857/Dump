// the idea here is to slice the tree in vertical levels
// this is same as top view of a tree

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        if(!root) return ans;
        map<int,int>mp;
        queue<pair<Node*,int>>q; // node , vertical level
        q.push({root,0});
        
        while(!q.empty())
        {
            Node* curr = q.front().first;
            int level = q.front().second;
            q.pop();
            
            mp[level] = curr->data;
            
            if(curr->left) q.push({curr->left, level-1});
            if(curr->right) q.push({curr->right, level+1});
        }
        
 
        for(auto x:mp) ans.push_back(x.second);
        
        return ans;
        
    }
};
// prb: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
// soln: https://www.youtube.com/watch?v=GbA0E5gzxfw