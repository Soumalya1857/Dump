class Solution {
    private:
        int calculate(string s, vector<string>&dict, int index, vector<int> &dp){
            if(index == s.length()){
                return 0;
            }

            if(dp[index] != -1){
                return dp[index];
            }

            int minCount = INT_MAX;

            // for each index recurr over each word to find an exact match
            // if not then 1 + other index
            for(int i =0; i<dict.size(); i++){
                string word = dict[i];

                // if my word matches
                int wordLen = word.length();

                if(wordLen <= (s.length()-index) && s.substr(index, wordLen) == word){
                    minCount = min(minCount, calculate(s, dict, index+wordLen, dp));
                }else{
                    minCount = min(minCount, 1+calculate(s, dict, index+1, dp)); // not take the character
                }
            }

            return dp[index] = minCount;
        }
public:
    int minExtraChar(string s, vector<string>& dictionary) {

        vector<int> dp(s.length(), -1);

        return calculate(s,dictionary, 0, dp);

    }
};

// https://www.youtube.com/watch?v=ONstwO1cD7c
// https://leetcode.com/problems/extra-characters-in-a-string/
// https://leetcode.com/problems/extra-characters-in-a-string/solutions/3990686/step-by-step-beginner-friendly-full-explanation-dp-efficient-easy-to-understand/


// this problem can be solved with tries also
// tricky and good question must see

// trie implementation



