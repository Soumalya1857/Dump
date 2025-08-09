class Solution {
public:
    void makeCombination(string res, vector<string>& ans,int open, int close, int n)
    {
        if(res.length() == 2*n) 
        {
            ans.push_back(res);
            return;
        }
        
        if(open < n) makeCombination(res+'(', ans, open+1, close, n);
        if(close < open) makeCombination(res+')', ans, open, close+1, n);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        makeCombination("", ans, 0,0,n);
        return ans;
        
    }
};

// question: https://leetcode.com/problems/generate-parenthese