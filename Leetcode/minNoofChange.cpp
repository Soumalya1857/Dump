class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int count = 0;
        for(int i=1;i<A.size();i++)
        {
            if(A[i] > A[i-1]) continue;
            else
            {
                count += A[i-1]+1-A[i];
                A[i] = A[i-1]+1;
            }
        }
        return count;
    }
};

/***
https://leetcode.com/problems/minimum-increment-to-make-array-unique/
**/