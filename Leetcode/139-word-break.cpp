// verdict: Passed
// DP based solution non Trie
// https://leetcode.com/problems/word-break/
// https://www.youtube.com/watch?v=oBUpyPZ08zU

class Solution {

private:
    bool solve(string s, vector<string> &dict, int index, vector<int> &dp){
        if(index == s.length()){
            return true;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        string temp = "";
        bool isPossible = false;

        for(int i=0; i<dict.size(); i++){
            string word = dict[i];
            int wordLen = word.length();

            if(word == s.substr(index, min(wordLen, (int)(s.length()-index))) && solve(s, dict, index+wordLen, dp)){
                // isPossible |= solve(s, dict, index+wordLen, dp);
                return dp[index] = true;
            }
        }

        // bool isPossible = false;
        // for(int i=index; i<s.length(); i++){
        //     temp += s[i];
        //     if(dict.find(temp) != dict.end()){
        //         dp[i+1] = solve(s, dict, i+1,dp); // try all the possible combinations, only return at the end
        //         isPossible |= dp[i+1];
        //     }
        // }

        return dp[index] = isPossible;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> dict;
        vector<int> dp(s.length(), -1);

        return solve(s,wordDict,0, dp);
    }
};

// =====================================================
/// better code

class Solution {
public:
    unordered_map<string, int> mp;
    unordered_map<int, int> dp;
    int m = -1;

    bool solve(string s, vector<string>& dict, int i){
        //base case
        if(i >= s.length()){
            return true;
        }
        if(dp.find(i) != dp.end())
            return dp[i];
        string str = "";
        for(int k = i; k < min(i + m, (int)s.size()); k++){
            str += s[k];
            if(mp.find(str) != mp.end()){
                if(solve(s, dict, k+1)){
                    dp[i] = true;
                    return true;
                }
            }
        }
        dp[i] = false;
        return false;
    }

    bool wordBreak(string s, vector<string>& dict) {

        int n = dict.size();
        for(auto it: dict){
            mp[it] = 1;
            m = max(m, (int)it.length());
        }

        bool ans = solve(s, dict, 0);

        return ans;
    }
};