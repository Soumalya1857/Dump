#include<bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n,i,j,count=0;
        cin >> n;
        int a[n];
        int dp[n][n];
        for(i=0;i<n;i++) {cin >> a[i], dp[i][i] = a[i]; if(a[i]==0) count++;}
        dp[0][0] = a[0];
        for(i=1; i<n;i++)
        {
            dp[0][i] = dp[0][i-1] + a[i];
        }
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(j!=i)
                {
                    dp[i][j] = dp[i][j-1] + a[j];
                    if(dp[i][j] == 0)
                    {
                        //dp[i][j] = 0;
                        count++;
                    }
                    
                }
            }
        }
        cout << count << endl;
        

    }
    return 0;
}

/**
 * 
 * https://practice.geeksforgeeks.org/problems/zero-sum-subarrays   
 * 
*/


/***
 * 
 * 
 * #include <bits/stdc++.h>
using namespace std;
int sub(int a[],int n){
    int sum=0,count=0;
    unordered_map<int,int>ump;
    ump[0]++;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(ump.find(sum)!=ump.end()){
                count+=ump[sum];
            }
        ump[sum]++;
    }
    return count;
}
int main() {
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)cin>>a[i];
	    cout<<sub(a,n)<<"\n";
	}
	return 0;
}
 * 
 * **/