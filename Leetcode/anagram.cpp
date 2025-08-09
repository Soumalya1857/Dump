int abso(int n)
    {
        if(n<0) return -n;
        else return n;
    }
    int minSteps(string s, string t) {
       int freqs[26]= {0}, freqt[26] = {0};
        int count = 0;
       string :: iterator it;
        for(it = s.begin(); it != s.end();it++) freqs[*it-'a']++;
        for(it = t.begin(); it != t.end();it++) freqt[*it-'a']++;
        for(int i=0;i<26;i++)
        {
            count += abso(freqs[i] - freqt[i]);
        }
        return count/2;
    }
/***
https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

***/