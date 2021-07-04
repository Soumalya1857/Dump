class Solution {
public:
    
    bool validate(pair<int,int> point, int row, int col)
    {
        int x = point.first;
        int y = point.second;
        
        if(x >=0 && x < row)
        {
            if(y >=0 && y < col)
                return true;
        }
        
        return false;
    }
    
    int bfs(vector<vector<int>>& grid, int xpos, int ypos)
    {   
        int row = grid.size();
        int col = grid[0].size();
        
        int xarr[4] = {0,0,1,-1};
        int yarr[4] = {1,-1,0,0};
        
        int area = 0;
        stack<pair<int,int>> st;
        st.push(make_pair(xpos, ypos));
        grid[xpos][ypos] = 0;
        
        while(!st.empty())
        {
            pair<int,int> curr = st.top();
            st.pop();
            
            //cout << curr.first << " " << curr.second << " " << endl;
            area++;
           
            
            for(int i=0;i<4;i++)
            {
                pair<int,int> point = make_pair(curr.first+xarr[i], curr.second+yarr[i]);
                if(validate(point, row, col) && grid[point.first][point.second] == 1)
                {
                    st.push(point);
                    grid[point.first][point.second] = 0;
                   // cout << point.first << " " << point.second << " " << endl;
                }
                
            }
            //cout << "a" << endl;
            
        }
        return area;
            
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        if(row == 0 || col == 0) return 0;
        int area = -1; 
        
        for(int i=0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(grid[i][j] == 1)
                {
                     int currArea = bfs(grid,i,j);
                     area = max(area, currArea);
                }
                    
            }
        }
        
        return (area==-1)?0:area;
        
    }
};

/*
question: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3764/
https://leetcode.com/problems/max-area-of-island/
*/