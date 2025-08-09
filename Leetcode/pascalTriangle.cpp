class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // need to calculate (rowIndex-1 s) ncr values
        // nCr = nCr-1  * (n-r+1)/r;
        // dp solution
        
        
        vector<int> res(rowIndex+1);
        
        res[0] = 1;
        //if(rowIndex == 1) return res;
        for(int i=1;i<res.size();i++)
        {
            res[i] = (int)((long long)res[i-1] * (rowIndex-i+1)/i);
        }
        
        return res;
        
    }
};

/*
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3421
*/