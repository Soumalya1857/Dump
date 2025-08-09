// #include<bits/stdc++.h>
// using namespace std;


//     bool validate(int i, int j, int n)
//     {
//         if(i>=0 && i<n)
//         {
//             if(j>=0 && j<n)
//                 return true;
//         }
        
//         return false;
//     }
    
//     int bfs(vector<vector<int>>&grid, int i, int j)
//     {
//         // index = i,j
//         int n = grid.size();
//         int count = -1; // nearest land distance
//         //bool visited[4][4] = {false};
        
//         vector<vector<bool>> visited(n,vector<bool>(n,false));
//         queue<pair<int,int>>q;
//         int x[4] = {0,0,1,-1};
//         int y[4] = {1,-1,0,0};
        
//         q.push(make_pair(i,j));
        
//         while(!q.empty())
//         {
//             int size = q.size();
//             count++;
//             while(size--)
//             {
//                 auto top = q.front();
//                 q.pop();
//                 visited[top.first][top.second] = true;
//                 for(int k=0;k<4;k++)
//                 {
//                     int xpos = top.first + x[k];
//                     int ypos = top.second + y[k];
                    
//                     if(grid[xpos][ypos] == 0 && validate(xpos,ypos,n) && !visited[xpos][ypos])
//                     {
//                         q.push(make_pair(xpos,ypos));
//                     }
//                     else if(grid[xpos][ypos] == 1 && validate(xpos,ypos,n))
//                     {
//                         return count+1;
//                     }
//                 }
//             }
//         }
        
//         return count+1; // for all 0 case
//     }
//     int maxDistance(vector<vector<int>>& grid) {
        
        
//         // implement bfs
//         int n = grid.size();
//         if(n==0) return -1;
//         if(n==1) return 0;
//         int val = 0, maxi = -1;
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(grid[i][j] == 0)
//                 {
//                     val = bfs(grid,i,j);
//                 }
                
//                 maxi = max(maxi,val);
//             }
            
//         }
        
//         return maxi;
        
//     }


// int main()
// {

//     vector<vector<int>>grid = {
//         {1,0,0},
//         {0,0,0},
//         {0,0,0},
//         //{0,0,0,0}
//     };

//     cout << "ans: " << maxDistance(grid) << endl;
//     return 0;
// }

// /*
// https://leetcode.com/problems/as-far-from-land-as-possible/
// */





class Solution {
public:
    int maxDistance(vector<vector<int>>& g) {
        if(g.size()==0) return 0;
        int l=1,w=1, ans=0;
        vector<vector<int>> dp(g.size()+1,vector<int>(g[0].size()+1,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<g.size();++i)
        {
            for(int j=0;j<g[0].size();++j)
            {
                if(g[i][j])
                {
                    q.push({i,j});
                    l=0;
                    dp[i][j]=0;
                }
                else
                    w=0;
            }
        }
        
        if(l || w) return -1;

        while(!q.empty())
        {
            pair<int,int> t = q.front();q.pop();
            static int row[4] = {0,-1,0,1};
            static int col[4] = {-1,0,1,0};
            for(int k=0;k<4;++k)
            {
                int x = t.first +row[k];
                int y = t.second+col[k];
                if(x>=0 && x<g.size() && y>=0 && y<g[0].size() 
                   && dp[x][y]>dp[t.first][t.second]+1)
                {
                    dp[x][y] = dp[t.first][t.second] +1;
                    q.push({x,y});
                }
            }
        }

        for(int i=0;i<g.size();++i)
            for(int j=0;j<g[0].size();++j)
                ans=max(dp[i][j],ans);
        return ans;
    }
};

// accepted solution
// https://leetcode.com/problems/as-far-from-land-as-possible/discuss/779294/Simple-C%2B%2B-solution-using-BFS-with-comments





class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size(), water=0, land=0, dist_max = INT_MIN;
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX-1000));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    land++;
                    dp[i][j]=0;
                }
                else water++;
            }
        }
        if(water==0 || land==0) return -1;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==0) {
                    if(i>0) dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
                    if(j>0) dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
                }
            }
        }
        for(int i=n-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                if(grid[i][j]==0) {
                    if(i<n-1) dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
                    if(j<n-1) dp[i][j] = min(dp[i][j], dp[i][j+1]+1);
                    dist_max = max(dist_max,dp[i][j]);
                }
            }
        }
        return dist_max;
    }
};
Copyright © 2020 LeetCodeHelp Center  |  Jobs  |  Bug Bounty  |  Terms  |  Privacy Policy      United States


// solution from server...
