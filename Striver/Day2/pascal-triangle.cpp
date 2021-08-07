// given a row and a column the number at that point is <-- r-1 C c-1 -->

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        vector<int> row1{1};
        ans.push_back(row1);
        if(numRows == 1) return ans;
        vector<int> row2{1,1};
        ans.push_back(row2);
        
        
        for(int i=2;i<numRows;i++)
        {
            vector<int>prev(ans[i-1].begin(), ans[i-1].end());
            vector<int> curr;
            curr.push_back(1); // starts and ends with 1 
            
            // sliding window (though not very good but for implementation I am doing this)
            
            int windowSum = prev[0]+prev[1]; curr.push_back(windowSum);
            for(int j=2; j<prev.size();j++)
            {
                windowSum = windowSum + prev[j] - prev[j-2];
                curr.push_back(windowSum);
            }
            
            curr.push_back(1);
            
            // add to ans
            ans.push_back(curr);
        }
        
        return ans;
    }
};

// ques: https://leetcode.com/problems/pascals-triangle/
// youtube: https://www.youtube.com/watch?v=6FLvhQjZqvM&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=8