#include<bits/stdc++.h>
using namespace std;


int solve(int N, int K, vector<int> powers)
{
    sort(powers.begin(), powers.end());
    int minSum = INT_MAX;
    int minDiff = INT_MAX;
    

    for(int i=0;i<powers.size(); i++){

        bool flag = false;
        int now = powers[i];
        int target = abs(K - now);
        int diff1,diff2,sum1,sum2;
        int diff=INT_MAX, sum=INT_MAX;

        auto it = lower_bound(powers.begin()+i+1, powers.end(), target);

         diff1 = abs(*it-now); int sum1 = (*it+now);
        prev(it);
        if(it != powers.rend()){  diff2 = abs(*it-now);  sum2 = (*it+now); flag = true;}

        if(flag)
        {
            if(diff1 > diff2)
            {
                diff = diff2;
                sum = sum2;
            }
            else if(diff1<diff2)
            {
                diff = diff1;
                sum = sum1;
            }
            else
            {
                diff = diff1; // both same
                sum = min(sum1,sum2);
            }
        }
        else
        {
            diff = diff1;
            sum = sum1;
        }


        if(diff<minDiff)
        {
            minDiff = diff;
            minSum = sum;
        }
        else if(diff == minDiff)
        {
            minSum = min(sum,minSum);
        }
    }

    return minSum;
}

int main()
{

    return 0;
}