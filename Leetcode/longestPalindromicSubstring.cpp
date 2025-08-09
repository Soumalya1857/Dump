
/*Fastest solution c++*/

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         //convert all even palindrome to odd palindrome
//         string new_str = "#";
//         for(char c: s)
//         {
//             new_str += c;
//             new_str += '#';
//         }
//         int start = 0, end = -1;
//         int center = 0, right = 0;
//         vector<int> arm_len(new_str.size());
//         arm_len[0] = 1;
//         for(int i = 0; i < new_str.size(); ++i)
//         {
//             int curr_arm_len;
//             if(right >= i)
//             {
//                 int min_arm_len = min(arm_len[2*center - i], right - i);
//                 curr_arm_len = expand(new_str, i - min_arm_len, i + min_arm_len);
//             }
//             else
//             {
//                 curr_arm_len = expand(new_str, i, i);
//             }
//             arm_len[i] = curr_arm_len;
//             if(i + curr_arm_len > right)
//             {
//                 center = i;
//                 right = i + curr_arm_len;
//             }
//             if(2 * curr_arm_len + 1 > end - start + 1)
//             {
//                 start = i - curr_arm_len;
//                 end = i + curr_arm_len;
//             }
//         }
//         string ans = "";
//         for(int j = start; j <= end; ++j)
//         {
//             if(new_str[j] != '#')
//             {
//                 ans += new_str[j];
//             }
//         }
//         return ans;
//     }
// private:
//     //return arm_len
//     int expand(const string& s, int left, int right)
//     {
//         while(left >= 0 && right < s.size() && s[left] == s[right])
//         {
//             left--;
//             right++;
//         }
//         return (right - left - 2) / 2;
//     }
// };




/*My solution*/

class Solution {
public:
    string longestPalindrome(string s) {

string res = "$#";
        int i,j;
        for(char c : s)
        {
            res += c;
            res += '#';
        }
        res += '@';
        
        // define length array
        int len = res.length();
        //int arr[len] = {0};
        vector<int> arr(len, 0);
        
        int center = 0, rightBound = 0;
        
        
        for(int i=1;i<len-1;i++)
        {
            // get the mirror
            int mirror = 2*center - 1;
            
            
            // if inside the rightbound copy mirror value
            if(i < rightBound)
            {
                arr[i] = min(rightBound-i, arr[mirror]);
            }
            
            // try to expand with center at i
            while(res[i + (1+arr[i])] == res[i-(1+arr[i])]) arr[i]++;
            
            // after expanding shift original center and rightBound if necessary
            if(i + arr[i] > rightBound)
            {
                center = i;
                rightBound = 1+arr[i];
            }
        }
        
        // locate the center for max len
        // startPos = center - (len/2)
        // return s.substr(startpos, length)
        int maxi = -1, pos = -1;
        for(i=0;i<len;i++)
        {
            if(arr[i] > maxi)
            {
                maxi = arr[i];
                pos = i;
            }
        }        
        
        int startPos = (pos-1)/2 - (maxi/2);
        return s.substr(startPos, maxi);
    }
};



/*
https://leetcode.com/problems/longest-palindromic-substring/

*/

// dp solution
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n ==0 || n ==1 ) return s;
        int i,j;
        int start, len=0;
        
        // can be solved by manachars algo also
        // but will use dp solution
        
        //bool palin[n][n] = {false};
        vector<vector<bool>>palin(n, vector<bool>(n,false));
        for(i=0;i<n;i++) {palin[i][i] = true; start=i,len=1;}
        
        for(i=0;i<n-1;i++)
        {
            if(s[i] == s[i+1])
            {
                palin[i][i+1] = true;
                start = i, len = 2;
            }
        }
        
        for(int k=3;k<=n;k++)
        {
            for(i=0;i<n-k+1;i++)
            {
                j = i + k -1;
                if(s[i] == s[j] && palin[i+1][j-1])
                {
                    
                    palin[i][j] = true;
                    if(len < k)
                    {
                         start = i;
                         len = k;
                    }
                }
            }
        }
        
        // for(i=0;i<n;i++)
        // {
        //     for(j=i+1;j<n;j++)
        //     {
        //         int currLen = j-i+1;
        //         if(palin[i+1][j-1] && s[i] == s[j])
        //         {
        //             palin[i][j] = true;
        //             if(currLen > len)
        //             {
        //                 start = i;
        //                 len = currLen;
        //             }
        //         }
        //     }
        // }
        //cout << " " << start << " " << len << endl;
        return s.substr(start, len);
    }
};