class Solution {
public:
    
    // k is the plus size
    // min size of k is 0
    // max size of k is n/2
    bool isExist(int n, vector<vector<int>>&grid, int k){
        bool flag = false;
        for(int i = k-1; i<=n-k; i++){
            for(int j = k-1; j<=n-k; j++){
                flag = true;
                for(int h = 0; h<k;h++){
                    if(grid[i-h][j] == 0){flag = false; break;}
                    if(grid[i][j-h] == 0){flag = false; break;}
                    if(grid[i+h][j] == 0){flag = false; break;}
                    if(grid[i][j+h] == 0){flag = false; break;}
                }
                
                if(flag) return true;
            }
        }
        
        return false;
        
    }
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n,1));
        for(int i=0;i<mines.size();i++)
        {
            int x = mines[i][0];
            int y = mines[i][1];
            
            grid[x][y] = 0;
        }
        bool res;
        int low = 0, high = n/2+(n%2);
        while(low <= high){
            int mid = (low+high)/2;
            res = isExist(n,grid,mid);
            if(res == true) low = mid+1;
            else high = mid-1;
            
            
            //cout << low << " " << high << endl;
        }
        //cout << res << endl;
        return low-1;
        
    }
};

// prb: https://leetcode.com/problems/largest-plus-sign/
// soln: think like aggresive cow


// link: https://leetcode.com/problems/largest-plus-sign/discuss/1633127/Nice-O(n2)-solution
int orderOfLargestPlusSign(int n, vector<vector>& mines) {

    vector< vector< int >>DP( n, vector< int >( n, 1));

    for( auto x:mines )
        DP[ x[0] ][ x[1] ] = 0;

    vector< vector< int >>left = DP, top = DP, right = DP, bottom =DP;

    for( int i=0 ; i<n ; i++ ){

        for( int j=0 ; j<n ; j++ ){

            if( DP[ i ][ j ] ){

                if( j>0 )
                    left[ i ][ j ] = 1 + left[ i ][ j-1 ];
                else
                    left[ i ][ j ] = 1;

                if( i>0 )
                    top[ i ][ j ] = 1 + top[ i-1 ][ j ];
                else
                    top[ i ][ j ] = 1;
            }
        }
    }

    int maxm = 0;

    for( int i=n-1 ; i>=0 ; i-- ){

        for( int j=n-1 ; j>=0 ; j-- ){

            if( DP[ i ][ j ] ){

                if( j<(n-1) )
                    right[ i ][ j ] = 1 + right[ i ][ j+1 ];
                else
                    right[ i ][ j ] = 1;

                if( i<(n-1) )
                    bottom[ i ][ j ] = 1 + bottom[ i+1 ][ j ];
                else
                    bottom[ i ][ j ] = 1;
            }

            int k = min({ left[i][j] , right[i][j] , top[i][j] , bottom[i][j] });

            maxm = max( k, maxm );
        }
    }

    return maxm;
}

