// If last characters of two strings are same, nothing much to do.
//  Ignore last characters and get count for remaining strings.
//  So we recur for lengths m-1 and n-1.
// Else (If last characters are not same), 
// we consider all operations on ‘str1’, consider all three operations on last character of first string, 
// recursively compute minimum cost for all three operations and take minimum of three values. 
// Insert: Recur for m and n-1
// Remove: Recur for m-1 and n
// Replace: Recur for m-1 and n-1

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int ans=0;
        int size1 = word1.length(), size2=word2.length();
        
        if(size1==0 || size2==0) return max(size1,size2);
        if(word1==word2) return 0;
        
        
        vector<vector<int>>dp(size1+1, vector<int>(size2+1,0));
        
        // dp[i][j] -> no of edits needed for i length of word1 and j length of word2
        
        // word2 is the final word
        // dp[0][i] = i -> all inserts
        
        for(int i=0;i<size2+1;i++) dp[0][i] = i; // all insert
        for(int i=0;i<size1+1;i++) dp[i][0] = i; // all delete
        
        for(int i=1;i<size1+1;i++)
        {
            for(int j=1;j<size2+1;j++)
            {
                // if last char same then no problem
                
                if(word1[i-1] == word2[j-1]) // here we are using 1indexing so -1 needed
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    // now try every possible opetation
                    dp[i][j] = 1 + min(
                                    dp[i-1][j], // delete
                                    min(dp[i-1][j-1], // replace
                                        dp[i][j-1] // insert
                                       )
                                    );
                }
            }
        }
        return dp[size1][size2];
    }
};
/*https://leetcode.com/problems/edit-distance*/
