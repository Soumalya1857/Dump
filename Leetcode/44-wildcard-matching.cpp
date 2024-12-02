class Solution {
public:
    bool solve(string s, string p, int sIdx, int pIdx, vector<vector<int>> &dp){

        if(sIdx < 0 && pIdx < 0){
            return true;
        }

        if( (sIdx >= 0 && pIdx < 0)) {
            return false;
        }

        if(sIdx < 0){ // all has to be "*"
            for(int i=0; i<=pIdx; i++){
                if(p[i] != '*') return false;
            }

            return true;
        }

        if(dp[sIdx][pIdx] != -1) return dp[sIdx][pIdx];

        if(p[pIdx] == s[sIdx] || p[pIdx] == '?'){
            return dp[sIdx][pIdx] = solve(s,p, sIdx-1, pIdx-1, dp);
        } else if(p[pIdx] == '*'){
            return dp[sIdx][pIdx]= solve(s,p, sIdx, pIdx-1, dp) || solve(s,p, sIdx-1, pIdx, dp);
        }else{
            return dp[sIdx][pIdx] = false;
        }
    }
    bool isMatch(string s, string p) {
    
        vector<vector<int>> dp(s.length(), vector<int>(p.length(), -1));
        return solve(s,p, s.length()-1, p.length()-1, dp);   
    }
};

// https://leetcode.com/problems/wildcard-matching/description/



// tabulization solution now
class Solution {
public:
    bool solve(string s, string p, int sIdx, int pIdx, vector<vector<int>> &dp){

        if(sIdx < 0 && pIdx < 0){
            return true;
        }

        if( (sIdx >= 0 && pIdx < 0)) {
            return false;
        }

        if(sIdx < 0){ // all has to be "*"
            for(int i=0; i<=pIdx; i++){
                if(p[i] != '*') return false;
            }

            return true;
        }

        if(dp[sIdx+1][pIdx+1] != -1) return dp[sIdx][pIdx];

        if(p[pIdx] == s[sIdx] || p[pIdx] == '?'){
            return dp[sIdx+1][pIdx+1] = solve(s,p, sIdx-1, pIdx-1, dp);
        } else if(p[pIdx] == '*'){
            return dp[sIdx+1][pIdx+1]= solve(s,p, sIdx, pIdx-1, dp) || solve(s,p, sIdx-1, pIdx, dp);
        }else{
            return dp[sIdx+1][pIdx+1] = false;
        }
    }
    bool isMatch(string s, string p) {
    
        vector<vector<bool>> dp(s.length()+1, vector<bool>(p.length()+1, -1));

        dp[0][0] = true; // i,j => i s, j p
        for(int i=1; i<=s.length(); i++){
            dp[i][0] = false;
        }

        for(int j=1; j<=p.length(); j++){
            for(int ii=1; ii<=j; ii++){
                if(p[ii-1] != '*'){
                    dp[0][j] = false;
                    break;
                }else{
                    dp[0][j] = true;
                }
            }
        }


        for(int i=1; i<=s.length(); i++){
            for(int j=1; j<=p.length(); j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                } else if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }else{
                    dp[i][j] = false;
                }
            }
        }

        return dp[s.length()][p.length()];

        //return solve(s,p, s.length()-1, p.length()-1, dp);   
    }
};

// https://leetcode.com/problems/wildcard-matching/description/