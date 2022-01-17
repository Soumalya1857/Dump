class Solution {
public:
    int numSplits(string s) {
        int ans = 0;
        unordered_map<char,int> sa, st;
        for(char ch : s)
            st[ch]++;
        
        
        for(char ch : s){
            sa[ch]++;
            st[ch]--;
            if(st[ch] == 0) st.erase(ch);
            
            if(sa.size() == st.size()){
                ans++;
            }
        }
        
        return ans;
    }
};

// https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
