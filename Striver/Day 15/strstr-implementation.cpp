class Solution {
public:
    int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    if(needle.length()>haystack.length()) return -1;
    else {
        for (int i = 0; i < haystack.length()-needle.length()+1; ++i) {
            if(haystack[i]==needle[0] && haystack[i+needle.length()-1]==needle[needle.length()-1]) {
                if(haystack.substr(i,needle.length())==needle) return i;
            }
        }
    }
    return -1;
}
    
    // prb: https://leetcode.com/problems/implement-strstr/submissions/
    // soln: https://leetcode.com/problems/implement-strstr/discuss/1413004/4ms-Time-Complexity.-Faster-than-92-percent.-Memory-7.2-MB
};