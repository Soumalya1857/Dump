class Solution {
public:
    int mod = 1e9+7;
    int power2(int y, int mod){
        long long x = 2;

        long long res = 1;
        while(y>0){
            if(y%2 == 1){
                res = (res*x) % mod;
            }

            y/=2;

            x = (x*x) % mod;
        }

        return res % mod;
    }


    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int i=0, j=nums.size()-1;
        int ans = 0;

        while(i<=j){
            if(i==j){
                if(nums[i]*2 <= target){
                    ans = (ans+i+1)%mod;
                }else{
                    ans = (ans + i) % mod; // +j as all the numbers before i also satisfies i+j <= target
                }
                i++;
                continue;
            }

            if(nums[i] + nums[j] <= target){
                ans = (ans -1 + power2(j-i, mod))%mod; // if i,j is a valid limit the all the number from i,i+1  i,i+2, i,i+3.....all are valid limit
                                                        // so 2^i + 2^i+1, 2^i+2 ...... 2^j sums to 2^(j-1)
                i++;
            }else{
                j--;
            }
        }

        return ans % mod;
    }
};

// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/



// better clean solution
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int ans=0;
        int n=nums.size();
        int mod=1e9+7;
        sort(nums.begin(),nums.end());
        int l=0,r=n-1;

        //pre-computing the power
        vector<int> power(n);
        power[0]=1;
        for(int i=1;i<n;++i)
        {
            power[i]=(power[i-1]*2)%mod;
        }

        while(l<=r)
        {
            if(nums[l]+nums[r]<=target)
            {
                int diff=r-l;
                ans=ans%mod+(power[diff])%mod;
                l++;
            }
            else r--;
        }

        return ans;
    }
};