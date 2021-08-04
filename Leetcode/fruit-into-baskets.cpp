class Solution {
public:
    int totalFruit(vector<int>& tree) {
        // easy e ache 
        // sliding window technique
        
        int start=0,end=0,ans=0,size=tree.size();
        
        
        unordered_map<int,int> mp;
        while(end < size)
        {
            mp[tree[end]]++;
            end++;
            while(mp.size() > 2)
            {
                mp[tree[start]]--;
                if(mp[tree[start]] == 0) mp.erase(tree[start]);
                start++;
            }
            ans = max(ans,end-start);
            
        }
        
        return ans;
        
    }
    
    // question: https://leetcode.com/problems/fruit-into-baskets/
    //solution: https://leetcode.com/problems/fruit-into-baskets/discuss/1368520/Simple-C%2B%2B-Solution
};