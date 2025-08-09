class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        if(s.length() == 1) return 1;
        
        // dp[i][j] longest substring without repeating chars
        // dp[i][i] = 1
        // check also the dual bostu dp[i][i+1] = 2 or 0
        // if
        
        
        int left=0,right=0,currLen=0,maxLen=INT_MIN;
        vector<bool>set(256,false);
        
        while(right<s.length())
        {
            char curr = s[right];
            if(set[int(curr)] == false){
                // add the char in set
                set[int(curr)] = true;
                
                // increase the right pointer
                right++;
                
                // increase curr len
                currLen++;
                maxLen = max(maxLen,currLen);
            }
            else
            {
                // we have duplicate in range l...r
                // delete the char from set pointed by left pointer
                set[int(s[left])] = false;
                // increase the left pointer
                left++;
                currLen--; // increasing left is decreasing the current length
            }
        }
        
        return maxLen;
        
    }
};

// prob: https://leetcode.com/problems/longest-substring-without-repeating-characters
// cannot do by myself -> check this https://www.youtube.com/watch?v=qtVh-XEpsJo&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=26