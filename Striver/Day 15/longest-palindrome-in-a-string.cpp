class Solution {
  public:

  // https://youtu.be/UflHuQj6MVA?si=p5gvep2DPdN01juH
    string longestPalin (string s) {
        // code here
        
        int size = s.length();
        //bool dp[size+1][size+1] = {false};
        vector<vector<bool>> dp(size+1, vector<bool>(size+1,false));
         int maxLen = INT_MIN, start=-1, end=-1;
        
        for(int i=0;i<size;i++) dp[i][i] = true;
        for(int i=0;i<size-1;i++)
        {
            if(s[i] == s[i+1]) {dp[i][i+1] = true; maxLen = 2; start=i;}
        }
        // this is not working because dp[2][7] is computed first and then dp[3][6]
        
        // for(int i=0;i<size;i++)
        // {
        //     for(int j=i+1;j<size;j++)
        //     {
        //         if(s[i] == s[j] && dp[i+1][j-1]) {dp[i][j] = true; cout << i << " " << j << " " << dp[3][6] << endl;}
        //       // else dp[i][j] = false;
                
        //         if(i==2 && j==7){cout<< dp[i][j] << " " << s[i] << " " << s[j] << " " << dp[3][] <<endl;} 
        //     }
        // }
        
       
        
        for(int dist=3; dist<=size;dist++)
        {
            for(int i=0;i<size-dist+1;i++)
            {
                int j = i+dist-1;
                if(s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    
                   //cout << i << " " << j << endl;
                    if(dist > maxLen){
                        maxLen = dist;
                        start = i;
                    }
                }
            }
            
        }
        
        
        return s.substr(start, maxLen);
    }
};
// https://youtu.be/wuOOOATz_IA?si=yQH3Liwd-gYKWljL


// there is a linear solution manachars algorithm
// https://youtu.be/V-sEwsca1ak?si=GtA6x0xBZTirD_oA


// brute force ....check every substring

// check every substring
// https://www.geeksforgeeks.org/longest-palindromic-substring/
class Solution{
    private:

        bool isPalindrome(string s, int left, int right){
            while(left<right){
                if(s[left++] != s[right--])
                    return false;
            }

            return true;
        }
    public:

        int longestPalindrome(string s){
            int maxLen = 1;
            int startIndex = -1;

            for(int i=0; i<s.length();i++){
                for(int j=i+1; j<s.length(); j++){
                    bool flag = isPalindrome(s, i, j);
                    if(flag && (j-i+1 > maxLen)){
                        maxLen = j-i+1;
                        startIndex = i;
                    }
                }
            }

            return maxLen == 1 ? {0,1} : {startIndex, maxLen};
        }
};


// recursive approach
// https://www.geeksforgeeks.org/length-of-longest-palindromic-sub-string-recursion/

