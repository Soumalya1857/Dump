class Solution {
public:
    string reverseWords(string s) {
        
         // delete the extra spaces
        
        int size = s.length();
        string temp = "";
        for(int i=0;i<size-1;i++)
        {
            if(s[i] == s[i+1] && s[i] == ' ')
            {
                continue;
            }
            
            temp += s[i];
        }
        if(s[size-1] != ' ') temp += s[size-1];
        if(temp[0] == ' ') temp = temp.substr(1);
        
        int lastSpace = temp.length();
        string ans = "";
        for(int i=temp.length()-1;i>=0;i--)
        {
            if(temp[i] == ' ')
            {
                ans += temp.substr(i+1,lastSpace-i-1);
                ans += " ";
                lastSpace = i;
            }
            if(i==0)
            {
                ans += temp.substr(i,lastSpace-i);
            }
        }
        return ans;
    }
};

// prb: https://leetcode.com/problems/reverse-words-in-a-string/
// https://leetcode.com/problems/reverse-words-in-a-string/discuss/1414293/Follow-up-questions-on-interview
// https://leetcode.com/problems/reverse-words-in-a-string/discuss/1272574/C%2B%2B-8ms-O(N)-Code

