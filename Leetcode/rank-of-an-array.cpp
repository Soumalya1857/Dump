class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int size = arr.size();
        vector<int> copy = arr;
        sort(copy.begin(), copy.end());
        int rank = 1;
        
        
        map<int,int> m;
        for(int num : copy)
        {
            if(m.find(num) == m.end())
            {
                m[num] = rank;
                rank++;
            }
        }
        
        copy.clear();
        for( int num : arr)
        {
            copy.push_back(m[num]);
        }
        
        return copy;
    }
};

// question: https://leetcode.com/problems/rank-transform-of-an-array/