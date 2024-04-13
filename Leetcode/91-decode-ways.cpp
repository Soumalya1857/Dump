// TLE
class Solution {
private:
    bool isValid(string s){
        int val = stoi(s);
        return val >= 1 && val <= 26;
    }

    string getString(char a){
        string s(1,a);
        return s;
    }


    // Copy two characters of s1 (starting
    // from position 3)
    //string r = s1.substr(3, 2);

    int solve(string s, unordered_map<string,int> &dp){
        if(s.length() == 0) return 1;

        if(dp[s] != 0) return dp[s];

        int total = 0;

        // 1 character scenario
        if(isValid(getString(s[s.length()-1]))){
            string temp = s.substr(0, s.length()-1);

            if(dp[temp] == 0){
                dp[temp] = solve(temp, dp);
            }

            total += dp[temp];
        }

        // 2 character scenario
        if(s.length() >= 2){
            if(s[s.length()-2] != '0' && isValid(s.substr(s.length()-2, 2) )){
                string temp = s.substr(0, s.length()-2);

                if(dp[temp] == 0){
                    dp[temp] = solve(temp, dp);
                }

                total += dp[temp];
            }
        }

        return dp[s] = total;
    }

public:
    int numDecodings(string s) {
        unordered_map<string,int> dp;
        return solve(s, dp);
    }
};

// https://leetcode.com/problems/decode-ways/

// great state-minimized dp solution
//https://leetcode.com/problems/decode-ways/solutions/30384/a-concise-dp-solution

int numDecodings(string s) {
    if (!s.size() || s.front() == '0') return 0;
    // r2: decode ways of s[i-2] , r1: decode ways of s[i-1]
    int r1 = 1, r2 = 1;

    for (int i = 1; i < s.size(); i++) {
        // zero voids ways of the last because zero cannot be used separately
        if (s[i] == '0') r1 = 0;

        // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
        if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
            r1 = r2 + r1;
            r2 = r1 - r2;
        }

        // one-digit letter, no new way added
        else {
            r2 = r1;
        }
    }

    return r1;
}