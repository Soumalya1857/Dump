
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
     
        
        int fresh = 0;
        int i,j;
        queue<pair<int,int>> q;
        int row = grid.size();
        int col = grid[0].size();
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2) q.push(make_pair(i,j));
            }
        }
        
        if(fresh == 0) return 0;
        int time = 0;
        
        int x[4] = {0,1,-1,0};
        int y[4] = {1,0,0,-1};
        
        int count = q.size();
        //time++;
        
        while(!q.empty() && fresh>0)
        {
//             pair<int,int> start = q.front();
//             q.pop();
            
            
//             if(count == 0)
//             {
//                 count = q.size();
//                 time++;
//             }
            
//             int xp = start.first;
//             int yp = start.second;
            
//             for(i=0;i<4;i++)
//             {
//                 if(xp+x[i] >= 0 && xp+x[i] < row)
//                 {
//                     if(yp+y[i] >= 0 && yp+y[i] < col)
//                     {
//                         if(grid[xp+x[i]][yp+y[i]] == 1)
//                         {
//                             grid[xp+x[i]][yp+y[i]] = 2;
//                             q.push(make_pair(xp+x[i], yp+y[i]));
//                             fresh --;
//                         }
//                     }
//                 }
//             }
            
//             count--;
            
            
//             if(fresh == 0)
//             {
//                 return time;
//             }
//             //cout << "count: " << count << endl;
            
            
            time++;
            int size = q.size();
            while(size--)
            {
                 pair<int,int> start = q.front();
                 q.pop();
                 int xp = start.first;
                 int yp = start.second;

                 for(i=0;i<4;i++)
                 {
                     if(xp+x[i] >= 0 && xp+x[i] < row)
                     {
                         if(yp+y[i] >= 0 && yp+y[i] < col)
                         {
                             if(grid[xp+x[i]][yp+y[i]] == 1)
                             {
                                 grid[xp+x[i]][yp+y[i]] = 2;
                                 q.push(make_pair(xp+x[i], yp+y[i]));
                                 fresh --;
                             }
                         }
                     }
                 }
            }
            
        }
         return (fresh==0)?time:-1;
    }
    
   
};


/*
https://leetcode.com/problems/rotting-oranges/
*/