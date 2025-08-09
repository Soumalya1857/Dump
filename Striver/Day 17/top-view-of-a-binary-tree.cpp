class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        // idea is to slice vertical level\
        
        if(!root) return vector<int>();
        
        queue<pair<Node*,int>> q;
        map<int,int> mp;
        q.push({root,0});
        
        while(!q.empty())
        {
            Node* curr = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(mp[level] == 0) mp[level] = curr->data; // we only update if we don't have an entry
                                                        // if we continuously try to update it we will get bottom view
            
            if(curr->left) q.push({curr->left, level-1});
            if(curr->right) q.push({curr->right, level+1});
        }
        
        vector<int>ans;
        for(auto x:mp) ans.push_back(x.second);
        
        return ans;
        
    }

};
// prb: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// soln: https://www.youtube.com/watch?v=EBTku_aIPXk&t=429s