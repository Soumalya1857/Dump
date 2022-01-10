class Solution {
public:
    
//     static int dp[1002][200][2]; // n,copy,prevMove 0 paste 1 copy
    
//     int solve(int &n, int len, int ans, int copy, char prevMove){
        
//         if(n == len) return ans;
//         if(n < len) return INT_MAX;
        
        
//         if(prevMove == 'p')
//         // paste......copy
//         {
//             if(dp[len+copy][copy][0] != -1 && dp[len][len][1] != -1)
//                 return min(dp[len+copy][copy][0], dp[len][len][1]);
        
//             return min(solve(n, len+copy, ans+1, copy, 'p'), solve(n, len, ans+1, len, 'c'));
//         }
    
//         else //if(prevMove == 'c')
//         {
//             if(dp[len+copy][copy][0] != -1) return dp[len+copy][copy][0];
//             else  return solve(n, len+copy, ans+1, copy, 'p');
//         }
        
//     }
    
    int minSteps(int n) {
        int ans = 0, factor = 2;
        
        while(n>1){
            while(n % factor == 0){
                ans += factor;
                n /= factor;
            }
            
            factor++;
        }
        return ans;
    }
};

// problem: https://leetcode.com/problems/2-keys-keyboard/
