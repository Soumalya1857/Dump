    
    // wrong implementation
    class Solution {
    public:


        bool isCorner(int row, int col, int m, int n){
            if(row == 0 && col == 0) return true;
            else if(row == m-1 && col == 0) return true;
             else if(row == m-1 && col == n-1) return true;
             else if(row == 0 && col == n-1) return true;

            return false;
        }

        bool isOnEdge(int row, int col, int m, int n){
            if(row == 0) return true;
            else if(row == m-1) return true;
            else if(col == 0) return true;
            else if(col == n-1) return true;

            return false;
        }

        bool isValid(int row, int col, int m, int n){
            if(row >= 0 && row < m){
                if(col >= 0 && col < n)
                    return true;
            }

            return false;
        }


        int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
            // number of ways to drive the football out

            long long int ans = 0;
            long long int mod = 1e9+7;


            int xpos[4] = {1,0,-1,0};
            int ypos[4] = {0,1,0,-1};

            int move = 0;
            queue<pair<int,int>> q;
            q.push({startRow, startColumn});
            while(!q.empty()){


                int size = q.size();
                move++;
                if(move == maxMove+1) break;
                while(size--){
                    pair<int,int> currPos = q.front();
                    q.pop();
                    if(isValid(currPos.first, currPos.second, m, n)){

                        if(isCorner(currPos.first, currPos.second, m, n)){
                            ans += 2;
                            ans %= mod;
                        }
                        else if(isOnEdge(currPos.first, currPos.second, m, n))
                        {
                            ans += 1;
                            ans %= mod;
                        }

                    }

                    for(int i=0;i<4;i++)
                    {
                        int x = currPos.first + xpos[i];
                        int y = currPos.second + ypos[i];

                        if(isValid(x,y,m,n)) q.push({x,y});
                    }
                }

            }
            return ans;
        }
    };




///////////////////////////////////////////////////////
// dp implementation

class Solution {
public:
    int mod = 1e9+7;
    int dp[51][51][51];
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    int solve(int m, int n, int moves, int r, int c){
        
        if(r<0 || r>=m || c<0 || c>=n) return 1;
        if(moves <= 0) return 0;
        
        if(dp[r][c][moves] != -1) return dp[r][c][moves];
        
        int sum = 0;
        
        for(int i=0;i<4;i++){
            int x = r + dx[i];
            int y = c + dy[i];
            
            sum  = (sum + solve(m,n,moves-1,x,y)) % mod;
        }
        dp[r][c][moves] = sum;
        return sum;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        // dp(i,j,moves) -> no of ways to leave from m,n with max moves moves
        memset(dp,-1,sizeof(dp));
        return solve(m,n,maxMove,startRow, startColumn );
    }
};

// question: https://leetcode.com/problems/out-of-boundary-paths/
// answer: https://leetcode.com/problems/out-of-boundary-paths/discuss/1369976/faster-than-97.64-of-C%2B%2B-online-submissions













