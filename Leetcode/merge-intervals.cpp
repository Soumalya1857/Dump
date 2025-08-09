class Solution {
public:
   static bool compare(const vector<int> a,const vector<int> b)
    {
        // sorting increasingly based on the first value
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
     
        sort(intervals.begin(), intervals.end(), compare);
        
        sort(begin(intervals),end(intervals));
        vector<vector<int>> res;
        if(intervals.size() == 1)
        {
            return intervals;
        }
        for(int i=0;i<intervals.size()-1;i++)
        {
            if(intervals[i+1][0] > intervals[i][1])
            {
                res.push_back(intervals[i]);
            }
            else
            {
                intervals[i+1][0] = intervals[i][0];
                intervals[i+1][1] = max(intervals[i][1],intervals[i+1][1]);
            }
        }
        res.push_back(intervals[intervals.size()-1]);
        return res;
    }
};

// q: https://leetcode.com/problems/merge-intervals/
// sol: https://leetcode.com/problems/merge-intervals/discuss/1347602/C%2B%2B-oror-O(nlogn)-oror-faster-than-90
