// got a TLE about that
/*
https://leetcode.com/problems/01-matrix
*/

class Solution {
public:
    bool validate(int i, int j, int row, int col)
    {
        if(i>=0 && i<row)
            if(j>=0 && j<col)
                return true;
        return false;        
    }
    
    
    int bfs(vector<vector<int>>& matrix, int i, int j)
    {
        int x[4] = {0,0,1,-1};
        int y[4] = {1,-1,0,0};
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int count = -1;
        queue<pair<int,int>>q;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        q.push({i,j});
        
        while(!q.empty())
        {
            int size = q.size();
            count++;
            while(size--)
            {
                auto top = q.front();
                q.pop();
                
                i = top.first;
                j = top.second;
                visited[i][j] = true;
                
                for(int k=0;k<4;k++)
                {
                    int xpos = i+x[k];
                    int ypos = j+y[k];
                    
                    if(validate(xpos,ypos,row,col) && 
                            !visited[xpos][ypos] && 
                                matrix[xpos][ypos] == 0)
                    {
                        return count+1;
                    }
                    else if(validate(xpos,ypos,row,col) && !visited[xpos][ypos])
                    {
                        q.push({xpos,ypos});
                    }
                }
            }
        }
        
        return count+1;
        
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
     
        
        int row = matrix.size();
        if(row == 0) return {};
        int col = matrix[0].size();
        if(col == 0) return {};
        
        
        vector<vector<int>> ans(row, vector<int>(col,0));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j] != 0)
                {
                    int count = bfs(matrix,i,j);
                    ans[i][j] = count;
                }
            }
        }
        
        return ans;
    }
};


// lets see what the faster solution looks like

##############################################################################
// dp solution

vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
{
    int rows = matrix.size();
    if (rows == 0)
        return matrix;
    int cols = matrix[0].size();
    vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX - 100000));

    //First pass: check for left and top
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0)
                dist[i][j] = 0;
            else {
                if (i > 0)
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                if (j > 0)
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
            }
        }
    }

    //Second pass: check for bottom and right
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 0; j--) {
            if (i < rows - 1)
                dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
            if (j < cols - 1)
                dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
        }
    }

    return dist;
}

############################################################################################


vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
{
    int rows = matrix.size();
    if (rows == 0)
        return matrix;
    int cols = matrix[0].size();
    vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX));
    queue<pair<int, int> > q;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] == 0) {
                dist[i][j] = 0;
                q.push({ i, j }); //Put all 0s in the queue.
            }

    int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
            if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) {
                if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
                    dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
                    q.push({ new_r, new_c });
                }
            }
        }
    }
    return dist;
}

// better dfs solution
#################################################################################################