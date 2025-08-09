class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int size = arr.size(),res=0;
        vector<int>prefix;
        for(auto x: arr)
        {
            res = res ^ x;
            prefix.push_back(res);
        }
        
        //for(auto x:prefix) cout << x << " ";
        
        vector<int>ans;
        for(auto q : queries)
        {
            if(q[0] == 0) ans.push_back(prefix[q[1]]);
            else ans.push_back(prefix[q[0]-1] ^ prefix[q[1]]);
        }
        
        return ans;
    }
};

// prob: https://leetcode.com/problems/xor-queries-of-a-subarray/submissions/