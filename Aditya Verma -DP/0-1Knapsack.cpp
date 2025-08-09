// recursive

int knapsack(int weight[], int val[], int W, int n)
{
    if(n==0 || W == 0) return 0;;

    if(weight[n-1] <= W)
        return max(val[n-1] + knapsack(weight, val, W-weight[n-1], n-1), knapsack(weight, val, W, n-1));

    else if(weight > W)
        return knapsack(weight, val, W, n-1);
}


// memorization
// see which variables in input are getting changed
// they will contribute to the dp dimensions

dp[n+1][w+1] = {-1}; 
memset(dp,-1,sizeof(dp));
int knapsack(int weight[], int val[], int W, int n)
{
    if(n==0 || W==0) return 0;

    if(dp[n][W] != -1) return dp[n][W];

    if(weight[n-1] < = W) 
        return dp[n][W] = max(val[n-1] + knapsack(weight, val, W-weight[n-1], n-1), knapsack(weight, val, W, n-1));

    else if(weight > W)
        return dp[n][W] = knapsack(weight, val, W, n-1);

}


// top-down approach

int knapsack(int weight[], int val[], int W, int n)
{
    int dp[n+1][W+1];
    memset(dp, -1, sizeof(dp));

    for(int i=0; i<=W ;i++)  dp[0][i] = 0;
    for(int i=0;i<=n;i++) dp[i][0] = 0;


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
           if(weight[i-1] <= j) dp[i][j] = max(val[i-1]+dp[i-1][j-weight[i-1]], dp[i-1][j]);
           else if(weight[i-1] > j) dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][w];
}
