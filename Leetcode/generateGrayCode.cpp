/*
https://www.geeksforgeeks.org/generate-n-bit-gray-codes/
*/

// problem: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3799/

// my solution
#include <string>
class Solution {
public:
    vector<int> grayCode(int n) {
        
        vector<string> grayString;
        vector<int> ans;
        
        if(n <= 0) return ans;
        
        int i,j;
        grayString.push_back("0");
        grayString.push_back("1");
        
        for(i=2;i< (1<<n); i=i<<1)
        {
            for(j=i-1;j>=0;j--)
            {
                grayString.push_back(grayString[j]);
            }
            
            for(j=0;j<i;j++)
            {
                grayString[j] = "0" + grayString[j];
            }
            
            for(j=i;j<2*i;j++)
            {
                grayString[j] = "1" + grayString[j];
            }
        }
        
        for(string s : grayString)
        {
            ans.push_back(stoi(s,0,2));
        }
        
        return ans;
    }
};

// toka solution
class Solution {
    void utils(bitset<32>& bits, vector<int>& result, int k){
        if (k==0) {
            result.push_back(bits.to_ulong());
        }
        else {
            utils(bits, result, k-1);
            bits.flip(k-1);
            utils(bits, result, k-1);
        }
    }
public:
    vector<int> grayCode(int n) {
        bitset<32> bits;
        vector<int> result;
        utils(bits, result, n);
        return result;
    }
};